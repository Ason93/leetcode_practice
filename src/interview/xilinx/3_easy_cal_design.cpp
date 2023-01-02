#include <iostream>
#include <unordered_map>

using namespace std;

// class Expr {
// public:
//   Expr(int res) : res_(res) {}
//   Expr operator+(const int num) {
//     int res = this->res_ + num;
//     return Expr(res);
//   }
//   const int eval() const { return res_; }

// private:
//   int res_;
// };

// class Var {
// public:
//   Var(int val) : val_(val) {}
//   Expr operator+(const Var &v) {
//     int res = this->val_ + v.getVal();
//     return Expr(res);
//   }
//   const int getVal() const { return val_; }

// private:
//   int val_;
// };

// int main() {
//   Var v1(1), v2(2);
//   Expr e1 = v1 + v2;
//   Expr e2 = e1 + 1;
//   int res = e2.eval();
//   cout << res << endl;
//   return 0;
// }

class Expr {
public:
  Expr(string expr_str) : expr_str_(expr_str) {}
  Expr operator+(const int num) {
    string res_expr_str = this->getExprStr() + to_string(num);
    return Expr(res_expr_str);
  }
  int eval(unordered_map<string, int> &m) {
    int res = 0;
    for (int i = 0; i < expr_str_.size(); ++i) {
      if (expr_str_[i] == 'x') {
        res += m["x"];
      } else if (expr_str_[i] == 'y') {
        res += m["y"];
      } else if (expr_str_[i] == '+') {
        continue;
      } else {
        string num_str;
        while (i < expr_str_.size()) {
          if (expr_str_[i] >= '0' && expr_str_[i] <= '9') {
            num_str += expr_str_[i];
          } else {
            break;
          }
          ++i;
        }
        res += atoi(num_str.c_str());
      }
    }
    return res;
  }
  const string getExprStr() const { return expr_str_; }

private:
  string expr_str_;
};

class Var {
public:
  Var(string str) : str_(str) {}
  Expr operator+(const Var &v) {
    string expr_str = this->getStr() + "+" + v.getStr();
    return Expr(expr_str);
  }
  const string getStr() const { return str_; }

private:
  string str_;
};

int main() {
  Var v1("x"), v2("y");
  Expr e1 = v1 + v2;
  Expr e2 = e1 + 16;
  unordered_map<string, int> m = {{"x", 1}, {"y", 2}};
  int res = e2.eval(m);
  cout << res << endl;
  return 0;
}