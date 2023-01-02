#include <iostream>
#include <unordered_map>

using namespace std;

/******************************************
208. Implement Trie (Prefix Tree)
A trie (pronounced as "try") or prefix tree is a tree data structure used to
efficiently store and retrieve keys in a dataset of strings. There are various
applications of this data structure, such as autocomplete and spellchecker.
Implement the Trie class:
Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie
(i.e., was inserted before), and false otherwise. boolean startsWith(String
prefix) Returns true if there is a previously inserted string word that has the
prefix prefix, and false otherwise.

Example 1:
Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
******************************************/

class TrieNode {
public:
  TrieNode() : is_end(false) {}
  bool is_end;
  unordered_map<char, TrieNode *> leaves;
};

class Trie {
public:
  Trie() { root_ = new TrieNode(); }

  void insert(string word) {
    auto *cur = root_;
    for (const auto &c : word) {
      if (cur->leaves.count(c) == 0) {
        cur->leaves[c] = new TrieNode();
      }
      cur = cur->leaves[c];
    }
    cur->is_end = true;
  }

  bool search(string word) {
    auto *cur = root_;
    for (const auto &c : word) {
      if (cur->leaves.count(c) > 0) {
        cur = cur->leaves[c];
      } else {
        return false;
      }
    }
    return cur->is_end;
  }

  bool startsWith(string prefix) {
    auto *cur = root_;
    for (const auto &c : prefix) {
      if (cur->leaves.count(c) > 0) {
        cur = cur->leaves[c];
      } else {
        return false;
      }
    }
    return true;
  }

private:
  TrieNode *root_;
};

int main() {
  Trie *trie = new Trie();
  trie->insert("apple");
  cout << trie->search("apple") << endl;   // return True
  cout << trie->search("app") << endl;     // return False
  cout << trie->startsWith("app") << endl; // return True
  trie->insert("app");
  cout << trie->search("app") << endl; // return True
  return 0;
}