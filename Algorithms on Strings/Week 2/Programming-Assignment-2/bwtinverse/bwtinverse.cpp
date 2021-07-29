#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;

string InverseBWT(const string& bwt) {
  int n=bwt.length();
  string text = "";

  // Find the sorted first row
  string sbwt=bwt;
  sort(sbwt.begin(),sbwt.end());

  // Find the ocurrences of the letters in the first and last column
  map<char, int> pos;
  map<char, int> number;
  vector<int> ocurrence(n);
  for(int i=0; i<n;i++){

    // Check if the character c is already in the map
    map<char, int>::iterator it;
    it=pos.find(bwt[i]);
    if(it==pos.end()){

      // Find the first ocurrence of it in the first column
      for(int j=0; j<n;j++){
        if(sbwt[j]==bwt[i]){
          pos.insert(std::pair<char, int>(bwt[i], j));
          number.insert(std::pair<char, int>(bwt[i], 0));
        }
      }
    }
    ocurrence[i]=number[bwt[i]];
    number[bwt[i]]+=1;
  }

  // Find the inverse BWT word with the property seen in class
  text+=bwt[0];
  int curr=pos[bwt[0]]+ocurrence[0];
  while(sbwt[curr]!='$'){
    text+=bwt[curr];
    curr=pos[bwt[curr]]+ocurrence[curr];
  }
  std::reverse(text.begin(), text.end());
  return (text.substr(1)+"$");
}

int main() {
  string bwt;
  cin >> bwt;
  cout << InverseBWT(bwt) << endl;
  return 0;
}
