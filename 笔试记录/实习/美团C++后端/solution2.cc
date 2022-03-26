// 数组arr第i个数表示第i个点的坐标
// a在arr[0],b在arr[n-1],求两人想要在某个地点会面的最小的行走的距离差

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;++i){
    cin>>arr[i];
  }
  int mindistance=std::numeric_limits<int>::max();
  for(int i=0;i<n;++i){
    int diff=abs((arr[i]-arr[0])-(arr[n-1]-arr[i]));
    mindistance=min(mindistance,diff);
  }
  cout<<mindistance<<endl;
  return 0;
}