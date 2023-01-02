/*****************************************************
https://leetcode.com/problems/flood-fill/?envType=study-plan&id=level-1
*****************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  // dfs
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int color) {
    int value = image[sr][sc];
    dfs(image, sr, sc, color, value);
    return image;
  }

private:
  void dfs(vector<vector<int>> &image, int sr, int sc, int color, int value) {
    if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() ||
        image[sr][sc] != value || image[sr][sc] == color) {
      return;
    }
    image[sr][sc] = color;
    vector<int> mr = {-1, 1, 0, 0};
    vector<int> mc = {0, 0, -1, 1};
    for (int i = 0; i < mr.size(); ++i) {
      dfs(image, sr + mr[i], sc + mc[i], color, value);
    }
  }
};

int main() {
  Solution S;

  vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
  int sr = 1, sc = 1;
  int color = 2;
  vector<vector<int>> outputs = S.floodFill(image, sr, sc, color);

  image = {{0, 0, 0}, {0, 0, 0}};
  sr = 0;
  sc = 0;
  color = 0;
  outputs = S.floodFill(image, sr, sc, color);

  image = {{0, 0, 0}, {0, 0, 0}};
  sr = 1;
  sc = 0;
  color = 2;
  outputs = S.floodFill(image, sr, sc, color);
  return 0;
}