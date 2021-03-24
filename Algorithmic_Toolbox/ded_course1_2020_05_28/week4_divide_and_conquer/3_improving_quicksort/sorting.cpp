#include <iostream>
#include <vector>
#include <cstdlib>
#include <utility>
#include <algorithm>

using std::vector;
using std::swap;
using std::pair;

pair<int, int> partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  int k = l;
  //std::cout << "par" << '\n';
  for (int i = l + 1; i <= r; i++) {
    //std::cout << "it: " << i <<'\n';
    if (a[i] < x) {
      if(j!=k){
        j++;
      }
      swap(a[j], a[i]);
      k++;
      swap(a[i], a[k]);
    }else if(a[i]==x) {
        if(a[j]<=a[i]){
           k++;
        }
        swap(a[i], a[k]);
    }
    /*
    for(auto c: a){
        std::cout << c <<' ';
      }
    std::cout << '\n';
    */
  }
  //swap(a[l], a[j]);
  /*
  std::cout << '&' << '\n';
  for(auto c : a){
    std::cout << c << ' ';
  }
  std::cout << '\n';
  std::cout << j << ' ' << k << '\n';
  */
  return {j+1, k};
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  //std::cout << "pivot: " << a[k] << ' ' << k << '\n';
  swap(a[l], a[k]);
  pair<int, int> m = partition2(a, l, r);

  randomized_quick_sort(a, l, m.first -1);
  randomized_quick_sort(a, m.second+1, r);
}

int main() {
  /*
  while(true){
    int n=rand()%10+1;
    vector<int> a(n);
    vector<int> b(n);
    for (size_t i = 0; i < a.size(); ++i) {
        a[i]=rand()%10;
        b[i]=a[i];
    }
    //std::cout << "--------------------" << '\n';
    for(auto c: b){
        std::cout << c << ' ';
    }
    std::cout << '\n';
    randomized_quick_sort(a, 0, a.size() - 1);
    std::sort(b.begin(), b.end());
    bool equal=true;
    for(int i=0; i<n;i++){
        std::cout << a[i] << ' ';
        if(a[i]!=b[i]){
            equal=false;
        }
    }
    std::cout << '\n';
    for(auto c: b){
        std::cout << c << ' ';
    }
    std::cout << '\n';
    if(!equal){
        std::cout << "Wrong answer" <<'\n';
        break;
    }else{
        std::cout << "ok" << '\n';
    }
    std::cout << "--------------------" << '\n';
  }
  */
  ///*
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
  //*/
}
