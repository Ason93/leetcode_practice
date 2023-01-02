// https://www.cnblogs.com/lpxblog/p/5085503.html
#include <iostream>
#include <map>
using namespace std;

class node {
public:
  int number;
  node *next;
  node(int a, node *b) {
    number = a;
    next = b;
  }
};

class stacks {
public:
  node *top;
  stacks(node *a = NULL) { top = NULL; }
  void push(int a) {
    if (top == NULL)
      top = new node(a, NULL);
    else
      top = new node(a, top);
  }
  void pop() {
    node *b = top;
    top = top->next;
    delete b;
  }

}; //保存已加入路径结点的栈

int cur_node;      //当前结点，即为栈顶的结点
int next_node = 8; //当前结点的下一个邻接点，即刚从栈顶弹出的结点，初始化为8
map<int, int> map_next; //每个结点的下一个邻接点，即刚从栈顶弹出的结点
int start = 3;
int end_num = 6; //起点为3，终点为6
stacks aray[8] = {stacks(NULL), stacks(NULL), stacks(NULL), stacks(NULL),
                  stacks(NULL), stacks(NULL), stacks(NULL), stacks(NULL)};
stacks stack(NULL);
int states[8]; //保存结点状态的数组

int main() {
  //初始化map_next
  for (int i = 0; i <= 7; i++) {
    map_next[i] = -1;
  }
  aray[0].push(2);
  aray[0].push(1);
  aray[1].push(4);
  aray[1].push(3);
  aray[1].push(0);
  aray[2].push(6);
  aray[2].push(5);
  aray[2].push(0);
  aray[3].push(7);
  aray[3].push(1);
  aray[4].push(7);
  aray[4].push(1);
  aray[5].push(6);
  aray[5].push(2);
  aray[6].push(5);
  aray[6].push(2);
  aray[7].push(4);
  aray[7].push(3);
  node *neighbour(int a);   // ,int b
  stack.push(start);        //将起点入栈
  states[start] = 1;        //将起点标记为入栈状态
  while (NULL != stack.top) //栈不为空
  {
    if (stack.top->number == end_num) {
      cout << "end";
      node *abc = stack.top;
      while (abc->number != start) {
        cout << abc->number << ",";
        abc = abc->next;
      }
      cout << "start" << endl; //输出已找到的路径
      stack.pop();             //将栈顶结点弹出
      states[end_num] = 0;     //清除终点的状态
      map_next[end_num] = -1;
    } else {
      cur_node = stack.top->number;
      if (neighbour(cur_node) != NULL) //邻居不为空
      {
        node *d = neighbour(cur_node);
        map_next[cur_node] = d->number;
        cur_node = d->number;
        stack.push(cur_node);
        states[cur_node] = 1;
      } else {
        stack.pop();
        states[cur_node] = 0;
        map_next[cur_node] = -1;
      }
    }
  }
  return 0;
}

node *neighbour(int a) //,int b
{
  node *abc = aray[a].top;
  while ((NULL != abc)) //结点abc不空
  {
    if (states[abc->number] == 1) //已经在栈stack里了
    {
      abc = abc->next;
    } else //不在栈stack里
    {
      if (-1 == map_next[a]) //就要abc作为返回值
      {
        while (NULL != abc && states[abc->number] == 1) {
          abc = abc->next;
        }
        return abc;

      } else if (abc->number == map_next[a]) {
        abc = abc->next;
        while (NULL != abc && states[abc->number] == 1) {
          abc = abc->next;
        }
        return abc; //将abc的下一个结点返回
      } else {
        abc = abc->next;
      }
    }
  }
  return NULL;
}

// #include <iostream>
// #include <vector>
// using namespace std;

// class Node {
// private:
//   string op_name_;
//   string op_type_;
//   bool visited_ = false;
//   vector<Node *> next_nodes_;
//   vector<Node *> prev_nodes_;

// public:
//   Node(const string &op_name, const string &op_type,
//        const vector<Node *> &next_nodes)
//       : op_name_(op_name), op_type_(op_type), next_nodes_(next_nodes) {
//     ;
//   }
//   ~Node() { ; }

//   const string &op_name() { return op_name_; }
//   const string &op_type() { return op_type_; }
//   void set_visited(bool flag) { visited_ = flag; }
//   const bool visited() { return visited_; }
//   const vector<Node *> &next_nodes() { return next_nodes_; }
//   void set_prev_nodes(Node *prev_node) { prev_nodes_.emplace_back(prev_node);
//   } const vector<Node *> &prev_nodes() { return prev_nodes_; }
// };

// class Graph {
// private:
//   int node_size_;
//   vector<Node *> inputs_;
//   Graph *sub_graph_;
//   vector<Node *> match_;
//   vector<vector<Node *>> matches_;

