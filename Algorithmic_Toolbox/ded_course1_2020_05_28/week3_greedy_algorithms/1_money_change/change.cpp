#include <iostream>

int get_change(int m) {
  int result=0;
  int ten_coins=m/10;
  int five_coins=(m%10)/5;
  int one_coins=((m%10)%5);
  result=ten_coins+five_coins+one_coins;
  return result;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
  //std::cout<< 2%10 << '\n';
}
