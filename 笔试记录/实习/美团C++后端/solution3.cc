// 数组内随意选数，需要满足和为7的倍数，（或者可以不选），求最大的和

#include <bits/stdc++.h>

using namespace std;


int main(){
  int n;
  cin>>n;
  vector<int>nums(n);
  for(int i=0;i<n;++i){
    cin>>nums[i];
  }

//  int n=4;
//  vector<int> nums={1,3,6,6};

//  int n=5;
//  vector<int>nums={-2,-6,15,4,5};

  vector<int>max_value(7,0);
  vector<bool>check(7,false);
  max_value[0]=0;
  check[0]=true;

  for(int i=0;i<n;++i){
    vector<int>pre_value=max_value;
    for(int j=0;j<7;++j){
      if(!check[j])continue;
      int next=(pre_value[j]+nums[i]);
      int id=(next+7*(int)pow(10,7))%7;
      //int id=next%7;
      if(!check[id]){
        check[id]=true;
        max_value[id]=next;
      }else{
        max_value[id]= max(max_value[id],next);
      }
      //cout<<id<<" "<<max_value[id]<<endl;
    }
  }
  cout<<max(0,max_value[0])<<endl;
  return 0;
}