/*****************************************************
https://leetcode.com/problems/remove-nth-node-from-end-of-list/
*****************************************************/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode start;
    start.next = head;
    ListNode *fast = &start;
    ListNode *slow = &start;
    for (int i = 0; i < n; ++i) {
      fast = fast->next;
    }
    while (fast->next != nullptr) {
      fast = fast->next;
      slow = slow->next;
    }
    slow->next = slow->next->next;
    return start.next;
  }
};

int main() { return 0; }