/*****************************************************
https://leetcode.com/problems/first-missing-positive
*****************************************************/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    int min_pos = 1;
    sort(nums.begin(), nums.end());
    for (auto num : nums) {
      if (min_pos == num) {
        min_pos++;
      }
    }
    return min_pos;
  }
};

int main() {
  Solution S;
  vector<int> nums = {1, 2, 0};
  cout << S.firstMissingPositive(nums) << endl; // 3

  nums = {3, 4, -1, 1};
  cout << S.firstMissingPositive(nums) << endl; // 2

  nums = {7, 8, 9, 11, 12};
  cout << S.firstMissingPositive(nums) << endl; // 1

  nums = {2, 1};
  cout << S.firstMissingPositive(nums) << endl; // 3

  return 0;
}