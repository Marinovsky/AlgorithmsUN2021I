#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  std::sort(a.begin(),a.end());
  int count=0;
  int pivot=a[0];
  for(auto c:a){
    if(c==pivot){
        count++;
    }else{
        if(count>(a.size()/2)){
            return 1;
        }else{
            count=1;
            pivot=c;
        }
    }
  }
  if(count>(a.size()/2)){
    return 1;
  }else{
    return 0;
  }
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << get_majority_element(a, 0, a.size()) << '\n';
}
