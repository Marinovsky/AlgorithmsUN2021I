#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void explore(vector<vector<int>> &adj, vector<int> &vis, int curr){
    vis[curr]=1;
    for(int i=0; i<adj[curr].size();i++){
        //cout<<adj[curr][i]<<'\n';
        if(vis[adj[curr][i]]==0){
            explore(adj, vis, adj[curr][i]);
        }
    }
}

int number_of_components(vector<vector<int> > &adj, vector<int> &vis) {
  int res = 0;
  for(int i=0; i<adj.size();i++){
      if(vis[i]==0){
          res++;
          explore(adj, vis, i);
      }
  }
  return res;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<int> vis(n,0);
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj, vis);
}
