// �����飬���ţ�ʹ�����������ɵ��ַ�����С

#include <bits/stdc++.h>

using namespace  std;


class Solution {
 public:
  /**
   * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
   *
   *
   * @param numbers int����vector
   * @return string�ַ���
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

