#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
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
long long lcm(int a, int b){
    long long d=gcd(a,b);
    long long prod=((long long)a)*((long long)b);
    long long res=prod/d;
    return res;
}

int main() {
 /*
    // Test case
    while(true){
    int c,d;
    c=rand()%1000+1;
    d=rand()%1000+1;
    std::cout<<c<<' '<<d<<'\n';
    int res1, res2;
    res1=lcm(std::max(c,d), std::min(c,d));
    res2=lcm_naive(std::max(c,d), std::min(c,d));
    if(res1!=res2){
        std::cout<<"Wrong answer: "<<res1<<' '<<res2<<'\n';
        break;
    }else{
        std::cout<<"OK"<<'\n';
    }
  }
 */
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;

  return 0;
}
