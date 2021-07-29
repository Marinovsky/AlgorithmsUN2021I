#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

string BWT(const string& text) {
  int n=text.length();
  string result = "";
  string temp;
  vector<string> cyclic(n);
  // Compute the cyclic rotations
  for(int i=0; i<n;i++){
    temp=text.substr(i) + text.substr(0,i);
    cyclic[i]=temp;
  }
  // Sort the cyclyc rotations
  std::sort(cyclic.begin(),cyclic.end());
  // Extract last column
  for(int i=0; i<n;i++){
    result+=cyclic[i][n-1];
  } 

  return result;
}

int main() {
  string text;
  cin >> text;
  cout << BWT(text) << endl;
  return 0;
}