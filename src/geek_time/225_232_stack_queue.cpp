#include <iostream>
#include <queue>
#include <stack>

using namespace std;

/******************************************
225. Implement Stack using Queues
Implement a last-in-first-out (LIFO) stack using only two queues.
The implemented stack should support all the functions of a normal stack (push,
top, pop, and empty).

Implement the MyStack class:
void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.

Notes:
You must use only standard operations of a queue, which means that only push to
back, peek/pop from front, size and is empty operations are valid. Depending on
your language, the queue may not be supported natively. You may simulate a queue
using a list or deque (double-ended queue) as long as you use only a queue's
standard operations.

Example 1:
Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
*******************************************/

class MyStack {
public:
  MyStack() {}

  void push(int x) {
    q_.push(x);
    for (int i = 0; i < q_.size() - 1; ++i) {
      int val = q_.front();
      q_.pop(); // pop the front of queue
      q_.push(val);
    }
  }

  int pop() {
    int val = q_.front();
    q_.pop();
    return val;
  }

  int top() { return q_.front(); }

  bool empty() { return q_.empty(); }

  queue<int> q_;
};

/******************************************
232. Implement Queue using Stacks
Implement a first in first out (FIFO) queue using only two stacks.
The implemented queue should support all the functions of a normal queue (push,
peek, pop, and empty).

Implement the MyQueue class:
void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.

Notes:
You must use only standard operations of a stack, which means only push to top,
peek/pop from top, size, and is empty operations are valid. Depending on your
language, the stack may not be supported natively. You may simulate a stack
using a list or deque (double-ended queue) as long as you use only a stack's
standard operations.

Example 1:
Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
*******************************************/

class MyQueue {
public:
  MyQueue() {}

  void push(int x) { s_in_.emplace(x); }

  int pop() { // Removes the element from the front of the queue and returns it.
    int top = peek();
    s_out_.pop();
    return top;
  }

  int peek() { // Returns the element at the front of the queue.
    if (s_out_.empty()) {
      while (!s_in_.empty()) {
        s_out_.emplace(s_in_.top());
        s_in_.pop();
      }
    }
    return s_out_.top();
  }

  bool empty() { return s_in_.empty() && s_out_.empty(); }

  stack<int> s_in_, s_out_;
};

int main() {
  cout << "225. Implement Stack using Queues" << endl;
  MyStack myStack;
  myStack.push(1);
  myStack.push(2);
  cout << myStack.top() << endl;   // return 2
  cout << myStack.pop() << endl;   // return 2
  cout << myStack.empty() << endl; // return False

  cout << "232. Implement Queue using Stacks" << endl;
  MyQueue myQueue;
  myQueue.push(1); // queue is: [1]
  myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
  cout << myQueue.peek() << endl;  // return 1
  cout << myQueue.pop() << endl;   // return 1, queue is [2]
  cout << myQueue.empty() << endl; // return false

  return 0;
}
