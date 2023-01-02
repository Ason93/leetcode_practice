/*****************************************************
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
*****************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int start = binaryFind(nums, target);
    int end = binaryFind(nums, target + 1);
    if (start == nums.size() || nums[start] != target) {
      return vector<int>(2, -1);
    }
    vector<int> ans;
    ans.emplace_back(start);
    ans.emplace_back(max(start, end - 1));
    return ans;
  }

  int binaryFind(const vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size();
    while (left < right) {
      int mid = (right + left) / 2;
      if (nums[mid] >= target) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};

int main() {
  Solution S;
  vector<int> nums = {5, 7, 7, 8, 8, 10};
  int target = 8;
  vector<int> outputs = S.searchRange(nums, target); // [3, 4]
  cout << "output1: " << endl;
  for (auto o : outputs) {
    cout << o << endl;
  }

  nums = {5, 7, 7, 8, 8, 10};
  target = 6;
  outputs = S.searchRange(nums, target); // [-1, -1]
  cout << "output2: " << endl;
  for (auto o : outputs) {
    cout << o << endl;
  }

  nums = {};
  target = 0;
  outputs = S.searchRange(nums, target); // [-1, -1]
  cout << "output3: " << endl;
  for (auto o : outputs) {
    cout << o << endl;
  }

  return 0;
}