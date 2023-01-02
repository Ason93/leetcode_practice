#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class TrieNode {
public:
  TrieNode() : is_end(false) {}
  bool is_end;
  unordered_map<char, TrieNode *> leaves;
};

class Solution {
public:
  Solution() { root_ = new TrieNode(); }
  /***************************************************
  79. Word Search
  Given an m x n grid of characters board and a string word, return true if word
  exists in the grid. The word can be constructed from letters of sequentially
  adjacent cells, where adjacent cells are horizontally or vertically
  neighboring. The same letter cell may not be used more than once.

  Example 1:
  Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
  "ABCCED" Output: true

  Example 2:
  Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
  "SEE" Output: true

  Example 3:
  Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
  "ABCB" Output: false
  ***************************************************/
  bool exist(vector<vector<char>> &board, string word) {
    vector<string> words = {word};
    vector<string> results = findWords(board, words);
    if (!results.empty()) {
      return true;
    } else {
      return false;
    }
  }

  /***************************************************
  212. Word Search II
  Given an m x n board of characters and a list of strings words, return all
  words on the board. Each word must be constructed from letters of sequentially
  adjacent cells, where adjacent cells are horizontally or vertically
  neighboring. The same letter cell may not be used more than once in a word.

  Example 1:
  Input: board =
  [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]],
  words = ["oath","pea","eat","rain"] Output: ["eat","oath"]

  Example 2:
  Input: board = [["a","b"],["c","d"]], words = ["abcb"]
  Output: []
  ***************************************************/
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    if (board.empty() || board[0].empty() || words.empty()) {
      return {};
    }
    // create trie
    for (const auto &word : words) {
      insert(word);
    }

    m_ = board.size();
    n_ = board[0].size();
    vector<vector<bool>> visited(m_, vector<bool>(n_, false));
    vector<string> results;
    for (int i = 0; i < m_; ++i) {
      for (int j = 0; j < n_; ++j) {
        findWordsDFS(board, i, j, visited, root_, "", results);
      }
    }

    return results;
  }

  void findWordsDFS(vector<vector<char>> &board, int i, int j,
                    vector<vector<bool>> &visited, TrieNode *node, string joint,
                    vector<string> &results) {
    if (i < 0 || i >= m_ || j < 0 || j >= n_) {
      return;
    }

    if (visited[i][j]) {
      return;
    }

    const char &word = board[i][j];
    TrieNode *next_node = node->leaves[word];
    if (!next_node) {
      return;
    }

    joint += word;
    if (next_node->is_end &&
        find(results.begin(), results.end(), joint) ==
            results.end()) { // warn: remove duplicated result
      results.emplace_back(joint);
    }

    visited[i][j] = true;
    vector<int> x = {0, 0, -1, 1};
    vector<int> y = {-1, 1, 0, 0};
    for (int k = 0; k < x.size(); ++k) {
      findWordsDFS(board, i + x[k], j + y[k], visited, next_node, joint,
                   results);
    }
    visited[i][j] = false;
  }

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

  // bool searchTrie(string &word) {
  //   auto *cur = root_;
  //   for (auto &c : word) {
  //     if (cur->leaves.count(c) == 0) {
  //       return false;
  //     } else {
  //       cur = cur->leaves[c];
  //     }
  //   }
  //   return cur->is_end;
  // }

private:
  TrieNode *root_;
  int m_;
  int n_;
};

int main() {
  Solution S0;
  vector<vector<char>> board0 = {{'o', 'a', 'a', 'n'},
                                 {'e', 't', 'a', 'e'},
                                 {'i', 'h', 'k', 'r'},
                                 {'i', 'f', 'l', 'v'}};

  string word0 = "oath";
  cout << S0.exist(board0, word0) << endl;

  Solution S;
  vector<vector<char>> board = {{'o', 'a', 'a', 'n'},
                                {'e', 't', 'a', 'e'},
                                {'i', 'h', 'k', 'r'},
                                {'i', 'f', 'l', 'v'}};
  vector<string> words = {"oath", "pea", "eat", "rain"};
  vector<string> results = S.findWords(board, words);
  cout << "results1: " << endl;
  for (auto &result : results) {
    cout << result << endl;
  }

  Solution S2;
  vector<vector<char>> board2 = {{'o', 'a', 'b', 'n'},
                                 {'o', 't', 'a', 'e'},
                                 {'a', 'h', 'k', 'r'},
                                 {'a', 'f', 'l', 'v'}};
  vector<string> words2 = {"oa", "oaa"};
  vector<string> results2 = S2.findWords(board2, words2);
  cout << "results2: " << endl;
  for (auto &result : results2) {
    cout << result << endl;
  }

  return 0;
}
