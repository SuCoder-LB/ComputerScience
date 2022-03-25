//
// Created by su on 2022/3/24.
//

#include <bits/stdc++.h>

class ThreadPool {
 public:
  ThreadPool(size_t);

  template<class F, class...Args>
  std::future<typename std::result_of<F(Args...)>::type> commit(F &&f,
                                                                Args &&...args);
  ~ThreadPool();
 private:
  std::vector<std::thread> workers_;
  std::queue<std::function<void()>> tasks_;
  std::mutex queue_mutex_;
  std::condition_variable condition_;
  bool stop_;

};

ThreadPool::ThreadPool(size_t threads) : stop_(false) {
  if (threads < 1)throw std::runtime_error("threads numbers less than 1");
  for (int i = 0; i < threads; ++i) {
    workers_.emplace_back([this] {
      while (1) {
        std::function<void()> task;
        {
          std::unique_lock<std::mutex> lock(this->queue_mutex_);
          condition_.wait(lock, [this] {
            return stop_ || !this->tasks_.empty();
          });
          if (stop_ && tasks_.empty())return;
          task = std::move(tasks_.front());
          tasks_.pop();
        }
        task();
      }
    })
  }
}

template<class F, class...Args>
std::future<typename std::result_of<F(Args...)>::type> ThreadPool::commit(F &&f,
                                                                          Args &&...args) {
  using returnType = typename std::result_of<F(Args...)>::type;
  auto task = std::make_shared < std::packaged_task < returnType() >> (
      std::bind(std::forward<F>(f), std::forward<Args>(args)...)
  );
  std::future<returnType> ret = task->get_future();
  {
    if (stop_) {
      throw std::runtime_error("commit on stopped thread pool");
    }
    tasks_.template emplace([task]() { (*task)(); });
  }
  condition_.notify_one();
  return ret;
}

ThreadPool::~ThreadPool() {
  {
    std::unique_lock<std::mutex> lock(queue_mutex_);
    stop_ = true;
  }
  condition_.notify_all();
  for (auto &worker : workers_)worker.join();
}