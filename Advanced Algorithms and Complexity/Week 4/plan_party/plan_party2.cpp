#include <bits/stdc++.h>

#if defined(__unix__) || defined(__APPLE__)

#include <sys/resource.h>

#endif

using namespace std;

void dfs(vector<vector<int>> &g, vector<vector<int>> &tree, vector<int> &vis, int head){
    vis[head]=1;
    for(auto u: g[head]){
        if(vis[u]==0){
            tree[head].push_back(u);
            dfs(g,tree, vis, u);
        }
    }
}

int funParty(vector<vector<int>> &tree, vector<int> &w, vector<int> &D, int head){
    if(D[head]==-1){
        if(tree[head].empty()){
            D[head]=w[head];
        }else{
            int m1=w[head];
            int m0=0;
            for(auto c: tree[head]){
                for(auto x: tree[c]){
                    if(x!=head){
                        m1+=funParty(tree, w, D, x);
                    }
                }
            }
            for(auto u: tree[head]){
                m0+=funParty(tree, w, D, u);
            }
            D[head]=max(m1, m0);
        }
    }
    return D[head];
}
int Solve(){
    std::ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<vector<int>> raw_tree(n); // Store the tree
    vector<vector<int>> tree(n);
    vector<int> D(n,-1); // Maximum fun party
    vector<int> w(n); // weights on the nodes
    vector<int> vis(n,0);
    for(int i=0; i<n;i++){
        cin>>w[i];
    }
    int u,v;
    for(int i=0; i<n-1;i++){
        cin>>u>>v;
        raw_tree[v-1].push_back(u-1);
        raw_tree[u-1].push_back(v-1);
    }
    // Process raw_graph to make it a directed graph
    dfs(raw_tree, tree,vis,0);
    cout<<funParty(tree, w, D, 0)<<'\n';
    return 0;
}

int main(){
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }

#endif
  return Solve();
}
/*
Test cases:

11
3 5 1 6 2 3 7 2 1 2 1
9 7
10 7
11 7
5 2
6 3
7 4
8 4
2 1
3 1
4 1


Output=18

8
2 1 1 3 3 1 2 3
3 4
4 1
8 1
8 5
3 7
3 2
6 2

Output=9
*/