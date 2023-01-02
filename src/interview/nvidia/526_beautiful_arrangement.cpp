#include <iostream>
#include <vector>

using namespace std;
/***************************************************
https://leetcode.com/problems/beautiful-arrangement/
***************************************************/

// 1. 状态压缩 + 动态规划
// （1）思路
// 因为 N 是一个不超过 15 的正整数，可用二进制方法进行状态压缩，设计一个数组
// dp，对于 dp[i]，若 i 的第 j 个二进制位为 1，说明整数 j 已被选取，dp[i]
// 则表示该状态下优美的排列数量。

// 结合动态规划方法，依次遍历 [1, 2^n - 1] 范围内的所有排列情况，对每种情况，若
// i 中有 cnt 个比特位为 1，说明当前添加的是第 cnt 个整数。若 i 中选取了整数 j
// (说明 j 可以为第 cnt 个整数)，且 j 能被 cnt 整除或 cnt 能被 j
// 整除，则累加统计符合要求的排列数。

// 最终，dp[2^n - 1] 就是全部整数被选取时的优美排列数，即所求解的答案。

// top-down DP/recursion with memorization
// Runtime: 16 ms, faster than 88.26% of C++ online submissions for Beautiful
// Arrangement. Memory Usage: 11.6 MB, less than 19.82% of C++ online
// submissions for Beautiful Arrangement.
class Solution {
public:
  int N;
  vector<vector<int>> dp;

  int backtrack(int cur, bitset<15> &used) {
    int kused = used.to_ulong();
    if (cur > N) {
      return 1;
    } else if (dp[cur][kused] != -1) {
      return dp[cur][kused];
    } else {
      dp[cur][kused] = 0;

      for (int i = 0; i < N; i++) {
        // i+1: the value to be inserted
        // cur: the value's index in perm(1-based)
        if (!used[i] && ((i + 1) % cur == 0 || cur % (i + 1) == 0)) {
          used[i] = 1;
          dp[cur][kused] += backtrack(cur + 1, used);
          used[i] = 0;
        }
      }
      cout << "(" << cur << ", " << kused << "): " << dp[cur][kused] << endl;
      return dp[cur][kused];
    }
  }

  int countArrangement(int N) {
    this->N = N;
    bitset<15> used;
    dp = vector<vector<int>>(N + 1, vector<int>(1 << N, -1));
    backtrack(1, used);
    return dp[1][0];
  }
};

int main() {
  Solution S;
  cout << S.countArrangement(5) << endl;
  return 0;
}

// public class Solution {

//     // 用 mask 的二进制表示选取状态，n 个数字用 n 位表示，第 i 位为 1
//     代表数字 i + 1 已被选取（i 从 0 开始），n 中 1 的个数 m 代表前 m 位已放置
//     // 例如：二进制 100110 共三个 1，代表排列的前三位已放置数字，三个 1
//     分别在二进制第 1、2、5 位置上(从右侧开始，从 0 开始计数）
//     // 所以 2、3、6 三个数字被选取，综合起来就是表示：2 3 6
//     这三个数字被放到了排列的前三位，三个数字完美排列方式未知
//     // 通过枚举 mask 进行计算

//     public int countArrangement(int n) {
//         // 状态定义：dp[6] = dp[000110] =
//         数字2、3在「前两位时」的完美排列数量 int size = 1 << n; int[] dp =
//         new int[size]; dp[0] = 1;
//         // 通过 mask 进行枚举，最终目的是为了得到二进制 mask = (11..11)n
//         时，总的完美排列数 for (int mask = 1; mask < size; mask++) {
//             // 目前已经有多少个 1
//             int num = Integer.bitCount(mask);
//             // 遍历 mask 的每一位，仍以 mask = 100110 为例，此 mask 代表 2 3
//             6 三个数字在排列的「前三位」
//             // 求三个数字 2 3 6 的完美排列方式，则先确定 2 3 6
//             哪些数字能放到第三位，然后累加另外两个数字的完美排列数量来获得

//             // liwei
//             注：下面这两个例子很重要，其实就是「分类计数」的「加法原理」
//             // 2 3 6，第三位可以为 6，则 dp[100110] += dp[000110]
//             (2、3在前两位时的完美排列数量)
//             // 2 3 6，第三位可以为 3，则 dp[100110] += dp[100010]
//             (2、6在前两位时的完美排列数量) for (int i = 0; i < n; i++) {
//                 // mask & (1<<i) 用来判断 mask 第 i 位是否为 1，如果为
//                 1，说明第 i+1 个数字被选取
//                 // ((num % (i + 1)) == 0 || (i + 1) % num == 0)
//                 判断被选取的数字 i+1 能否放到位置 num 上，
//                 // 即：先从被选取的数字中找到能放到最高位 num
//                 的数字，然后将剩余 num-1 个数字的完美排列方式累加到f[mask]中
//                 if ((mask & (1 << i)) != 0 && ((num % (i + 1)) == 0 || (i +
//                 1) % num == 0)) {
//                     // mask ^ (1 << i) 将 mask 第 i 位设置为 0
//                     dp[mask] += dp[mask ^ (1 << i)];
//                 }
//             }
//         }
//         return dp[size - 1];
//     }
// }