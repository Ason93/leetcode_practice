#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  /****************************
  1. Two Sum
  Given an array of integers nums and an integer target,
  return indices of the two numbers such that they add up to target.
  You may assume that each input would have exactly one solution,
  and you may not use the same element twice.
  You can return the answer in any order.

  Example 1:
  Input: nums = [2,7,11,15], target = 9
  Output: [0,1]
  Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

  Example 2:
  Input: nums = [3,2,4], target = 6
  Output: [1,2]

  Example 3:
  Input: nums = [3,3], target = 6
  Output: [0,1]
  ****************************/
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> lookup;
    for (int i = 0; i < nums.size(); ++i) {
      if (lookup.count(target - nums[i])) {
        return {lookup[target - nums[i]], i};
      }
      lookup[nums[i]] = i;
    }
    return {};
  }

  /****************************
  15. 3Sum
  Given an integer array nums, return all the triplets [nums[i], nums[j],
  nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k]
  == 0. Notice that the solution set must not contain duplicate triplets.

  Example 1:
  Input: nums = [-1,0,1,2,-1,-4]
  Output: [[-1,-1,2],[-1,0,1]]

  Example 2:
  Input: nums = []
  Output: []

  Example 3:
  Input: nums = [0]
  Output: []
  ****************************/

  // method both sides to middle: time: O(n*logn+n)
  vector<vector<int>> threeSum(vector<int> &nums) {
    if (nums.size() < 3) {
      return {};
    }
    vector<vector<int>> outputs;
    sort(nums.begin(), nums.end());
    for (int n = 0; n < nums.size() - 2; ++n) {
      if (n > 0 && nums[n] == nums[n - 1]) { // remove repetition
        continue;
      }
      int l = n + 1;
      int r = nums.size() - 1;
      while (l < r) {
        int sum = nums[n] + nums[l] + nums[r];
        if (sum < 0) {
          l++;
        } else if (sum > 0) {
          r--;
        } else {
          outputs.emplace_back(vector<int>{nums[n], nums[l], nums[r]});
          while (l < r && nums[l] == nums[l + 1]) { // remove repetition
            l++;
          }
          while (l < r && nums[r] == nums[r - 1]) { // remove repetition
            r--;
          }
          l++;
          r--;
        }
      }
    }
    return outputs;
  }

  // method hashSet: time: O(n*logn+n), space: O(n) (out of time limitation)
  vector<vector<int>> threeSum2(vector<int> &nums) {
    if (nums.size() < 3) {
      return {};
    }
    set<vector<int>> res;           // warn: remove repetition
    sort(nums.begin(), nums.end()); // warn: remove repetition
    for (int i = 0; i < nums.size() - 2; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) { // warn: skip some repetitive cases
        continue;
      }
      set<int> lookup;
      for (int j = i + 1; j < nums.size(); ++j) {
        if (lookup.count(-nums[i] - nums[j])) {
          res.insert(vector<int>{nums[i], nums[j], -nums[i] - nums[j]});
        }
        lookup.insert(nums[j]);
      }
    }
    vector<vector<int>> outputs(res.begin(), res.end());
    return outputs;
  }

  /****************************
  18. 4Sum
  Given an array nums of n integers,
  return an array of all the unique quadruplets [nums[a], nums[b], nums[c],
  nums[d]] such that: 0 <= a, b, c, d < n a, b, c, and d are distinct. nums[a] +
  nums[b] + nums[c] + nums[d] == target You may return the answer in any order.

  Example 1:
  Input: nums = [1,0,-1,0,-2,2], target = 0
  Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

  Example 2:
  Input: nums = [2,2,2,2,2], target = 8
  Output: [[2,2,2,2]]
  ****************************/

  // method both sides to middle: time: O(n*logn+n)
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    if (nums.size() < 4) {
      return {};
    }
    vector<vector<int>> outputs;
    sort(nums.begin(), nums.end());
    for (int n = 0; n < nums.size() - 3; ++n) {
      if (n > 0 && nums[n] == nums[n - 1]) { // remove repetition
        continue;
      }
      for (int m = n + 1; m < nums.size() - 2; ++m) {
        if (m > n + 1 && nums[m] == nums[m - 1]) { // remove repetition
          continue;
        }
        int l = m + 1;
        int r = nums.size() - 1;
        while (l < r) {
          // warn: overflow workround
          int sum_n_m = nums[n] + nums[m];
          int sum_l_r = nums[l] + nums[r];
          if (sum_n_m < target - sum_l_r) {
            l++;
          } else if (sum_n_m > target - sum_l_r) {
            r--;
          } else {
            outputs.emplace_back(
                vector<int>{nums[n], nums[m], nums[l], nums[r]});
            while (l < r && nums[l] == nums[l + 1]) { // remove repetition
              l++;
            }
            while (l < r && nums[r] == nums[r - 1]) { // remove repetition
              r--;
            }
            l++;
            r--;
          }
        }
      }
    }
    return outputs;
  }
};

int main() {
  Solution S;

  cout << "1. Two Sum" << endl;
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  vector<int> output = S.twoSum(nums, target);
  cout << "input:" << endl;
  for (auto i : nums) {
    cout << i << ", ";
  }
  cout << endl;
  cout << "output:" << endl;
  for (auto o : output) {
    cout << o << ", ";
  }
  cout << endl;

  cout << "15. 3Sum" << endl;
  nums = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> outputs = S.threeSum(nums);
  cout << "input:" << endl;
  for (auto i : nums) {
    cout << i << ", ";
  }
  cout << endl;
  cout << "output:" << endl;
  for (auto output : outputs) {
    cout << "[ ";
    for (auto o : output) {
      cout << o << ", ";
    }
    cout << "], ";
  }
  cout << endl;

  cout << "18. 4Sum" << endl;
  // nums = {-1, 0, 1, 0, -2, 2};
  // nums = {0, 0, 0, 0};
  // target = 0;
  nums = {2, 2, 2, 2, 2};
  target = 8;
  outputs = S.fourSum(nums, target);
  cout << "input:" << endl;
  for (auto i : nums) {
    cout << i << ", ";
  }
  cout << endl;
  cout << "output:" << endl;
  for (auto output : outputs) {
    cout << "[ ";
    for (auto o : output) {
      cout << o << ", ";
    }
    cout << "], ";
  }
  cout << endl;

  return 0;
}
