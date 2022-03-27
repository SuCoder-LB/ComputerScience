// 书里放广告
// 数的页数n，后面紧跟着的样例个数m，广告间隔上限t
// 放广告的多种case,判断是否合适

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,m,t;
  cin>>n>>m>>t;

  for(int i=0;i<m;++i){
    bool check=true;
    int pre=-1;
    for(int j=0;j<n;++j){
      int c;
      cin>>c;
      if(c){
        if(pre!=-1&&j-pre-1<t){
          check=false;
        }
        pre=j;
      }
    }
    if(check)cout<<1<<" ";
    else cout<<0<<" ";
  }
  return 0;
}
