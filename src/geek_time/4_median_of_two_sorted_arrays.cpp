#include <iostream>
#include <vector>
using namespace std;

// method 1
// merge two arrays to an new array and get the median of the new array
// Time: O(m+n)
// Space: O(1)
double findMedianSortedArrays1(vector<int> &nums1, vector<int> &nums2) {
  vector<int> merged_nums;
  if (nums1.empty()) {
    merged_nums = nums2;
  }
  if (nums2.empty()) {
    merged_nums = nums1;
  }
  if (!nums1.empty() && !nums2.empty()) {
    unsigned int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size()) {
      while (nums1[i] <= nums2[j] && i < nums1.size()) {
        merged_nums.emplace_back(nums1[i]);
        i++;
      }
      while (nums1[i] > nums2[j] && j < nums2.size()) {
        merged_nums.emplace_back(nums2[j]);
        j++;
      }
    }
    while (i < nums1.size()) {
      merged_nums.emplace_back(nums1[i]);
      i++;
    }
    while (j < nums2.size()) {
      merged_nums.emplace_back(nums2[j]);
      j++;
    }
  }

  // cout << "merged arrays: " << endl;
  // for (auto num : merged_nums) {
  //   cout << num << ", ";
  // }
  // cout << endl;

  double median = 0.;
  if (!merged_nums.empty()) {
    if (merged_nums.size() % 2 == 0) {
      unsigned int median_idx = merged_nums.size() / 2;
      median = static_cast<double>(
                   (merged_nums[median_idx - 1] + merged_nums[median_idx])) /
               2.;
    } else {
      unsigned int median_idx = merged_nums.size() / 2;
      median = static_cast<double>(merged_nums[median_idx]);
    }
  }

  return median;
}

// method 2
// 1.get the median of each array: m1 and m2
// 2.if m1=m2, return m1 or m2
// 3.if m1>m2, median is in the nums1[0:m1] or nums2[m2:]
// 4.if m1<m2, median is in the nums1[m1:m] or nums2[0:m2]
// 5.repeat the above, until len(m1)==2 and len(m2)==2
// 6.if len(m1)==2 and len(m2)==2, return (max(nums1[0], nums2[0]) +
//    min(nums1[1], nums2[2])) / 2.0 Time: O(log(m+n) Space: O(1)

// /* Utility functions */
// int max(int x, int y) { return x > y ? x : y; }
// int min(int x, int y) { return x > y ? y : x; }

// /* Function to get median of a sorted array */
// int median(int arr[], int n) {
//   if (n % 2 == 0)
//     return (arr[n / 2] + arr[n / 2 - 1]) / 2;
//   else
//     return arr[n / 2];
// }

// double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
//   int m1; /* For median of ar1 */
//   int m2; /* For median of ar2 */
// }

int findKthInTwoSortedArrays(const vector<int> &A, const vector<int> &B,
                             int k) {
  const int m = A.size();
  const int n = B.size();

  // Make sure m is the smaller one.
  if (m > n) {
    return findKthInTwoSortedArrays(B, A, k);
  }

  int left = 0;
  int right = m;
  // Find a partition of A and B
  // where min left s.t. A[left] >= B[k - 1 - left]. Thus A[left] is the
  // (k+1)-th or above element.
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (0 <= k - 1 - mid && k - 1 - mid < n && A[mid] >= B[k - 1 - mid]) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  int Ai_minus_1 = left - 1 >= 0 ? A[left - 1] : numeric_limits<int>::min();
  int Bj = k - 1 - left >= 0 ? B[k - 1 - left] : numeric_limits<int>::min();

  // kth element would be A[left - 1] or B[k - 1 - left].
  return max(Ai_minus_1, Bj);
}

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
  if ((nums1.size() + nums2.size()) % 2 == 1) {
    return findKthInTwoSortedArrays(nums1, nums2,
                                    (nums1.size() + nums2.size()) / 2 + 1);
  } else {
    return (findKthInTwoSortedArrays(nums1, nums2,
                                     (nums1.size() + nums2.size()) / 2) +
            findKthInTwoSortedArrays(nums1, nums2,
                                     (nums1.size() + nums2.size()) / 2 + 1)) /
           2.0;
  }
}

int main() {
  // vector<int> nums1({1, 2});
  // vector<int> nums2({3, 4});
  // double median = findMedianSortedArrays(nums1, nums2);
  // cout << "the median is: " << median << endl;

  vector<int> nums1({1, 3});
  vector<int> nums2({2});
  double median = findMedianSortedArrays(nums1, nums2);
  cout << "the median is: " << median << endl;
  return 0;
}