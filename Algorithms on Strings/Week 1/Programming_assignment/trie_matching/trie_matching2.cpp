#include <bits/stdc++.h>

using namespace std;

map<char, int> id = {{'A', 0},{'C',1},{'G',2},{'T',3},{'$',4}};
vector<char> letter = {'A','C','G','T','$'};

vector<int> newNode(){
    vector<int> arr(5,-1);
    return arr;
}
vector<vector<int>> buildTrie(vector<string> &patterns){
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

int prefixMatching(vector<vector<int>> &Trie, string &text){
    int pos=0;
    char symbol=text[pos];
    int root=0;
    while(true){
        if(Trie[root][4]!=-1){
            return 1;
        }else if((Trie[root][id[symbol]]!=-1)&&(pos<text.length())){
            pos++;
            root=Trie[root][id[symbol]];
            symbol=text[pos];
        }else{
            return 0;
        }
    }
}
void trieMatching(vector<vector<int>> &Trie, string &text){
    int pos=0;
    while((text.substr(pos))!=""){
        string subtext=text.substr(pos);
        int match=prefixMatching(Trie, subtext);
        if(match){
            cout<<pos<<' ';
        }
        pos++;
    }
    cout<<'\n';
}
int main(){
    string text;
    cin>>text;
    int n;
    cin>>n;
    vector<string> patterns(n);
    string temp;
    for(int i=0; i<n;i++){
        cin>>temp;
        temp+="$";
        patterns[i]=temp;
    }
    vector<vector<int>> Trie=buildTrie(patterns);
    trieMatching(Trie, text);
}
