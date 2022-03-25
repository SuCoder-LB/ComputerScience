// 3*3数独，横竖，指定区域块3个为三个不同数（1，2，3）,
// 单解输出解
// 多解输出multi，无解输出no

#include <bits/stdc++.h>


using id2 = array<int,2>;
class Solution1 {
 public:
  bool check3(int a, int b, int c) {
    vector<int> num = {a, b, c};
    sort(num.begin(), num.end());
    return num[0] == 1 && num[1] == 2 && num[2] == 3;
  }
  void getret(vector<string> &arr,
              vector<vector<id2>> &patch,
              int &state,
              vector<string> &ret) {
    int cnt = 0;
    for (int i = 0; i < pow(3, 9); ++i) {
      vector<int> nums(9, 0);
      int k = i;
      for (int j = 0; j < 9; ++j) {
        nums[j] = k % 3 + 1;
        k /= 3;
      }
      bool check = true;
      for (int j = 0; j < 3; ++j) {
        check &= check3(nums[j * 3], nums[j * 3 + 1], nums[j * 3 + 2]);
        check &= check3(nums[j], nums[j + 3], nums[j + 6]);
      }
      for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < 3; ++k) {
          if (isdigit(arr[j][k])) {
            check &= nums[j * 3 + k] == (arr[j][k] - '0');
          }
        }
      }
      for (int j = 0; j < 3; ++j) {
        check &= check3(nums[patch[j][0][0] * 3 + patch[j][0][1]],
                        nums[patch[j][1][0] * 3 + patch[j][1][1]],
                        nums[patch[j][2][0] * 3 + patch[j][2][1]]);
      }
      if (check) {
        ++cnt;
        if (cnt == 1) {
          ret.clear();
          ret.resize(3);
          for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
              ret[j] += '0' + nums[j * 3 + k];
            }
          }
        }
      }
    }
    state = cnt;
  }
};