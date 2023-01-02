/*****************************************************
https://leetcode.com/problems/running-sum-of-1d-array/
*****************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> runningSum(vector<int> &nums) {
    if (nums.empty()) {
      return vector<int>({});
    }
    vector<int> results(nums.size(), 0);
    results[0] = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      results[i] = nums[i] + results[i - 1];
    }
    return results;
  }
};

int main() {
  Solution S;

  vector<int> nums = {1, 2, 3, 4};
  vector<int> outputs = S.runningSum(nums);
  for (int i = 0; i < outputs.size(); ++i) {
    cout << outputs[i] << endl;
  }

  nums = {1, 1, 1, 1};
  outputs = S.runningSum(nums);
  for (int i = 0; i < outputs.size(); ++i) {
    cout << outputs[i] << endl;
  }

  nums = {3, 1, 2, 10, 1};
  outputs = S.runningSum(nums);
  for (int i = 0; i < outputs.size(); ++i) {
    cout << outputs[i] << endl;
  }

  return 0;
}