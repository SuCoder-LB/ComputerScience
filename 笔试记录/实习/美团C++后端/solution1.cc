//�����ַ������������ź��ܳ��֡�acbcca���ĸ���

#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin>>s;
  unordered_map<char,int>hash;
  for(auto c:s){
    hash[c]++;
  }
  int val=min(hash['c']/3,min(hash['a']-1,hash['b']))+1;

  cout<<val<<endl;
  return 0;
}
