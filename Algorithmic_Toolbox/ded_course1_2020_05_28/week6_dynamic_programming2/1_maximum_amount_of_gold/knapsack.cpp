#include <iostream>
#include <vector>

using std::vector;
using std::cout;
int optimal_weight(int W, vector<int> &w) {
    vector<vector<int>> val(w.size(), vector<int>(W+1));
    int temp;
    for(int i=1; i<w.size();i++){
        for(int j=1; j<W+1;j++){
            val[i][j]=val[i-1][j];
            if(w[i]<=j){
                temp=val[i-1][j-w[i]]+w[i];
                if(val[i][j]<temp){
                    val[i][j]=temp;
                }
            }
        }
    }

    int i=w.size()-1;
    int j=W;
    while(i>0){
        cout<<i<<' '<<j<<' '<<w[i]<<' ';
        if((w[i]<j)){
            if(val[i-1][j]<(val[i-1][j-w[i]]+w[i])){
                j=j-w[i];
                w[i]=0;
                i=i-1;
                cout<<":)"<<'\n';
            }else{
                i=i-1;
                cout<<":v"<<'\n';
            }
        }else{
            i=i-1;
            cout<<":v"<<'\n';
        }
    }
    return val[w.size()-1][W];
}

int optimal_weight2(int W, vector<int> &w) {
    vector<vector<int>> val(w.size()+1, vector<int>(W+1));
    int temp;
    for(int i=1; i<w.size()+1;i++){
        for(int j=1; j<W+1;j++){
            val[i][j]=val[i-1][j];
            if(w[i]<=j){
                temp=val[i-1][j-w[i]]+w[i];
                if(val[i][j]<temp){
                    val[i][j]=temp;
                }
            }
        }
    }
    int i=w.size()-1;
    int j=W;
    while(i>0){
        cout<<i<<' '<<j<<'\n';
        if((w[i]<j)){
            if((val[i-1][j]<(val[i-1][j-w[i]]+w[i]))&&(w[i]<j)){
                j=j-w[i];
                w[i]=0;
                i=i-1;
                cout<<":)"<<'\n';
            }else{
                i=i-1;
            }
        }else{
            i=i-1;
        }
    }
    return val[w.size()][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n+1, 0);
  for (int i = 1; i < n+1; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
