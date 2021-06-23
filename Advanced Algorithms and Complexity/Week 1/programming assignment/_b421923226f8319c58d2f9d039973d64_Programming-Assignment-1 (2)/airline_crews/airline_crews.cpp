#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <queue>

using std::vector;
using std::cin;
using std::cout;
using std::pair;
using std::queue;

class MaxMatching {
 public:
 vector<vector<bool>> adj_matrix;
 int n; int m;
  void Solve() {
    adj_matrix = ReadData();
    vector<int> matching = FindMatching();
    WriteResponse(matching);
  }
 private:
  vector<vector<bool>> ReadData(){
    int num_left, num_right;
    cin >> num_left >> num_right;
    n=num_left;
    m=num_right;
    vector<vector<bool>> input(num_left,vector<bool>(num_right));
    for (int i = 0; i < num_left; ++i)
      for (int j = 0; j < num_right; ++j) {
        int bit;
        cin >> bit;
        input[i][j] = (bit == 1);
      }
    return input;
  }

  void WriteResponse(const vector<int>& matching) {
    for (int i = 0; i < matching.size(); ++i) {
      if (i > 0)
        cout << " ";
      if (matching[i] == -1)
        cout << "-1";
      else
        cout << (matching[i] + 1);
    }
    cout << "\n";
  }
  bool DFS(int source, vector<int> &vis, vector<int> &match){
    for(int i=0; i<adj_matrix[0].size();i++){
      if((adj_matrix[source][i]==1)&&(vis[i]!=1)){
        vis[i]=1;
        if((match[i]==-1)||(DFS(match[i], vis, match))){
          match[i]=source;
          return true;
        }
      }
    }
    return false;
  }

  vector<int> FindMatching() {
    // Replace this code with an algorithm that finds the maximum
    // matching correctly in all cases.
    vector<int> match(m,-1);

    for(int i=0;i<n;i++){
      vector<int> vis(m,0);

      DFS(i, vis, match);
    }

    vector<int> result(n, -1);
    for(int i=0; i<m;i++){
      if(match[i]!=-1){
        result[match[i]]=i;
      }
    }

    return result;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  MaxMatching max_matching;
  max_matching.Solve();
  return 0;
}
