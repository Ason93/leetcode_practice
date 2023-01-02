#include <iostream>
using namespace std;

/*
Question:
Write a string class.
mystring s1();
mystring s2("hello");
mystring s3(s2);
s1=s2;
*/

class mystring {
public:
  mystring() = default;
  ~mystring() { delete[] data_; }
  explicit mystring(char *pdata) {
    if (pdata == nullptr) {
      this->data_ = nullptr;
    } else {
      this->data_ = new char[strlen(pdata) + 1];
      strcpy(this->data_, pdata);
    }
  }
  explicit mystring(const mystring &str) {
    if (str.data_ == nullptr) {
      this->data_ = nullptr;
    } else {
      this->data_ = new char[strlen(str.data_) + 1];
      strcpy(this->data_, str.data_);
    }
  }

  mystring &operator=(const mystring &str) {
    if (this != &str) {
      mystring strtmp(str);
      this->data_ = strtmp.data_;

      // mystring strtmp(str);
      // char *ptmp = strtmp.data_;
      // strtmp.data_ = this->data_;
      // this->data_ = ptmp;
    }
    return *this;
  }

  void print() {
    if (this->data_ != nullptr) {
      cout << data_ << endl;
    } else {
      cout << "Data is empty!" << endl;
    }
  }

private:
  char *data_;
};

int main() {
  mystring s1;
  mystring s2("hello");
  mystring s3(s2);
  s1 = s2;
  s1.print();
  s2.print();
  s3.print();
  return 0;
}