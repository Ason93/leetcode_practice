/*
https://github.com/kaushal02/interview-coding-problems/blob/master/superStack.cpp
https://gist.github.com/neerajkumar/2fc5f04126910650b55918369144d0be


  You are given an empty stack. Your task is to perform following three
operations: push a: Push an integer a, to the top of the stack pop: Pop the top
element from the stack. It is guaranteed that stack is not empty, when
performing the pop operation. inc x d: Add d to bottom x elements of the stack.
  After each operation, print the top element of the stack, if after an
operation, the stack becomes empty, then print EMPTY. Input Format: The first
line of the input is n, total number of operations performed on the stack. Each
of the next n lines is one of the three operations listed above. Constraints:
  * 0 ≤ n ≤ 2 x 105
  * -10 ≤a,d ≤ 10
  * 1 ≤ x ≤ size of the stack at the time of the operation
  * There is no pop operation when the stack is empty.
  Output Format:
  For each operation, output the top element of the stack. If after an
operation, the stack becomes empty, print EMPTY. Sample Input 12 push 4 pop push
3 push 5 push 2 inc 3 1 pop push 1 inc 2 2 push 4 pop pop Sample Output
  4
  EMPTY
  3
  5
  2
  3
  6
  1
  1
  4
  1
  8
  Explanation
  Assume S is the stack, initially S = [].
        Also, the leftmost element in the S is the bottom most element and the
right most element is the top element of the stack.

  push 4: We push 4 on the top of the stack, so the stack is now S = [4].
        The top element is 4, so we print 4 after this operation.

  pop: We pop the top element from the stack, so the stack is now S = [].
        The stack is empty, so we print EMPTY after this operation.

  push3: We push 3 on the top of the stack, so the stack is now S = [3].
        The top element is 3, so we print 3 after this operation.

  push 5: We push 5 on the top of the stack, so the stack is now S = [3, 5].
        The top element is 5, so we print 5 after this operation.

  push 2: We push 2 on the top of the stack, so the stack is now S = [3, 5, 2].
        The top element is 2, so we print 2 after this operation.

  inc 3 1: We add 1 to bottom 3 elements of the stack, so the stack is now S =
[4, 6, 3]. The top element is 3, so we print 3 after this operation.

  pop: We pop the top element from the stack, so the stack is now S = [4, 6].
        The top element is 6, so we print 6 after this operation.

  push 1: We push 1 on the top of the stack, so the stack is now S = [4, 6, 1].
        The top element is 1, so we print 1 after this operation.

  inc 2 2: We add 2 to bottom 2 elements of the stack, so the stack is now S =
[6, 8, 1]. The top element is 1, so we print 1 after this operation.

  push 4: We push 4 on the top of the stack, so the stack is now S = [6, 8, 1,
4]. The top element is 4, so we print 4 after this operation.

  pop: We pop the top element from the stack, so the stack is now S = [6, 8, 1].
        The top element is 1, so we print 1 after this operation.

  pop: We pop the top element from the stack, so the stack is now S = [6, 8].
        The top element is 8, so we print 8 after this operation.
 */

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
void superStack(vector<string> operations);
int main() {

  vector<string> items;
  items.push_back("push 4");
  items.push_back("pop");
  items.push_back("push 3");
  items.push_back("push 5");
  items.push_back("push 2");
  items.push_back("inc 3 1");
  items.push_back("pop");
  items.push_back("push 1");
  items.push_back("inc 2 2");
  items.push_back("push 4");
  items.push_back("pop");
  items.push_back("pop");

  superStack(items);

  return 0;
}

void superStack(vector<string> operations) {
  vector<string> items;
  int itemIndex = -1;
  vector<int> superStack;

  for (int i = 0; i < operations.size(); i++) {
    string item;
    stringstream ss(operations[i]);

    while (getline(ss, item, ' ')) {
      items.push_back(item);
    }

    if (items[0] == "push") {
      superStack.push_back(atoi(items[1].c_str()));
      itemIndex++;
      cout << superStack[itemIndex] << endl;
    } else if (items[0] == "pop") {
      superStack.erase(superStack.end() - 1);
      itemIndex--;
      if (superStack.size() == 0) {
        cout << "EMPTY" << endl;
      } else {
        cout << superStack[itemIndex] << endl;
      }
    } else {
      int targetIndex = atoi(items[1].c_str());
      int num = atoi(items[2].c_str());

      for (int j = 0; j < targetIndex; j++) {
        superStack[j] += num;
      }

      cout << superStack[itemIndex] << endl;
    }

    items.clear();
  }
}