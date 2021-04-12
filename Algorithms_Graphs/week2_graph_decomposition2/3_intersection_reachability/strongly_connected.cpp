#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void DFS(vector<vector<int> > adj, vector<int> &vis, vector<int> &post, int x){
    vis[x]=1;
    for(int i=0; i<adj[x].size();i++){
        if(vis[adj[x][i]]==0){
            DFS(adj, vis, post,adj[x][i]);
        }
    }
    post.push_back(x);
}
void DEL(vector<vector<int> > adj, vector<int> &del, int x){
    del[x]=1;
    for(int i=0; i<adj[x].size();i++){
        if(del[adj[x][i]]==0){
            DEL(adj, del, adj[x][i]);
        }
    }
}

int number_of_strongly_connected_components(vector<vector<int> > adj, vector<vector<int>> rev) {
  int result = 0;
  vector<int> vis(adj.size(), 0);
  vector<int> del(adj.size(), 0);
  vector<int> post;
  for(int i=0; i<adj.size();i++){
    if(vis[i]==0){
        DFS(rev, vis, post,

            i);
    }
  }
  std::reverse(post.begin(), post.end());
  for(auto c: post){
    if(del[c]==0){
        DEL(adj, del, c);
        result++;
    }
  }

  //write your code here
  return result;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > rev(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    rev[y - 1].push_back(x - 1);
  }
  std::cout << number_of_strongly_connected_components(adj, rev);
}
