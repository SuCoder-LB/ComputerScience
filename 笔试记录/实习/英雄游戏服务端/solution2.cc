//���������������������

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  /**
   * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
   *
   *
   * @param pre int����vector
   * @param vin int����vector
   * @return TreeNode��
   */
  TreeNode *ReConstructBinaryTree(vector<int> &pre, vector<int> &vin) {
    return build(pre,vin,0,pre.size()-1,0,vin.size()-1);

    // write code here
  }

  TreeNode* build(vector<int>&pre,vector<int>&vin,int l1,int r1,int l2,int r2){
    if(r1<l1)return nullptr;
    if(r1==l1)return new TreeNode(pre[l1]);
    int j;
    for(j=l2;j<=r2;++j){
      if(vin[j]==pre[l1]){
        break;
      }
    }
    int len=j-l2;

    TreeNode*head=new TreeNode(pre[l1]);
    head->left=build(pre,vin,l1+1,l1+len,l2,j-1);
    head->right=build(pre,vin,l1+len+1,r1,j+1,r2);
    return head;
  }

};