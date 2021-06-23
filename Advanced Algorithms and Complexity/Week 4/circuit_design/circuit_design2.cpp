#include <bits/stdc++.h>

using namespace std;
void DFS(vector<vector<int>> &g, vector<int> &vis, int head, stack<int> &nodes){
    vis[head]=1;
    for(auto c: g[head]){
        if(vis[c]==0){
            DFS(g,vis,c,nodes);
        }
    }
    nodes.push(head);
}
void DFS2(vector<vector<int>> &g, vector<int> &vis, int head,vector<int> &com, vector<int> &colors, int color){
    vis[head]=1;

    for(auto c: g[head]){
        if(vis[c]==0){
            DFS2(g,vis,c, com, colors, color);
        }
    }
    colors[head]=color;
    com.push_back(head);
}

int main(){
    int n,c;
    cin>>n>>c;
    // Initialize implication graph
    vector<vector<int>> ig(2*n);
    // Initialize reverse graph for SCC(Strongly connected components)
    vector<vector<int>> rev(2*n);
    // For a variable x_i, is position in the graph is i-1
    // For a variable -x_i is position in the graph is n+(i-1)
    for(int i=0; i<c;i++){
        int u,v;
        cin>>u>>v;
        if((u>0)&&(v>0)){
            ig[n+(u-1)].push_back(v-1);
            rev[v-1].push_back(n+(u-1));
            ig[n+(v-1)].push_back(u-1);
            rev[u-1].push_back(n+(v-1));
        }else if((u>0)&&(v<0)){
            ig[n+(u-1)].push_back(n+(abs(v)-1));
            rev[n+(abs(v)-1)].push_back(n+(u-1));
            ig[abs(v)-1].push_back(u-1);
            rev[u-1].push_back(abs(v)-1);
        }else if((u<0)&&(v>0)){
            ig[abs(u)-1].push_back(v-1);
            rev[v-1].push_back(abs(u)-1);
            ig[n+(v-1)].push_back(n+(abs(u)-1));
            rev[n+(abs(u)-1)].push_back(n+(v-1));
        }else{
            ig[abs(u)-1].push_back(n+(abs(v)-1));
            rev[n+(abs(v)-1)].push_back(abs(u)-1);
            ig[abs(v)-1].push_back(n+(abs(u)-1));
            rev[n+(abs(u)-1)].push_back(abs(v)-1);
        }
    }
    // Traverse the reverse implication graph in pos order
    vector<int> vis(2*n,0);
    stack<int> nodes;
    for(int i=0; i<2*n;i++){
        if(vis[i]==0){
            DFS(rev, vis,i,nodes);
        }
    }
    
    // Find SCC of the implication graph
    fill(vis.begin(), vis.end(), 0);
    vector<vector<int>> scc;
    vector<int> component;
    // Asign a color for each strongly connected component
    vector<int> colors(2*n,0);
    int color=1;
    while(!nodes.empty()){
        int v=nodes.top();
        nodes.pop();
        if(vis[v]==0){
            DFS2(ig, vis, v,component, colors, color);
            color++;
            scc.push_back(component);
            component.clear();
        }   

    }
    // Check if x and -x lie in the same SCC
    // Check if the color of x and -x is the same
    bool satisfiable=true;
    for(int i=0; i<n;i++){
        if(colors[i]==colors[n+i]){
            satisfiable=false;
        }
    }
    // Check wheter the formula is satisfiable or not
    if(satisfiable){
        cout<<"SATISFIABLE"<<'\n';
        // Construct an assignment
        fill(vis.begin(), vis.end(), -1);
        for(auto c: scc){
            for(auto i: c){
                if(vis[i]==-1){
                    vis[i]=1;
                    if(i>=n){
                        vis[i-n]=0;
                    }else{
                        vis[i+n]=0;
                    }
                }
            }
        }
        // print assignment
        for(int i=0; i<n;i++){
            if(vis[i]==0){
                cout<<'-'<<(i+1)<<' ';
            }else{
                cout<<i+1<<' ';
            }
        }
        cout<<'\n';
    }else{
        cout<<"UNSATISFIABLE"<<'\n';
    }
}