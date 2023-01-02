#include <iostream>
#include <vector>

using namespace std;

/**************************************
169. Majority Element
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times.
You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2
**************************************/

// 1. violence to solve: O(n^2)
// 2. map: O(n), space: O(n)
// 3. sort: O(nlogn)
// 4. divide & conquer: O(nlogn)
// 5. count: O(n)
class Solution {
public:
  int majorityElement(vector<int> &nums) {
    int ans = nums[0];
    int count = 0;
    for (auto num : nums) {
      if (num == ans) {
        count++;
      } else {
        count--;
        if (count == 0) {
          ans = num;
          count = 1;
        }
      }
    }
    return ans;
  }
};

int main() {

  Solution S;

  vector<int> nums = {3, 2, 3};
  cout << S.majorityElement(nums) << endl;

  nums = {2, 2, 1, 1, 1, 2, 2};
  cout << S.majorityElement(nums) << endl;

  return 0;
}
