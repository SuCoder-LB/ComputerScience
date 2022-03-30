// 给数组，重排，使最后连起来组成的字符串最小

#include <bits/stdc++.h>

using namespace  std;


class Solution {
 public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   *
   * @param numbers int整型vector
   * @return string字符串
   */
  //121 12,,,12112,12121
  string PrintMinNumber(vector<int>& numbers) {
    vector<string>stringnums;
    stringnums.reserve(numbers.size());
    for(auto x:numbers){
      stringnums.emplace_back(to_string(x));
    }
    sort(stringnums.begin(),stringnums.end(),[](auto s1,auto s2){
      string t1=s1+s2;
      string t2=s2+s1;
      return t1<t2;
    });

    string ret;
    for(const auto& x:stringnums){
      ret+=x;
    }
    return ret;
    // write code here
  }
};

