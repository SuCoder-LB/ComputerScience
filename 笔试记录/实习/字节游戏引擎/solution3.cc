// 绳子初始长度x，天数n
// 每过一天，所有绳子长度+1
// 第0天开始，最长的偶数长度绳子折半

#include <bits/stdc++.h>

using namespace std;

int main(){
  int x,n;
  cin>>x>>n;
  map<int,int>cnts;
  cnts[x]++;

  for(int i=0;i<n;++i){
    bool find=false;
    int len;
    for(auto it=cnts.rbegin();it!=cnts.rend();++it){
      if((it->first+i)%2==0){
        find=true;
        len=it->first;
      }
    }
    if(find){
      cnts[len-i]--;
      if(cnts[len-i]==0)cnts.erase(len-i);
      cnts[len/2-i]+=2;
    }
  }
  cout<<cnts.rbegin()->first+n-1<<endl;

  return 0;
}

