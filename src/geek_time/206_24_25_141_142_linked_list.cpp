#include <iostream>
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
  ListNode *createList() {
    ListNode *head = new ListNode();
    ListNode *curr_node = head;
    for (int i = 1; i < 10; i++) {
      ListNode *next_node = new ListNode(i);
      curr_node->next = next_node;
      curr_node = next_node;
    }
    return head;
  }

  void printNode(ListNode *head) {
    if (head != nullptr && head->next == nullptr)
      return;
    // head = head->next;
    while (head != nullptr) {
      cout << head->val;
      head = head->next;
      if (head != nullptr) {
        cout << "-->";
      }
    }
    cout << endl;
  }

  /*********************************************
206. Reverse Linked List
Given the head of a singly linked list,
reverse the list, and return the reversed list.
  input: 1->2->3->4->5->null
  output: 5->4->3->2->1->null
*********************************************/
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    // Need three template point to save status
    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *next = head->next;
    while (next != nullptr) {
      // 1.current node points to previous node
      curr->next = prev;
      // 2.move all three points back one step
      prev = curr;
      curr = next;
      next = next->next;
    }
    // 3.finally, let current node point to previous node
    curr->next = prev;
    return curr;
  }

  /*********************************************
  24. Swap Nodes in Pairs
  Given a linked list, swap every two adjacent nodes and return its head.
  You must solve the problem without modifying the values in the list's nodes
  (i.e., only nodes themselves may be changed.)
  input: 1->2->3->4->5->null
  output: 2->1->4->3->5->null
*********************************************/
  ListNode *swapPairs(ListNode *head) {
    ListNode virtual_head; // virtual head to return
    virtual_head.next = head;
    ListNode *prev = &virtual_head;
    ListNode *curr = head;
    ListNode *next = nullptr;
    while (curr != nullptr && curr->next != nullptr) {
      next = curr->next->next; // 1) next point skips by stride 2
      prev->next = curr->next; // 2)
      prev->next->next = curr; // 3)
      curr->next = next;       // 4)
      prev = curr;
      curr = next;
    }
    return virtual_head.next;
  }

  /*********************************************
  25. Reverse Nodes in k-Group
Given the head of a linked list, reverse the nodes of the list k at a time, and
return the modified list. k is a positive integer and is less than or equal to
the length of the linked list. If the number of nodes is not a multiple of k
then left-out nodes, in the end, should remain as it is. You may not alter the
values in the list's nodes, only nodes themselves may be changed. input:
1->2->3->4->5->null, k = 3 output: 3->2->1->4->5->null
  *********************************************/
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode virtual_head;
    virtual_head.next = head;
    ListNode *begin = &virtual_head;
    ListNode *end = head;
    int len = 0;
    while (end) {
      end = end->next;
      len = (len + 1) % k;
      if (len == 0) {
        ListNode *real_begin = begin->next;
        reverse(begin, end);
        begin = real_begin;
      }
    }
    return virtual_head.next;
  }

  void reverse(ListNode *begin, ListNode *end) {
    ListNode *prev = begin;
    ListNode *curr = begin->next;
    ListNode *real_begin = begin->next;
    ListNode *next = curr->next;
    while (next != end) {
      curr->next = prev;
      prev = curr;
      curr = next;
      next = next->next;
    }
    curr->next = prev;
    begin->next = curr;
    real_begin->next = end;
  }

  /*********************************************
  141. Linked List Cycle
Given head, the head of a linked list, determine if the linked list has a cycle
in it. There is a cycle in a linked list if there is some node in the list that
can be reached again by continuously following the next pointer. Internally, pos
is used to denote the index of the node that tail's next pointer is connected
to. Note that pos is not passed as a parameter. Return true if there is a cycle
in the linked list. Otherwise, return false.
  *********************************************/
  bool hasCycle(ListNode *head) {
    ListNode *slow_ptr = head;
    ListNode *fast_ptr = head;
    while (fast_ptr && fast_ptr->next) { // warning: only one node in list
      slow_ptr = slow_ptr->next;
      fast_ptr = fast_ptr->next->next;
      if (slow_ptr == fast_ptr) {
        return true;
      }
    }
    return false;
  }

  /*********************************************
  142. Linked List Cycle II
  Given the head of a linked list, return the node where the cycle begins. If
  there is no cycle, return null. There is a cycle in a linked list if there is
  some node in the list that can be reached again by continuously following the
  next pointer. Internally, pos is used to denote the index of the node that
  tail's next pointer is connected to (0-indexed). It is -1 if there is no
  cycle. Note that pos is not passed as a parameter. Do not modify the linked
  list.
  *********************************************/
  ListNode *detectCycle(ListNode *head) {
    ListNode *slow_ptr = head;
    ListNode *fast_ptr = head;
    while (fast_ptr && fast_ptr->next) { // warning: only one node in list
      slow_ptr = slow_ptr->next;
      fast_ptr = fast_ptr->next->next;
      if (slow_ptr == fast_ptr) { // linked list has cycle
        fast_ptr = head;
        while (fast_ptr != slow_ptr) { // slow and fast point have the same step
          slow_ptr = slow_ptr->next;
          fast_ptr = fast_ptr->next;
        }
        return slow_ptr;
      }
    }
    return nullptr;
  }
};

int main() {
  cout << "*************** 206.Reverse Linked List ***************" << endl;
  Solution S1;
  ListNode *head1 = S1.createList();
  cout << "input linked list:" << endl;
  S1.printNode(head1);
  ListNode *reverseHead = S1.reverseList(head1);
  cout << "output linked list:" << endl;
  S1.printNode(reverseHead);

  cout << "*************** 24.Swap Nodes in Pairs ***************" << endl;
  cout << "input linked list:" << endl;
  Solution S2;
  ListNode *head2 = S2.createList();
  S2.printNode(head2);
  ListNode *swapHead = S2.swapPairs(head2);
  cout << "output linked list:" << endl;
  S2.printNode(swapHead);

  cout << "*************** 25.Reverse Nodes in k-Group ***************" << endl;
  cout << "input linked list:" << endl;
  Solution S3;
  ListNode *head3 = S3.createList();
  S3.printNode(head3);
  ListNode *kGroupHead = S3.reverseKGroup(head3, 2);
  cout << "output linked list:" << endl;
  S3.printNode(kGroupHead);

  cout << "*************** 141.Linked list Cycle ***************" << endl;
  cout << "input linked list:" << endl;
  Solution S4;
  ListNode *head4 = S4.createList();
  S4.printNode(head4);
  bool has_cycle = S4.hasCycle(head4);
  cout << "whether linked list has cycle:" << has_cycle << endl;

  cout << "*************** 142. Linked List Cycle II ***************" << endl;
  cout << "input linked list:" << endl;
  Solution S5;
  ListNode *head5 = S5.createList();
  S5.printNode(head5);
  ListNode *cycle_start = S5.detectCycle(head5);
  if (cycle_start) {
    cout << "linked list cycle start is:" << cycle_start->val << endl;
  } else {
    cout << "linked list cycle start is: null" << endl;
  }
  return 0;
}
