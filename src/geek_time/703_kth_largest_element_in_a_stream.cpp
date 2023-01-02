/****************************************************************************
703. Kth Largest Element in a Stream

Design a class to find the kth largest element in a stream. Note that it is the
kth largest element in the sorted order, not the kth distinct element.

Implement KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the
stream of integers nums. int add(int val) Appends the integer val to the stream
and returns the element representing the kth largest element in the stream.

Example 1:

Input
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
Output
[null, 4, 5, 5, 8, 8]

Explanation
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8


Constraints:

1 <= k <= 104
0 <= nums.length <= 104
-104 <= nums[i] <= 104
-104 <= val <= 104
At most 104 calls will be made to add.
It is guaranteed that there will be at least k elements in the array when you
search for the kth element.
****************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

/******************
method sort: O(n*klog(k))
method priority_queue:  O(n*log(k))
******************/

class KthLargest {
public:
  KthLargest(int k, vector<int> &nums) : k_(k) {
    for (auto n : nums) {
      add(n);
    }
  }

  int add(int val) {
    if (greater_queue_.size() < k_) {
      greater_queue_.emplace(val);
    } else {
      if (val > greater_queue_.top()) {
        greater_queue_.pop();
        greater_queue_.emplace(val);
      }
    }
    return greater_queue_.top();
  }

private:
  int k_;
  priority_queue<int, vector<int>, greater<int>> greater_queue_;
};

int main() {
  int k = 3;
  vector<int> input = {4, 5, 8, 2};
  KthLargest kl(k, input);
  cout << kl.add(3) << endl;  // return 4
  cout << kl.add(5) << endl;  // return 5
  cout << kl.add(10) << endl; // return 5
  cout << kl.add(9) << endl;  // return 8
  cout << kl.add(4) << endl;  // return 8
  return 0;
}
