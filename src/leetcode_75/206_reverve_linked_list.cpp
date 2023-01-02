/*****************************************************
https://leetcode.com/problems/reverse-linked-list/?envType=study-plan&id=level-1
*****************************************************/
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }
    // Need three template point to save status
    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *next = head->next;
    while (next) {
      // 1.current node points to previous node
      curr->next = prev;
      // 2.move all three points forward one step
      prev = curr;
      curr = next;
      next = next->next;
    }
    // 3.finally, let current node point to previous nod
    curr->next = prev;
    return curr;
  }
};

int main() { return 0; }