/*****************************************************
https://leetcode.com/problems/merge-k-sorted-lists/
*****************************************************/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//
class Cmp {
public:
  bool operator()(ListNode *l1, ListNode *l2) { return l1->val >= l2->val; }
};

class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode start;
    priority_queue<ListNode *, vector<ListNode *>, Cmp> pq;
    // priority_queue<Type, Container, Functional>
    // greater<>: class, ascending，top() return min
    for (auto l : lists) {
      while (l) {
        pq.push(l);
        l = l->next;
      }
    }
    if (pq.empty()) {
      return nullptr;
    }
    ListNode *head = new ListNode(pq.top()->val);
    start.next = head;
    pq.pop();
    while (!pq.empty()) {
      ListNode *nl = new ListNode(pq.top()->val);
      head->next = nl;
      head = head->next;
      pq.pop();
    }
    return start.next;
  }
};

int main() { return 0; }