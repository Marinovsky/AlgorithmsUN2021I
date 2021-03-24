#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <stdlib.h>
#include <limits>
#define LLONG_MAX 9223372036854775807;
#define LLONG_MIN -9223372036854775807;

using std::vector;
using std::string;
using std::max;
using std::min;
using std::cout;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}
std::pair<long long, long long> MinAndMax(int i, int j, vector<vector<long long>> M, vector<vector<long long>> m, const string op){
    long long min=LLONG_MAX;
    long long max=LLONG_MIN;
    long long a;long long b;long long c;long long d;
    for(int k=i;k<=j-1;k++){
        a=eval(M[i][k],M[k+1][j], op[k-1]);
        b=eval(M[i][k],m[k+1][j], op[k-1]);
        c=eval(m[i][k],M[k+1][j], op[k-1]);
        d=eval(m[i][k],m[k+1][j], op[k-1]);
        min=std::min(min, std::min(a, std::min(b, std::min(c, d))));
        max=std::max(max, std::max(a, std::max(b, std::max(c, d))));
    }
    return {min, max};
}

long long get_maximum_value(const string &numbers, const string &op){
  //write your code here
  int n=numbers.length()+1;
  vector<vector<long long>> M(n, vector<long long>(n));
  vector<vector<long long>> m(n, vector<long long>(n));
  for(int i=1;i<n;i++){
    M[i][i]=numbers[i-1]-'0';
    m[i][i]=numbers[i-1]-'0';
  }
  int j;
  for(int s=1;s<n-1;s++){
    for(int i=1;i<n-s;i++){
        j=i+s;
        std::pair<long long, long long> res=MinAndMax(i,j, M,m,op);
        m[i][j]=res.first;
        M[i][j]=res.second;
    }
  }
/*
  for(int i=1;i<n;i++){
    for(int j=1;j<n;j++){
        cout<<M[i][j]<<' ';
    }
    cout<<'\n';
  }

  for(int i=1;i<n;i++){
    for(int j=1;j<n;j++){
        cout<<m[i][j]<<' ';
    }
    cout<<'\n';
  }
*/
  return M[1][n-1];
}

int main() {
  string s;
  std::cin >> s;
  string numbers="";
  string op="";
  for(char c:s){
    if((c=='+')||(c=='*')||(c=='-')){
        op+=c;
    }else{
        numbers+=c;
    }
  }
  std::cout << get_maximum_value(numbers, op) << '\n';
}
