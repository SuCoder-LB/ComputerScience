// 给n，m，一段string
// 重写分配字符串，每行长度不超过N
// 若前一行加上这个单词未超过n+m，允许这一行加这一次
// 出现标点，无论如何，不放行首

#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin>>N>>M;
  getchar();

  string context;
  getline(cin,context);

//  int N=20,M=3;
//  string context="I am coordinator of the Latin video games Federation. I'm born, member of the UWOOyan game Developers Association.";

  int n=context.size();
  vector<string>context_tran;

  string token;
  bool fixlast=false;

  int last=-1;//-1 start,0,空格,2,单词
  for(int i=0;i<n;++i){
    if(last==-1&&context[i]==' ')continue;
    if(last==-1){
      token+=context[i];
      last=2;
      continue;
    }
    if(last==2){
      if(context[i]==' '||context[i]==','||context[i]=='.'){
        if(token.empty()){
          if(context[i]==','||context[i]=='.'){
            context_tran.back()+=context[i];
          }
          continue;
        }
        if(context_tran.empty()){
          context_tran.push_back(token);
          token="";
        }else if(fixlast){
          context_tran.push_back(token);
          token="";
          fixlast=false;
        }else if(context_tran.back().size()+token.size()+1<=N){
          context_tran.back()+=' ';
          context_tran.back()+=token;
          token="";
        }else if(context_tran.back().size()==N-1||context_tran.back().size()==N){
          context_tran.push_back(token);
          token="";
        }else if(context_tran.back().size()+token.size()+1<=N+M){
          context_tran.back()+=' ';
          context_tran.back()+=token;
          token="";
          fixlast=true;
        }else{
          context_tran.push_back(token);
          token="";
        }
        if(context[i]==' ') last=0;
        else context_tran.back()+=context[i];
      }else{
        token+=context[i];
      }
      continue;
    }
    if(last==0){
      token="";
      token+=context[i];
      last=2;
    }
  }
  cout<<context_tran.size()<<endl;
  for(auto s:context_tran){
    cout<<s<<endl;
  }
  return 0;
}