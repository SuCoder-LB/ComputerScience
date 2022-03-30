// ����ÿk����תһ�Σ����������k��������ת

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
   * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
   *
   *
   * @param head ListNode��
   * @param k int����
   * @return ListNode��
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
