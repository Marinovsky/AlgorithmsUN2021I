#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}
int gcd(int a, int b){
    if(b==0){
        return a;
    }else{
        int res=a%b;
        //std::cout<<b<<' '<<res<<'\n';
        return gcd(b,res);
    }
}

int main() {
  int a, b;
  // test
/*
  while(true){
    int c,d;
    c=rand()%1000000+1;
    d=rand()%1000000+1;
    std::cout<<c<<' '<<d<<'\n';
    int res1, res2;
    res1=gcd(std::max(c,d), std::min(c,d));
    res2=gcd_naive(std::max(c,d), std::min(c,d));
    if(res1!=res2){
        std::cout<<"Wrong answer: "<<res1<<' '<<res2<<'\n';
        break;
    }else{
        std::cout<<"OK"<<'\n';
    }
  }
*/
  std::cin >> a >> b;
  std::cout << gcd(a, b) << std::endl;

  return 0;
  }
