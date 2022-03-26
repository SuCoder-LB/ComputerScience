//重排字符串，计算重排后能出现”acbcca“的个数

#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin>>s;
  unordered_map<char,int>hash;
  for(auto c:s){
    hash[c]++;
  }
  int val=min(hash['c']/3,min(hash['a']-1,hash['b']));

  cout<<val<<endl;
  return 0;
}
