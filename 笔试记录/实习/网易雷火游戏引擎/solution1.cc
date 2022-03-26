//ÌâÄ¿ÍüÁË

#include <bits/stdc++.h>

using namespace std;

int main(){
  int m,n;
  cin>>m>>n;
  int x,y;
  cin>>x>>y;
  int ret=0;
  vector<vector<int>>arr(m,vector<int>(n));
  for(int i=0;i<m;++i){
    for(int j=0;j<n;++j){
      cin>>arr[i][j];
      ret+=(i==x-1&&j==y-1)?1:arr[i][j];
    }
  }
  cout<<ret<<endl;
  return 0;
}
