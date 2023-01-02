#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int *, int> buff_pool_;

class sharedPtr {
public:
  sharedPtr(int *ptr) : buff_(ptr) {
    if (buff_pool_.find(ptr) == buff_pool_.end()) {
      buff_pool_[ptr] = 1;
    } else {
      buff_pool_[ptr]++;
    }
  }

  sharedPtr(const sharedPtr &sptr) {
    if (buff_pool_.find(this->buff_) != buff_pool_.end()) {
      unrefPtr(this->buff_);
    }
    this->buff_ = sptr.buff_;
    buff_pool_[sptr.buff_]++;
  }

  void operator=(const sharedPtr &sptr) {
    if (buff_pool_.find(this->buff_) != buff_pool_.end()) {
      unrefPtr(this->buff_);
    }
    this->buff_ = sptr.buff_;
    buff_pool_[sptr.buff_]++;
  }

  ~sharedPtr() { unrefPtr(this->buff_); }

  void printBuffPool() {
    for (auto pool : buff_pool_) {
      cout << "buff addr: " << pool.first << ", use count: " << pool.second
           << endl;
    }
  }

private:
  // static unordered_map<void *, int> buff_pool_;

  int *buff_;

  void unrefPtr(int *ptr) {
    buff_pool_[ptr]--;
    if (buff_pool_[ptr] == 0) {
      buff_pool_.erase(ptr);
      delete ptr;
      ptr = nullptr;
    }
  }
};

template <typename T> class smartPtr {

private:
  T *buff_;
  atomic<int> *count_;

public:
  smartPtr(T *ptr) : buff_(ptr) { count_ = new atomic<int>(1); }

  smartPtr(const smartPtr &sptr) {
    buff_ = sptr.buff_;
    count_ = sptr.count_;
    (*count_)++;
  }

  smartPtr &operator=(const smartPtr &sptr) {
    if (this == &sptr)
      return *this;
    (count_)--;
    if (count_ == 0) {
      if (buff_) {
        delete buff_;
        buff_ = nullptr;
      }
      if (count_) {
        delete count_;
        count_ = nullptr;
      }
    }
    buff_ = sptr.buff_;
    count_ = sptr.count_;
    (*count_)++;
    return *this;
  }

  ~smartPtr() {
    (count_)--;
    if (count_ == 0) {
      if (buff_) {
        delete buff_;
        buff_ = nullptr;
      }
      if (count_) {
        delete count_;
        count_ = nullptr;
      }
    }
  }

  T &operator*() { return *buff_; }
  T *operator->() { return buff_; }
  int getCount() { return *count_; }
};

int main() {
  cout << "######## shared_ptr ######" << endl;
  sharedPtr p1(new int[100]);
  cout << "######## 1 ######" << endl;
  p1.printBuffPool();
  sharedPtr p2(new int[100]);
  cout << "####### 2 #######" << endl;
  p2.printBuffPool();
  sharedPtr p3(p1);
  cout << "####### 3 #######" << endl;
  p3.printBuffPool();
  p2 = p1;
  cout << "####### 4 #######" << endl;
  p3.printBuffPool();

  cout << "######## smart_ptr ######" << endl;
  smartPtr<int> s1(new int[100]);
  cout << "s1 count: " << s1.getCount() << endl;
  smartPtr<int> s2(new int[100]);
  cout << "s2 count: " << s2.getCount() << endl;
  smartPtr<int> s3(s1);
  cout << "s3 count: " << s3.getCount() << endl;
  s2 = s1;
  cout << "s2 count: " << s2.getCount() << endl;

  return 0;
}