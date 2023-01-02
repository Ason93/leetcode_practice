#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
};

class Solution {
public:
  TreeNode *Convert(TreeNode *root) {
    if (root == nullptr) {
      return nullptr;
    }
    // the last node of the list
    TreeNode *last = nullptr;
    // DFS to build a double linked list
    ConvertNode(root, last);
    // find the first node of a double linked list
    while (last->left != nullptr) {
      last = last->left;
    }
    // return the first node of a double linked list
    return last;
  }

  void ConvertNode(TreeNode *cur, TreeNode *&last) {
    if (cur == nullptr) {
      return;
    }
    // traverse the left subtree
    if (cur->left != nullptr) {
      ConvertNode(cur->left, last);
    }
    // double link
    cur->left = last;
    if (last != nullptr) {
      last->right = cur;
    }
    last = cur;
    // traverse the right subtree
    if (cur->right != nullptr) {
      ConvertNode(cur->right, last);
    }
  }
};

int main() { return 0; }