// public:
//   Graph(const int node_size, const vector<Node *> &inputs)
//       : node_size_(node_size), inputs_(inputs) {
//     init_prev_nodes();
//   }
//   ~Graph() { ; }

//   const int &node_size() { return node_size_; }
//   const vector<Node *> &inputs() { return inputs_; }
//   const vector<vector<Node *>> &matches() { return matches_; }

//   void print_matches() {
//     cout << "####### matches results ########" << endl;
//     for (int i = 0; i < matches_.size(); ++i) {
//       cout << "####### matches chain " << i << ": ";
//       for (auto node : matches_[i]) {
//         cout << node->op_name() << ", ";
//       }
//       cout << endl;
//     }
//   }

//   void sub_graph_match(Graph *sub_graph) {
//     sub_graph_ = sub_graph;
//     for (auto sub_input : sub_graph_->inputs()) {
//       for (auto input : this->inputs()) {
//         match_traverse(sub_input, input);
//       }
//     }
//   }

//   void print_prev_node_name(Node *node) {
//     cout << "node name: " << node->op_name() << "; prev node name: ";
//     for (auto prev_node : node->prev_nodes()) {
//       cout << prev_node->op_name() << ", ";
//     }
//     cout << endl;
//     for (auto next_node : node->next_nodes()) {
//       print_prev_node_name(next_node);
//     }
//   }

// private:
//   void match_traverse(Node *sub_node, Node *node) {
//     // if is deep to output but not find chain, fallback node
//     if (node->next_nodes().empty() || node->visited()) {
//       node->set_visited(true);
//       if (match_.size() > 0 && match_.back()->op_name() == node->op_name()) {
//         match_.pop_back();
//         for (auto sub_prev_node : sub_node->prev_nodes()) {
//           for (auto prev_node : node->prev_nodes()) {
//             for (auto prev_next_node : prev_node->next_nodes()) {
//               if (!prev_next_node->visited()) {
//                 match_traverse(sub_prev_node, prev_next_node);
//               }
//             }
//           }
//         }
//       } else {
//         for (auto prev_node : node->prev_nodes()) {
//           for (auto prev_next_node : prev_node->next_nodes()) {
//             if (!prev_next_node->visited()) {
//               match_traverse(node, prev_next_node);
//             }
//           }
//         }
//       }
//     }
//     node->set_visited(true);

//     if (sub_node->op_type() != node->op_type()) {
//       // not find chain, continue to traverse nodes
//       for (auto next_node : node->next_nodes()) {
//         match_traverse(sub_node, next_node);
//       }
//     } else {
//       match_.emplace_back(node);
//       // find one chain
//       if (match_.size() == sub_graph_->node_size()) {
//         matches_.emplace_back(match_);
//       } else {
//         // find a part of chain, compare next sub_node with node
//         for (auto next_node : node->next_nodes()) {
//           for (auto sub_next_node : sub_node->next_nodes()) {
//             match_traverse(sub_next_node, next_node);
//           }
//         }
//       }
//     }
//   }

//   void init_prev_nodes() {
//     for (auto node : this->inputs()) {
//       search_prev_nodes(node);
//     }
//   }

//   void search_prev_nodes(Node *node) {
//     for (auto next_node : node->next_nodes()) {
//       next_node->set_prev_nodes(node);
//       search_prev_nodes(next_node);
//     }
//   }
// };

// int main() {
//   // init graph
//   const int node_size = 5;
//   Node gelu_1(string("gelu_1"), string("gelu"), vector<Node *>{});
//   Node gelu_0(string("gelu_0"), string("gelu"), vector<Node *>{});
//   Node softmax_0(string("softmax_0"), string("softmax"), vector<Node *>{});
//   Node layer_norm_0(string("layer_norm_0"), string("layer_norm"),
//                     vector<Node *>{&softmax_0, &gelu_1, &gelu_0});
//   Node matmul_0(string("matmul_0"), string("matmul"),
//                 vector<Node *>{&layer_norm_0});
//   Node input_0(string("input_0"), string("input"), vector<Node
//   *>{&matmul_0}); Graph graph(node_size, vector<Node *>{&input_0});
//   graph.print_prev_node_name(&input_0);

//   // init sub_graph
//   const int sub_node_size = 3;
//   Node sub_gelu_0(string("sub_gelu_0"), string("gelu"), vector<Node *>{});
//   Node sub_layer_norm_0(string("sub_layer_norm_0"), string("layer_norm"),
//                         vector<Node *>{&sub_gelu_0});
//   Node sub_matmul_0(string("sub_matmul_0"), string("matmul"),
//                     vector<Node *>{&sub_layer_norm_0});
//   Graph sub_graph(sub_node_size, vector<Node *>{&sub_matmul_0});
//   sub_graph.print_prev_node_name(&sub_matmul_0);

//   // match sub_graph
//   graph.sub_graph_match(&sub_graph);
//   graph.print_matches();
//   return 0;
// }
