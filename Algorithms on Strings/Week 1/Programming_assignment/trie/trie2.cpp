#include <bits/stdc++.h>

using namespace std;

map<char, int> id = {{'A', 0},{'C',1},{'G',2},{'T',3},{'$',4}};
vector<char> letter = {'A','C','G','T','$'};

vector<int> newNode(){
    vector<int> arr(5,-1);
    return arr;
}
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

int main(){
    int n;
    cin>>n;
    vector<string> patterns(n);
    string temp;
    for(int i=0; i<n;i++){
        cin>>temp;
        //temp+="$";
        patterns[i]=temp;
    }
    vector<vector<int>> Trie=buildTrie(patterns);
    for(int i=0; i<Trie.size();i++){
        for(int j=0;j<4;j++){
            if(Trie[i][j]!=-1){
                cout<<i<<"->"<<Trie[i][j]<<":"<<letter[j]<<'\n';
            }   
        }
    }
}