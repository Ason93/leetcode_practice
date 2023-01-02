/*****************************************************
https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*****************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int count = 0;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i - 1] == nums[i]) {
        count++;
      } else {
        nums[i - count] = nums[i];
      }
    }
    return nums.size() - count;
  }
};

int main() {
  Solution S;
  vector<int> nums1 = {1, 1, 2};
  cout << S.removeDuplicates(nums1) << endl; // 2, nums = [1,2,_]

  vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  cout << S.removeDuplicates(nums2) << endl; // 5, nums = [0,1,2,3,4,_,_,_,_,_]
  return 0;
}