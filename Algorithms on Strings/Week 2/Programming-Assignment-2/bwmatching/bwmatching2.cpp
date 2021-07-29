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
using std::pair;

class BWT{
    private:
        vector<vector<int>> count; // Number of ocurrences of each symbol in the last column
        vector<int> Find; // First ocurrence of a symbol in sbwt
        string bwt; // Last column
        string sbwt; // First column
        int n; // Length of the string
        map<char, int> dic={{'$',0},{'A',1},{'C',2},{'G',3},{'T',4}};
    public:
        BWT(const string& bwt_){
            bwt=bwt_;
            n=bwt_.length();
            sbwt=bwt_;
            sort(sbwt.begin(), sbwt.end());
            count=vector<vector<int>>(n+1,vector<int>(5,0));
            Find=vector<int>(5,0);
            buildCount();
            buildFind();
        }
        void buildCount(){
            for(int i=1;i<n+1;i++){
                count[i]=count[i-1];
                count[i][dic[bwt[i-1]]]++;
            }
        }
        void buildFind(){
            map<char, int> found;
            found['$']=0;
            found['A']=0;
            found['C']=0;
            found['G']=0;
            found['T']=0;
            int char_found=0;
            for(int i=0; i<n;i++){
                if(char_found==5){
                    break;
                }
                if(found[sbwt[i]]==0){
                    
                    found[sbwt[i]]++;
                    Find[dic[sbwt[i]]]=i;
                    char_found++;
                }
            }
        }
        void print(){
            cout<<"$ A C G T"<<'\n';
            for(int i=0; i<n+1;i++){
                for(int j=0; j<5;j++){
                    cout<<count[i][j]<<' ';
                }
                cout<<'\n';
            }
        }
        int matching(string pattern){
            int top=0;
            int bottom=n-1;
            char symbol;
            int i=0;
            while(top<=bottom){
                i++;
                if(pattern!=""){
                    symbol= pattern[pattern.length()-1];
                    pattern.erase(pattern.length()-1,1);
                    if(std::find(std::begin(bwt)+top, std::begin(bwt)+bottom+1,symbol)!=std::begin(bwt)+bottom+1){
                        top=Find[dic[symbol]]+count[top][dic[symbol]];
                        bottom=Find[dic[symbol]]+count[bottom+1][dic[symbol]]-1;
                    }else{
                        return 0;
                    }               
                }else{
                    return bottom-top+1;
                }
            }
            return 0;
        }
        string reverse(){
            map<char, int> pos;
            map<char, int> number;
            vector<int> ocurrence(n);
            string text="";
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
        string fColumn(){
            return sbwt;
        }
};


int main() {

    string bwt;
    cin >> bwt;
    int n;
    cin>>n;
    vector<string> patterns(n);
    for(int i=0; i<n;i++){
        cin>>patterns[i];
    }
    BWT myBWT(bwt);
    vector<int> result;
    for(auto pattern: patterns){
        result.push_back(myBWT.matching(pattern));
    }
    for(int x: result){
        cout<<x<<' ';
    }
    cout<<'\n';
    return 0;
}
