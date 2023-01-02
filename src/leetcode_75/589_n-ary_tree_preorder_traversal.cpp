/*****************************************************
https://leetcode.com/problems/n-ary-tree-preorder-traversal/?envType=study-plan&id=level-1
*****************************************************/

#include <iostream>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
public:
  vector<int> preorder(Node *root) {
    vector<int> preorder;
    traverse(root, preorder);
    return preorder;
  }

private:
  void traverse(Node *node, vector<int> &preorder) {
    if (node == nullptr) {
      return;
    }
    preorder.emplace_back(node->val);
    for (int i = 0; i < node->children.size(); ++i) {
      traverse(node->children[i], preorder);
    }
  }
};

int main() { return 0; }