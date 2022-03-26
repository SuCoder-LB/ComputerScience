// 5张以内的牌，根据规则，求最大分
// 5张成豹子，15000
// 5张同花顺，8000
// 5张同花，300
// 存在四张豹子，150
// 3张豹子加对子，40
// 5张顺子，20
// 存在3张豹子，6
// 两个对子，4
// 一个对子，2
// 一般，1

#include <bits/stdc++.h>

using namespace std;

//15000
bool check1(vector<int>&num,vector<int>&type){
  if(num.size()<5)return false;
  bool check=true;
  int t=num[0];
  for(int i=1;i<5;++i){
    check&=num[i]==t;
  }
  return check;
}
//8000
bool check2(vector<int>&num,vector<int>&type){
  if(num.size()<5)return false;
  int t=type[0];
  bool check=true;
  for(int i=1;i<5;++i){
    check&=type[i]==t;
  }
  sort(num.begin(),num.end());
  int s= num[0];
  for(int i=1;i<5;++i){
    check&=num[i]==s+i;
  }
  return check;
}
//300
bool check3(vector<int>&num,vector<int>&type){
  if(num.size()<5)return false;
  int t=type[0];
  bool check=true;
  for(int i=1;i<5;++i){
    check&=type[i]==t;
  }
  return check;
}
//150
bool check4(vector<int>&num,vector<int>&type){
  if(num.size()<4)return false;
  sort(num.begin(),num.end());

  if(num.size()==4){
    return num[1]==num[0]&&num[2]==num[0]&&num[3]==num[0];
  }

  int t=num[0];
  bool check=true;
  for(int i=1;i<4;++i){
    check&=num[i]==t;
  }
  if(check)return true;
  check=true;
  t=num[1];
  for(int i=2;i<5;++i){
    check&=num[i]==t;
  }
  return check;
}
//40
bool check5(vector<int>&num,vector<int>&type){
  if(num.size()<5)return false;
  sort(num.begin(),num.end());
  int t1=num[0],t2=num[2];
  bool check=(num[1]==t1)&&(num[3]==t2&&num[4]==t2);
  if(check)return true;
  t1=num[0],t2=num[3];
  return (num[1]==t1&&num[2]==t1)&&(num[4]==t2);

}
//20
bool check6(vector<int>&num,vector<int>&type){
  if(num.size()<5)return false;
  int t=type[0];
  bool check=true;
  sort(num.begin(),num.end());
  int s= num[0];
  for(int i=1;i<5;++i){
    check&=num[i]==s+i;
  }
  return check;
}
//6
bool check7(vector<int>&num,vector<int>&type){
  unordered_map<int,int>hash;
  for(auto x:num)hash[x]++;
  for(auto x:hash){
    if(x.second==3)return true;
  }
  return false;
}
bool check8(vector<int>&num,vector<int>&type){
  unordered_map<int,int>hash;
  for(auto x:num)hash[x]++;
  int cnt=0;
  for(auto x:hash){
    if(x.second==2)++cnt;
  }
  return cnt==2;
}
bool check9(vector<int>&num,vector<int>&type){
  unordered_map<int,int>hash;
  for(auto x:num)hash[x]++;
  for(auto x:hash){
    if(x.second==2)return true;
  }
  return false;
}

int main(){
  int M;
  cin>>M;
  for(int i=0;i<M;++i){
    int N;
    cin>>N;
    vector<int>num(N);
    vector<int>type(N);
    for(int j=0;j<N;++j){
      cin>>num[j];
    }
    for(int j=0;j<N;++j){
      char c;
      cin>>c;
      type[j]=c-'A';
    }
    if(check1(num,type)){
      cout<<15000<<endl;
    }else if(check2(num,type)){
      cout<<8000<<endl;
    }else if(check3(num,type)){
      cout<<300<<endl;
    }else if(check4(num,type)){
      cout<<150<<endl;
    }else if(check5(num,type)){
      cout<<40<<endl;
    }else if(check6(num,type)){
      cout<<20<<endl;
    }else if(check7(num,type)){
      cout<<6<<endl;
    }else if(check8(num,type)){
      cout<<4<<endl;
    }else if(check9(num,type)){
      cout<<2<<endl;
    }else{
      cout<<1<<endl;
    }
  }
  return 0;
}