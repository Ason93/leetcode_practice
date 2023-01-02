#include <iostream>
#include <vector>
using namespace std;

/*
Question:
There are n stairs.
You can take 1/2 steps each time.
But the k of them is bad.
You need to skip the bad ones.
How many kinds to take the stairs?
*/

int take_stair(vector<int> &bad_stairs, int curr, int step, int stair_num) {
  if (curr + step == stair_num) {
    return 1;
  } else if (curr + step > stair_num) {
    return 0;
  } else {
    if (bad_stairs[curr + step] == -1) {
      return 0;
    } else {
      return take_stair(bad_stairs, curr + step, 1, stair_num) +
             take_stair(bad_stairs, curr + step, 2, stair_num);
    }
  }
}

int main() {
  vector<int> bad_stairs = {0, 0,  0, 0, 0,
                            0, -1, 0, 0, 0}; // bad in 6, start from 0
  int stair_num = 10;
  int res = take_stair(bad_stairs, 0, 1, stair_num) +
            take_stair(bad_stairs, 0, 2, stair_num);
  std::cout << "kinds of taking stair: " << res << std::endl;
  return 0;
}