#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <utility>
#include <set>

using std::vector;
using std::cin;
using std::cout;
using std::pair;
using std::make_pair;
using std::min_element;
using std::max_element;

class StockCharts {
 public:
 vector<vector<int>> stock_data;
  void Solve() {
    stock_data = ReadData();
    int result = MinCharts(stock_data);
    WriteResponse(result);
  }

 private:
  vector<vector<int>> ReadData() {
    int num_stocks, num_points;
    cin >> num_stocks >> num_points;
    vector<vector<int>> stock_data(num_stocks, vector<int>(num_points));
    for (int i = 0; i < num_stocks; ++i)
      for (int j = 0; j < num_points; ++j) {
        cin >> stock_data[i][j];
      }
    return stock_data;
  }

  void WriteResponse(int result) {
    cout << result << "\n";
  }

  vector<vector<int>> MakeMatrix(){
    int n= stock_data.size();
    int m= stock_data[0].size();
    vector<vector<int>> adj_matrix(n, vector<int>(n,0));
    for(int i=0; i<n;i++){
      for(int j=0; j<n;j++){
        bool flag=true;
        for(int t=0; t<m;t++){
          if(stock_data[i][t]<=stock_data[j][t]){
            flag=false;
          }
        }
        if(flag){
          adj_matrix[i][j]=1;
        }
      }
    }
    return adj_matrix;
  }

  bool DFS(int head, vector<vector<int>> adj_matrix, vector<int> &vis, vector<int> &match){
    for(int i=0; i<adj_matrix.size();i++){
      if((adj_matrix[head][i]!=0)&&(vis[i]==0)){
        vis[i]=1;
        if((match[i]==-1)||(DFS(match[i], adj_matrix, vis, match))){
          match[i]=head;
          return true;
        }
      }
    }
    return false;
  }

  int MinCharts(const vector<vector<int>>& stock_data) {
    // Replace this incorrect greedy algorithm with an
    // algorithm that correctly finds the minimum number
    // of charts on which we can put all the stock data
    // without intersections of graphs on one chart.
    vector<vector<int>> adj_matrix = MakeMatrix();
    /*
    for(int i=0; i<adj_matrix.size();i++){
      for(int j=0; j<adj_matrix.size();j++){
        cout<<adj_matrix[i][j]<<" ";
      }
      cout<<"\n";
    }
    */
    vector<int> match (adj_matrix.size(),-1);
    vector<int> vis (adj_matrix.size(),0);

    for(int i=0; i<adj_matrix.size();i++){
      DFS(i, adj_matrix, vis, match);
      std::fill(vis.begin(), vis.end(), 0);
    }
    vector<int> result (adj_matrix.size(),-1);

    for(int i=0; i<match.size();i++){
      if(match[i]!=-1){
        result[match[i]]=i;
      }
    }

    int solution=0;
    for(int i=0; i<result.size();i++){
      if(result[i]==-1){
        solution++;
      }
    }

    
    return solution;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  StockCharts stock_charts;
  stock_charts.Solve();

  return 0;
}
