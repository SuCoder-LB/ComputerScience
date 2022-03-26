// 有n个课程，
// 给出这些课程的所需时间，及前置课程
// 可以一次性看任意多个课程
// 求每个课程的最快的完成时刻

#include <bits/stdc++.h>
using  namespace std;

int main(){
  int n;
  cin>>n;
  vector<int>time(n);
  vector<unordered_set<int>>from(n);
  vector<unordered_set<int>>to(n);
  priority_queue<pair<int,int>,vector<pair<int,int>>>q;
  for(int i=0;i<n;++i){
    int c;
    cin>>time[i]>>c;
    for(int j=0;j<c;++j){
      int t;
      cin>>t;
      from[i].insert(t-1);
      to[t-1].insert(i);
    }
  }
  for(int i=0;i<n;++i){
    if(from[i].empty()){
      q.push({-time[i],i});
    }
  }
  vector<int>finish_time(n,0);
  while(!q.empty()){
    auto x=q.top();
    q.pop();
    int id=x.second;
    int start_time=-x.first;
    finish_time[id]=start_time;
    for(auto idto:to[id]){
      from[idto].erase(id);
      if(from[idto].empty()){
        q.push({-start_time- time[idto],idto});
      }
    }
  }
  for(int i=0;i<n;++i){
    cout<<finish_time[i]<<" ";
  }
  return 0;
}
