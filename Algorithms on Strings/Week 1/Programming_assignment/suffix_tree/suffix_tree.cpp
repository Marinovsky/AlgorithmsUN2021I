#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

map<char, int> id = {{'A', 0},{'C',1},{'G',2},{'T',3},{'$',4}};
vector<char> letter = {'A','C','G','T','$'};

vector<int> newNode(){
    vector<int> arr(5,-1);
    return arr;
}
// Build a suffix tree of the string text and return a vector
// with all of the labels of its edges (the corresponding 
// substrings of the text) in any order.
vector<vector<int>> buildTrie(vector<string> patterns){
    vector<vector<int>> Trie;
    int count=0;
    int curr;
    Trie.push_back(newNode());
    for(auto pattern: patterns){
        curr=0;
        for(char s: pattern){
            if(Trie[curr][id[s]]!=-1){
                curr=Trie[curr][id[s]];
            }else{
                Trie.push_back(newNode());
                count++;
                Trie[curr][id[s]]=count;
                curr=count;      
            }
        }

    }
    return Trie;
}

vector<string> ComputeSuffixTreeEdges(const string& text) {
  vector<string> result;
  int n=text.length();
  // Implement this function yourself
  vector<string> suffixes(n);
  string temp;
  for(int i=0; i<n;i++){
    temp=text.substr(i);
    suffixes[i]=temp;
  }
  vector<vector<int>> Trie=buildTrie(suffixes);
  for(int i=0; i<Trie.size();i++){
        for(int j=0;j<4;j++){
            if(Trie[i][j]!=-1){
                cout<<i<<"->"<<Trie[i][j]<<":"<<letter[j]<<'\n';
            }   
        }
  }
  return result;
}

int main() {
  string text;
  cin >> text;
  vector<string> edges = ComputeSuffixTreeEdges(text);
  /*
  for (int i = 0; i < edges.size(); ++i) {
    cout << edges[i] << endl;
  }
  */
  return 0;
}
