/*****************************************************
https://leetcode.com/problems/find-pivot-index/
*****************************************************/

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  // O(n)
  int pivotIndex(vector<int> &nums) {
    int sumNums = accumulate(nums.begin(), nums.end(), 0);
    int leftSum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (leftSum == sumNums - leftSum - nums[i]) {
        return i;
      }
      leftSum += nums[i];
    }
    return -1;
  }
  // O(n^2)
  int pivotIndex2(vector<int> &nums) {
    for (int idx = 0; idx < nums.size(); ++idx) {
      int sum_l = 0;
      for (int l = 0; l < idx; ++l) {
        sum_l += nums[l];
      }
      int sum_r = 0;
      if (idx + 1 < nums.size()) {
        for (int r = idx + 1; r < nums.size(); ++r) {
          sum_r += nums[r];
        }
      }
      if (sum_l == sum_r) {
        return idx;
      }
    }
    return -1;
  }
};

int main() {
  Solution S;

  vector<int> nums = {1, 7, 3, 6, 5, 6};
  cout << S.pivotIndex(nums) << endl; // 3
  cout << S.pivotIndex2(nums) << endl;

  nums = {1, 2, 3};
  cout << S.pivotIndex(nums) << endl; // -1
  cout << S.pivotIndex2(nums) << endl;

  nums = {2, 1, -1};
  cout << S.pivotIndex(nums) << endl; // 0
  cout << S.pivotIndex2(nums) << endl;

  nums = {-1, -1, 0, 1, 1, 0};
  cout << S.pivotIndex(nums) << endl; // 5
  cout << S.pivotIndex2(nums) << endl;

  return 0;
}