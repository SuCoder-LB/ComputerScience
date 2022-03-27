// 总工作量n，工作效率上限m，工作效率上限持续上限天数t
// 初始工作效率1，每过一天，效率+1
// 上限效率持续t天需要休息10天从1开始
// 可以选择摸鱼5天，从之前的工作效率折半开始

#include <bits/stdc++.h>

using namespace std;
int min_days;

int cpt(int start,int end){
  return (start+end)*(end-start+1)/2;
}

void dfs(int curt,int curxiaolv,int curn,int n,int m,int t){
  if(curn+cpt(curxiaolv,m)+m*(t-1)>=n){
    while(curn<n){
      if(curxiaolv==m){
        curt+=(n-curn)/m+((n-curn)%m>0);
        curn=n;
      }else{
        curt++;
        curn+=curxiaolv;
        curxiaolv+=1;
      }
    }
    min_days=min_days==-1?curt:min(min_days,curt);
    return;
  }
  dfs(curt+m-curxiaolv+1+t-1+10,1,curn+cpt(curxiaolv,m)+m*(t-1),n,m,t);
  dfs(curt+m-curxiaolv+1+t-2+5,m/2,curn+cpt(curxiaolv,m)+m*(t-2),n,m,t);
}

int main() {
  int n,m,t;
  cin>>n>>m>>t;
  dfs(0,1,0,n,m,t);
  cout<<min_days<<endl;
  return 0;
}
