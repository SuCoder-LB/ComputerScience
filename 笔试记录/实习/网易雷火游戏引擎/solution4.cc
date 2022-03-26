// 地图对应坐标高度给定，
// 水慢慢淹没，当淹没到给定的xy，wz时，且能从前者地点根据水到后者地点，认为当前水淹没的高度为可行解
// 求出最小的可行解

#include <bits/stdc++.h>

using namespace std;

class UnionFind{
 public:
  vector<int>fa_;
  UnionFind(int n){
    fa_.resize(n,-1);
  }
  int Find(int x){return fa_[x]<0?x:fa_[x]=(Find(fa_[x]));}
  bool Same(int x,int y){return Find(x)== Find(y);}
  bool Join(int x,int y){
    x= Find(x),y= Find(y);
    if(x==y)return false;
    if(fa_[x]>fa_[y])swap(x,y);
    fa_[x]+=fa_[y];
    fa_[y]=x;
    return true;
  }
};
using id2=array<int,2>;
int dir[4]={-1,-1,1,1};

int main(){
  int N,M;
  cin>>N>>M;
  int X,Y;
  cin>>X>>Y;
  int Z,W;
  cin>>Z>>W;
  --X,--Y,--Z,--W;
  vector<int>height((N+2)*(M+2),N*M);
  map<int,vector<int>>hash;
  UnionFind *uf=new UnionFind((N+2)*(M+2));
  int start=(X+1)*(M+2)+Y+1;
  int end=(Z+1)*(M+2)+W+1;
  for(int i=1;i<=N;++i){
    for(int j=1;j<=M;++j){
      cin>>height[i*(M+2)+j];
      hash[height[i*(M+2)+j]].push_back(i*(M+2)+j);
    }
  }
  dir[0]=-M-2;
  dir[3]=M+2;
  auto t=hash.begin();
  while(!uf->Same(start,end)){
    for(auto x:t->second){
      for(int d=0;d<4;++d){
        if(height[x+dir[d]]<=height[x]){
          uf->Join(x,x+dir[d]);
        }
      }
    }
    ++t;
  }
  std::cout<<(--t)->first<<std::endl;
  return 0;
}


