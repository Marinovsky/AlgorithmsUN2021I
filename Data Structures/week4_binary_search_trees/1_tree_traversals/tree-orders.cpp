#include <iostream>
#include <vector>
#include <algorithm>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::vector;
using std::ios_base;
using std::cin;
using std::cout;
using std::endl;

class TreeOrders {
  int n;
  vector <int> key;
  vector <int> left;
  vector <int> right;

public:
  void read();
  void pre_order(int n);
  void in_order(int n);
  void post_order(int n);
  void driver(int k);
};
void TreeOrders::read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }

void TreeOrders::in_order(int k) {
    // Finish the implementation
    // You may need to add a new recursive method to do that
    if(k==-1){
        cout<<"";
    }else{
        in_order(left[k]);
        cout<<key[k]<<" ";
        in_order(right[k]);
    }
}

void TreeOrders::pre_order(int k) {
    // Finish the implementation
    // You may need to add a new recursive method to do that
    if(k==-1){
        cout<<"";
    }else{
        cout<<key[k]<<" ";
        pre_order(left[k]);
        pre_order(right[k]);
    }
}

void TreeOrders::post_order(int k) {
    // Finish the implementation
    // You may need to add a new recursive method to do that
    if(k==-1){
        cout<<"";
    }else{
        post_order(left[k]);
        post_order(right[k]);
        cout<<key[k]<<" ";
    }
}

void TreeOrders::driver(int k){
    in_order(k);
    cout<<endl;
    pre_order(k);
    cout<<endl;
    post_order(k);
}


int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  t.driver(0);
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

  return main_with_large_stack_space();
}

