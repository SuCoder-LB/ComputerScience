// ����arr��i������ʾ��i���������
// a��arr[0],b��arr[n-1],��������Ҫ��ĳ���ص�������С�����ߵľ����

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