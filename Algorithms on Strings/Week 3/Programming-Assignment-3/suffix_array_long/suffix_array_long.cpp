#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::string;
using std::vector;
using std::map;

map<char, int> id = {{'$',0},{'A',1},{'C',2},{'G',3},{'T',4}};

vector<int> SortCharacters(const string& s){
  int n=s.length();
  vector<int> order(n);
  vector<int> count(5,0);
  for(char c: s){
    count[id[c]]++;
  }
  for(int i=1; i<5;i++){
    count[i]+=count[i-1];
  }
  for(int i=n-1;i>=0;i--){
    char c=s[i];
    count[id[c]]-=1;
    order[count[id[c]]]=i;
  }
  return order;
}

vector<int> ComputeCharClasses(const string &s, vector<int>& order){
  int n=s.length();
  vector<int> class_(n);
  class_[order[0]]=0;
  for(int i=1; i<n;i++){
    if(s[order[i]]!=s[order[i-1]]){
      class_[order[i]]=class_[order[i-1]]+1;
    }else{
      class_[order[i]]=class_[order[i-1]];
    }
  }
  return class_;
}
vector<int> SortDoubled(const string& s, int L, vector<int>& order, vector<int>& class_){
  int n=s.length();
  vector<int> newOrder(n);
  vector<int> count(n,0);
  int start;
  int cl;
  for(int i=0; i<n;i++){
    count[class_[i]]++;
  }
  for(int i=1; i<n;i++){
    count[i]+=count[i-1];
  }
  for(int i=n-1;i>=0;i--){
    start=(order[i]-L+n)%n;
    cl=class_[start];
    count[cl]-=1;
    newOrder[count[cl]]=start;
  }
  return newOrder;
}

vector<int> UpdateClasses(vector<int>& order, vector<int>& class_, int L){
  int n=order.size();
  vector<int> newClass(n);
  newClass[order[0]]=0;
  int cur, prev, mid, midprev;
  for(int i=1; i<n;i++){
    cur=order[i];prev=order[i-1];
    mid=(cur+L)%n;midprev=(prev+L)%n;
    if((class_[cur]!=class_[prev])||(class_[mid]!=class_[midprev])){
      newClass[cur]=newClass[prev]+1;
    }else{
      newClass[cur]=newClass[prev];
    }
  }
  return newClass;
}

// Build suffix array of the string text and
// return a vector result of the same length as the text
// such that the value result[i] is the index (0-based)
// in text where the i-th lexicographically smallest
// suffix of text starts.
vector<int> BuildSuffixArray(const string& text) {
  vector<int> order=SortCharacters(text);
  vector<int> class_=ComputeCharClasses(text, order);
  int L=1;
  while(L<text.length()){
    order=SortDoubled(text, L, order, class_);
    class_=UpdateClasses(order, class_, L);
    L*=2;
  }
  return order;
}

int main() {
  string text;
  cin >> text;
  vector<int> suffix_array = BuildSuffixArray(text);
  for (int i = 0; i < suffix_array.size(); ++i) {
    cout << suffix_array[i] << ' ';
  }
  cout << endl;
  return 0;
}
