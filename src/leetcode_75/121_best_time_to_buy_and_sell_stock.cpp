/*****************************************************
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*****************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.empty()) {
      return 0;
    }
    int minPrice = prices[0];
    int maxProfit = 0;
    for (auto price : prices) {
      minPrice = min(minPrice, price);
      maxProfit = max(maxProfit, price - minPrice);
    }
    return maxProfit;
  }
};

int main() {
  Solution S;

  vector<int> prices = {7, 1, 5, 3, 6, 4};
  cout << S.maxProfit(prices) << endl; // 5

  prices = {7, 6, 4, 3, 1};
  cout << S.maxProfit(prices) << endl; // 0

  return 0;
}