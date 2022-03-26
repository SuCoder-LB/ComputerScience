// 求一个数组的所有奇数个子数组的中位数的和

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int>nums;
  for(int i=0;i<n;++i){
    cin>>nums[i];
  }
//  int n=4;
//  vector<int>nums={2,3,1,4};
  int ret=0;
  for(int start=0;start<n;++start){
    priority_queue<int,vector<int>,less<int>>pre;
    priority_queue<int,vector<int>,greater<int>>next;

    for(int end=start;end<n;++end){
      if(pre.size()==next.size()){
        if(pre.empty()){
          pre.push(nums[end]);
        }else if(next.top()>=nums[end]){
          pre.push(nums[end]);
        }else{
          int val=next.top();
          pre.push(val);
          next.pop();
          next.push(nums[end]);
        }
      } else{
        if(pre.top()<=nums[end]){
          next.push(nums[end]);
        }else{
          int val=pre.top();
          next.push(val);
          pre.pop();
          pre.push(nums[end]);
        }
      }
      if(pre.size()!=next.size()){
        ret+=pre.top();
      }
    }
  }
  cout<<ret<<endl;
  return 0;
}