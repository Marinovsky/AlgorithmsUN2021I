#include <bits/stdc++.h>
using namespace std;
ofstream coutt("out.txt");
class SAT{
    private:
        int n;
        int m;
        vector<vector<int>> g;
        vector<string> clauses;
        int count;
    public:
        SAT(vector<vector<int>> g_, int m_){
            g=g_;
            n=g_.size();
            m=m_;
        }
        int varnum(int i, int j){
            return n*(i-1)+j;
        }
        void belongs_path(){
            for(int i=1; i<=n;i++){
                string temp="";
                for(int j=1; j<=n;j++){
                    //coutt<<varnum(i,j)<<" ";
                    temp+=to_string(varnum(i,j))+" ";
                }
                //coutt<<"0"<<'\n';
                temp+="0";
                clauses.push_back(temp);
                just_once(i);
            }
        }
        void just_once(int i){
            for(int j=1; j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    //coutt<<"-"<<varnum(i,j)<<" -"<<varnum(i,k)<<" 0"<<'\n';
                    string temp="-"+to_string(varnum(i,j))+" -"+to_string(varnum(i,k))+" 0";
                    clauses.push_back(temp);
                }
            }
        }
        void pos_path(){
            for(int j=1;j<=n;j++){
                string temp="";
                for(int i=1; i<=n;i++){
                    //coutt<<varnum(i,j)<<" ";
                    temp+=to_string(varnum(i,j))+" ";
                }
                //coutt<<"0"<<'\n';
                temp+="0";
                clauses.push_back(temp);
                same_pos(j);
            }
        }
        void same_pos(int j){
            for(int i=1;i<=n;i++){
                for(int k=i+1;k<=n;k++){
                    //coutt<<"-"<<varnum(i,j)<<" -"<<varnum(k,j)<<" 0"<<'\n';
                    string temp="-"+to_string(varnum(i,j))+" -"+to_string(varnum(k,j))+" 0";
                    clauses.push_back(temp);
                }
            }
        }
        void connected(){
            for(int i=1; i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(g[i-1][j-1]==0){
                        for(int k=1;k<=n-1;k++){
                            //coutt<<"-"<<varnum(i,k)<<" -"<<varnum(j,k+1)<<" 0"<<'\n';
                            string temp="-"+to_string(varnum(i,k))+" -"+to_string(varnum(j,k+1))+" 0";
                            clauses.push_back(temp);
                        }
                    }
                }
            }
        }
        void print(){
            cout<<clauses.size()<<" "<<(n*n)<<'\n';
            for(auto s:clauses){
                cout<<s<<'\n';
            }
        }
        void solve(){
            belongs_path();
            pos_path();
            connected();
            print();
        }
};


int main() {
    int n, m;
    cin >> n >> m;
    int u,v;
    vector<vector<int>> g(n,vector<int>(n,0));
    for(int i=0; i<m;i++){
        cin>>u>>v;
        g[u-1][v-1]=1;
        g[v-1][u-1]=1;
    }
    SAT problem(g,m);
    problem.solve();
    return 0;
}
