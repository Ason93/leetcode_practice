/*****************************************************
https://leetcode.com/problems/binary-search/?envType=study-plan&id=level-1
*****************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (nums[mid] < target) {
        left = mid + 1;
      } else if (nums[mid] > target) {
        right = mid - 1;
      } else {
        return mid;
      }
    }
    return -1;
  }
};

int main() {
  Solution S;

  vector<int> nums = {-1, 0, 3, 5, 9, 12};
  int target = 9;
  cout << S.search(nums, target) << endl;

  nums = {-1, 0, 3, 5, 9, 12};
  target = 2;
  cout << S.search(nums, target) << endl;

  return 0;
}