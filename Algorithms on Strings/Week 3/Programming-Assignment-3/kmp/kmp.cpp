#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::string;
using std::vector;

vector<int> ComputePrefix(const string& p){
  int n=p.length();
  vector<int> s(n,0);
  s[0]=0;
  int border=0;
  for(int i=1; i<n;i++){
    while((border>0)&&(p[i]!=p[border])){
      border=s[border-1];
    }
    if(p[i]==p[border]){
      border++;
    }else{
      border=0;
    }
    s[i]=border;
  }
  return s;
}

vector<int> KMP(const string& p,const string& t){
  string S=p+"$"+t;
  vector<int> s=ComputePrefix(S);
  vector<int> result;
  for(int i=p.length()+1;i<S.length();i++){
    if(s[i]==p.length()){
      result.push_back(i-2*(p.length()));
    }
  }
  return result;
}

// Find all occurrences of the pattern in the text and return a
// vector with all positions in the text (starting from 0) where 
// the pattern starts in the text.
vector<int> find_pattern(const string& pattern, const string& text) {
  vector<int> result;
  // Implement this function yourself
  result=KMP(pattern, text);
  return result;
}

int main() {
  string pattern, text;
  cin >> pattern;
  cin >> text;
  vector<int> result = find_pattern(pattern, text);
  for (int i = 0; i < result.size(); ++i) {
    printf("%d ", result[i]);
  }
  printf("\n");
  return 0;
}
