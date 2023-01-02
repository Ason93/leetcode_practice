/*****************************************************
https://leetcode.com/problems/search-in-rotated-sorted-array/
*****************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    while (l <= r) {
      int m = (l + r) >> 1;
      if (nums[m] == target) {
        return m;
      }
      if (nums[l] <= nums[m]) { // nums[m] is in the ascending order part
        if (target >= nums[l] && target < nums[m]) { // target is in [l, m)
          r = m - 1;
        } else { // target is in (m, r]
          l = m + 1;
        }
      } else {
        if (target > nums[m] && target <= nums[r]) { // target is in (m, r]
          l = m + 1;
        } else { // target is in [l, m)
          r = m - 1;
        }
      }
    }

    return -1;
  }
};

int main() {
  Solution S;
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  int target = 0;
  cout << S.search(nums, target) << endl; // 4

  nums = {4, 5, 6, 7, 0, 1, 2};
  target = 3;
  cout << S.search(nums, target) << endl; // -1

  nums = {1};
  target = 0;
  cout << S.search(nums, target) << endl; // -1

  return 0;
}