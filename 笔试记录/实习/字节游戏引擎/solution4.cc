// n个人
// 每个人信任的人的编号（1-n）
// 每个人可以传消息给信任的人，判断最短能让所有人知道消息的天数

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin>>n;
  vector<vector<int>>to(n);
  for(int i=0;i<n;++i){
    int m;
    cin>>m;
    for(int j=0;j<m;++j){
      int c;
      cin>>c;
      --c;
      to[i].emplace_back(c);
    }
  }
  int min_day=-1;
  for(int i=0;i<n;++i){
    queue<int>q;
    vector<bool>vis(n,false);
    vis[i]=true;
    q.push(i);
    int steps=0;
    int people=1;
    while(!q.empty()){
      int s=q.size();
      for(int j=0;j<s;++j){
        int x=q.front();
        q.pop();
        for(auto next:to[x]){
          if(vis[next])continue;
          vis[next]=true;
          q.push(next);
          people++;
        }
      }
      steps++;
    }

    if(people==n)min_day=min_day==-1?steps:min(min_day,steps);
  }
  cout<<min_day-1<<endl;
  return 0;
}