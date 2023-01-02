#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

/***************************************
121 -> 1 time
122 -> inf times
123 -> 2 times
188 -> k times
309 -> inf times, cool down
714 -> inf times, with transaction fee

188. Best Time to Buy and Sell Stock IV
You are given an integer array prices where prices[i] is the price of a given
stock on the ith day, and an integer k. Find the maximum profit you can achieve.
You may complete at most k transactions. Note: You may not engage in multiple
transactions simultaneously (i.e., you must sell the stock before you buy
again).

Example 1:
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit =
4-2 = 2.

Example 2:
Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit =
6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit =
3-0 = 3.
***************************************/
class Solution {
public:
  int maxProfit(int k, vector<int> &prices) {
    if (prices.size() < 2 || k < 1) {
      return 0;
    }
    const int size = prices.size();
    k = k <= size / 2 ? k : size / 2;
    vector<vector<vector<int>>> results(
        size, vector<vector<int>>(
                  k + 1, vector<int>(2, -INT16_MAX))); // why -INT16_MAX?
    for (int i = 0; i < size; i++) {
      results[i][0][0] = 0;
    }
    results[0][1][1] = -prices[0];
    for (int i = 1; i < size; ++i) {
      for (int j = 1; j <= k; ++j) {
        results[i][j][0] = max(results[i - 1][j][0], // no transaction
                               results[i - 1][j][1] + prices[i]); // zero stock
        results[i][j][1] =
            max(results[i - 1][j][1],                  // no transaction
                results[i - 1][j - 1][0] - prices[i]); // one stock
      }
    }
    int result = -INT_MAX;
    for (int i = 0; i < size; ++i) {
      for (int j = 0; j <= k; ++j) {
        result = max(result, results[i][j][0]);
      }
    }
    return result;
  }
};

int main() {
  Solution S;

  int k = 2;
  vector<int> prices = {3, 2, 6, 5, 0, 3};
  cout << S.maxProfit(k, prices) << endl;

  k = 2;
  prices = {2, 4, 1};
  cout << S.maxProfit(k, prices) << endl;

  k = 1;
  prices = {1};
  cout << S.maxProfit(k, prices) << endl;

  k = 4;
  prices = {1, 2, 4, 2, 5, 7, 2, 4, 9, 0};
  cout << S.maxProfit(k, prices) << endl;

  return 0;
}