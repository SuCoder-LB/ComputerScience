// 黑白棋，下一子，横竖斜8个方向找最远的对方子，中间的子翻面，
// 一个子不能连续翻两次面，
// 给出盘面和后续出棋坐标（白字先出），
// 求最终盘面

#include <bits/stdc++.h>

using id2 = array<int,2>;
vector<vector<int>> dir =
    {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
class Solution2 {
 public:
  vector<vector<bool>> vis;
  vector<vector<bool>>vis2;
  vector<vector<int>> arr;
  int m, n;
  bool outofrange(id2 pos) {
    return pos[0] < 0 || pos[0] >= n || pos[1] < 0 || pos[1] >= n;
  }
  void getnext(id2 curpos, int player, vector<id2> &nextpos) {
    nextpos.resize(8, {-1, -1});
    for (int i = 0; i < 8; ++i) {
      id2 next = curpos;
      while (true) {
        next = {next[0] + dir[i][0], next[1] + dir[i][1]};
        if (outofrange(next))break;
        if (arr[next[0]][next[1]] == -1)break;
        if (arr[next[0]][next[1]] != player) {
          nextpos[i] = next;
        }
      }
    }
  }

  void change(id2 pos, vector<id2> &nextpos) {
    for (int i = 0; i < 8; ++i) {
      if (nextpos[i] == id2{-1, -1})continue;
      id2 curpos = {pos[0] + dir[i][0], pos[1] + dir[i][1]};
      while (curpos != nextpos[i]) {
        if (!vis[curpos[0]][curpos[1]]&&arr[curpos[0]][curpos[1]] != -1){
          arr[curpos[0]][curpos[1]] = 1-arr[curpos[0]][curpos[1]];
          vis2[curpos[0]][curpos[1]]=true;
        }
        curpos = {curpos[0] + dir[i][0], curpos[1] + dir[i][1]};
      }
    }
    vis=vis2;
    vis2.clear();
    vis2.resize(n, vector<bool>(n, false));
  }
  void getret(vector<string> &_arr, vector<id2> &steps, vector<string> &ret) {
    n = _arr.size();
    m = steps.size();

    vis.resize(n, vector<bool>(n, false));
    vis2.resize(n, vector<bool>(n, false));
    arr.resize(n, vector<int>(n, -1));

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (_arr[i][j] == 'w')arr[i][j] = 0;
        if (_arr[i][j] == 'b')arr[i][j] = 1;
      }
    }

    for (int i = 0; i < m; ++i) {
      arr[steps[i][0]][steps[i][1]] = i % 2;
      vector<id2> nextpos;
      getnext(steps[i], i % 2, nextpos);
      change(steps[i], nextpos);
    }

    ret.clear();
    ret.resize(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (arr[i][j] == -1) {
          ret[i] += '-';
        }
        if (arr[i][j] == 0) {
          ret[i] += 'w';
        }
        if (arr[i][j] == 1) {
          ret[i] += 'b';
        }
      }
    }
  }
};
