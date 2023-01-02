/****************************************************************************
146. LRU Cache

Design a data structure that follows the constraints of a Least Recently Used
(LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return
-1. void put(int key, int value) Update the value of the key if the key exists.
Otherwise, add the key-value pair to the cache.
If the number of keys exceeds the capacity from this operation, evict the least
recently used key. The functions get and put must each run in O(1) average time
complexity.

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // return -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4

Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.
****************************************************************************/

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

//// method 1
// class LRUCache {
// private:
//   int cap_;
//   list<pair<int, int>> lru_;
//   unordered_map<int, list<pair<int, int>>::iterator> lru_map_;
//
// private:
//   void update(int key, int value) {
//     auto iter = lru_map_.find(key);
//     if (iter != lru_map_.end()) {
//       lru_.erase(iter->second);
//     }
//     lru_.emplace_front(key, value);
//     lru_map_[key] = lru_.begin();
//   }
//
// public:
//   LRUCache(int cap) : cap_(cap) {}
//
//   int get(int key) {
//     if (lru_map_.find(key) != lru_map_.end()) {
//       int value = lru_map_[key]->second;
//       update(key, value);
//       return value;
//     } else {
//       return -1;
//     }
//   }
//
//   void put(int key, int value) {
//     if (lru_map_.find(key) == lru_map_.end() && lru_.size() == cap_) {
//       auto del = lru_.back();
//       lru_.pop_back();
//       lru_map_.erase(del.first);
//     }
//     update(key, value);
//   }
// };

class LRUCache {
public:
  LRUCache(int cap) : cap_(cap) {}

  int get(int key) {
    auto iter = lru_map_.find(key);
    if (iter != lru_map_.end()) {
      int value = lru_map_[key]->second;
      update(key, value);
      return value;
    } else {
      return -1;
    }
  }

  void put(int key, int value) {
    auto iter = lru_map_.find(key);
    if (iter == lru_map_.end() && lru_.size() == cap_) {
      auto del = lru_.back();
      lru_.pop_back();
      lru_map_.erase(del.first);
    }
    update(key, value);
  }

private:
  int cap_;
  list<pair<int, int>> lru_;
  unordered_map<int, list<pair<int, int>>::iterator> lru_map_;

  void update(int key, int value) {
    auto iter = lru_map_.find(key);
    if (iter != lru_map_.end()) {
      lru_.erase(iter->second);
    }
    lru_.emplace_front(make_pair(key, value));
    lru_map_[key] = lru_.begin();
  }
};

//// method 2
// struct Node {
//   int key;
//   int val;
//   Node *previous;
//   Node *next;
//   Node(int key, int val) {
//     this->key = key;
//     this->val = val;
//     this->previous = NULL;
//     this->next = NULL;
//   }
// };
// class LRUCache {
// private:
//   int capacity;
//   int currentCap = 0;
//   Node *head;
//   Node *tail;
//   unordered_map<int, Node *> map;
//
//   void addNode(Node *node) {
//     Node *nxt = head->next;
//     node->previous = head;
//     head->next = node;
//     node->next = nxt;
//     nxt->previous = node;
//   }
//   void deleteNode(Node *delnode) {
//     Node *delprevious = delnode->previous;
//     Node *delnext = delnode->next;
//     delprevious->next = delnext;
//     delnext->previous = delprevious;
//   }
//
// public:
//   LRUCache(int capacity) {
//     this->capacity = capacity;
//     this->head = new Node(0, 0);
//     this->tail = new Node(0, 0);
//     head->next = tail;
//     tail->previous = head;
//   }
//
//   int get(int key) {
//     if (map.find(key) == map.end())
//       return -1;
//     deleteNode(map[key]);
//     addNode(new Node(key, map[key]->val));
//     map[key] = head->next;
//     return head->next->val;
//   }
//
//   void put(int key, int val) {
//     if (map.find(key) != map.end()) {
//       deleteNode(map[key]);
//       addNode(new Node(key, val));
//       map[key] = head->next;
//     } else {
//       if (currentCap < capacity) {
//         addNode(new Node(key, val));
//         map.insert({key, head->next});
//         currentCap++;
//       }
//
//       else {
//         map.erase(tail->previous->key);
//         deleteNode(tail->previous);
//         addNode(new Node(key, val));
//         map.insert({key, head->next});
//       }
//     }
//   }
// };

int main() {
  LRUCache lRUCache(2);
  lRUCache.put(1, 1);              // cache is {1=1}
  lRUCache.put(2, 2);              // cache is {1=1, 2=2}
  cout << lRUCache.get(1) << endl; // return 1
  lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
  cout << lRUCache.get(2) << endl; // return -1 (not found)
  lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
  cout << lRUCache.get(1) << endl; // return -1 (not found)
  cout << lRUCache.get(3) << endl; // return 3
  cout << lRUCache.get(4) << endl; // return 4
}
