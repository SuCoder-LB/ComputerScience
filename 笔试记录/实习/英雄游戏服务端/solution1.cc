// 链表每k个旋转一次，最后若不足k个，不旋转

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   *
   * @param head ListNode类
   * @param k int整型
   * @return ListNode类
   */
  ListNode *reverseKGroup(ListNode *head, int k) {

    vector<ListNode *> arr;
    while (head) {
      arr.emplace_back(head);
      head = head->next;
    }

    int n = arr.size();
    for (int i = 0; i < n / k; ++i) {
      reverse(arr.begin() + (k * i), arr.begin() + (k * i + k));
    }

    for (int i = 0; i < n; ++i) {
      if (i != 0)arr[i - 1]->next = arr[i];
      arr[i]->next = nullptr;
    }
    return arr[0];
    // write code here
  }
};
