#include <iostream>
#include <vector>

using std::cout;
using std::vector;
int get_change(int m) {
  //write your code here
  vector<int> v(m+1,0);
  vector<int> coins={1,3,4};
  int num=0;
  for(int i=1;i<m+1;i++){
      v[i]=m+1;
      for(auto c: coins){
          if(i>=c){
              num=v[i-c]+1;
              if(num<v[i]){
                  v[i] = num;
              }
          }
      }
  }
  return v[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
