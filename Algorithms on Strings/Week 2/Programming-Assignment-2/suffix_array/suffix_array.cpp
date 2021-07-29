#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::string;
using std::vector;

// Build suffix array of the string text and
// return a vector result of the same length as the text
// such that the value result[i] is the index (0-based)
// in text where the i-th lexicographically smallest
// suffix of text starts.
vector<pair<string, int>> BuildSuffixArray(const string& text) {
  int n=text.length();
  string suffix;
  vector<pair<string, int>> arr_suffix(n);
  for(int i=0; i<n;i++){
    suffix=text.substr(i);
    arr_suffix[i]=pair<string, int>(suffix, i);
  }
  sort(arr_suffix.begin(), arr_suffix.end());

  return arr_suffix;
}

int main() {
  string text;
  cin >> text;
  vector<pair<string, int>> suffix_array = BuildSuffixArray(text);
  for (auto x: suffix_array) {
    cout << x.second << ' ';
  }
  cout << endl;
  return 0;
}
