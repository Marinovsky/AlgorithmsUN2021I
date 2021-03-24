#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::min;
using std::cout;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  vector<vector<int>> D(str1.length()+1, std::vector<int>(str2.length()+1));
  int matches=0;int mismatchs=0;int insertion=0; int deletion=0;
  for(int i=0; i<str2.length()+1;i++){
        D[0][i]=i;
  }
  for(int i=0; i<str1.length()+1;i++){
        D[i][0]=i;
  }
  /*
  for(int i=0; i<str1.length()+1;i++){
        for(int j=0; j<str2.length()+1;j++){
            cout<<D[i][j]<<' ';
        }
        cout<<'\n';
  }
  */
  //cout<<"-----------------------------------------"<<'\n';
  for(int i=1; i<str1.length()+1;i++){
        for(int j=1; j<str2.length()+1;j++){
                insertion=D[i][j-1]+1;
                deletion=D[i-1][j]+1;
                mismatchs=D[i-1][j-1]+1;
                matches=D[i-1][j-1];
                if(str1[i-1]==str2[j-1]){
                    D[i][j]=min(insertion, min(deletion,matches));
                }else{
                    D[i][j]=min(insertion, min(deletion, mismatchs));
                }
        }
  }
  /*
  for(int i=0; i<str1.length()+1;i++){
        for(int j=0; j<str2.length()+1;j++){
            cout<<D[i][j]<<' ';
        }
        cout<<'\n';
  }
  */
  return D[str1.length()][str2.length()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
