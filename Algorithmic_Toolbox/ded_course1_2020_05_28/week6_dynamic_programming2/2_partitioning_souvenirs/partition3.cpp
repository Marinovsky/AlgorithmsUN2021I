#include <iostream>
#include <vector>
#include <numeric>

using std::vector;
using std::cout;

bool optimal_weight(int W, vector<int> &w) {
    vector<vector<int>> val(w.size(), vector<int>(W+1));
    bool check=false;
    int temp;
    int i; int j;
    for(i=1; i<w.size();i++){
        for(j=1; j<W+1;j++){
            val[i][j]=val[i-1][j];
            if(w[i]<=j){
                temp=val[i-1][j-w[i]]+w[i];
                if(val[i][j]<temp){
                    val[i][j]=temp;
                }
                if(val[i][j]==W){
                    check=true;
                    break;
                }
            }
        }
        if(check){
            break;
        }
    }
    if(i==w.size()){

    }
    cout<<i<<' '<<j<<'\n';

    while(i>0){
        cout<<i<<' '<<j<<' '<<w[i]<<'\n';
        cout<<val[i-1][j]<<' '<<(val[i-1][j-w[i]]+w[i])<<' ';
        if((w[i]<=j)){
            if(val[i-1][j]<=(val[i-1][j-w[i]]+w[i])){
                j=j-w[i];
                w[i]=0;
                i=i-1;
                cout<<":)"<<'\n';
            }else{
                i=i-1;
                cout<<":v"<<'\n';
            }

            i=i-1;
        }else{
            i=i-1;
            cout<<":v"<<'\n';
        }
    }
    return check;
}


int partition3(vector<int> &A) {
  vector<int> a=A;
  int sum1=0;int sum2=0;int sum3=0;
  bool res1;int res2;int res3;
  sum1=std::accumulate(a.begin(), a.end(), 0);
  cout<<sum1<<'\n';
  if(sum1%3==0){
      res1=optimal_weight(sum1/3, a);
      cout<<res1<<'\n';
      for(auto c: a){
        cout<<c<<' ';
      }
      cout<<'\n';
      cout<<"--------------------------------------------"<<'\n';
      if(res1){
          sum2=std::accumulate(a.begin(), a.end(), 0);
          cout<<sum2<<'\n';
          if(sum2==(sum1/3)*2){
              res2=optimal_weight(sum1/3, a);
              cout<<res2<<'\n';
              for(auto c: a){
                cout<<c<<' ';
              }
              cout<<'\n';
              cout<<"--------------------------------------------"<<'\n';
              if(res2){
                  sum3=std::accumulate(a.begin(), a.end(), 0);
                  cout<<sum3<<'\n';
                  if(sum3==sum1/3){
                    res3=optimal_weight(sum1/3, a);
                    if(res3){
                        return 1;
                    }
                  }
              }
          }
      }
  }
  return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n+1,0);
  for (size_t i = 1; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
