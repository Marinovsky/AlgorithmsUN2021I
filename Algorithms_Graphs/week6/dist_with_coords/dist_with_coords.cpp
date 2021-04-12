#include <cstdio>
#include <cassert>
#include <vector>
#include <limits>
#include <utility>
#include <math.h>
#include <set>
#include <iostream>
#include <unordered_map>

using namespace std;

// See the explanations of these typedefs and constants in the starter for friend_suggestion
typedef vector<vector<int>> Adj;
typedef long long Len;
//typedef vector<priority_queue<pair<Len, int>,vector<pair<Len,int>>,greater<pair<Len,int>>>> Queue;
typedef set<pair<Len,int>> Extract;
typedef unordered_map<Len,Len> Heuristics;

const Len MAX_ = numeric_limits<Len>::max() / 4;

class AStar {
    // See the descriptions of these fields in the starter for friend_suggestion
    int n_;
    Adj adj_;
    Adj cost_;
    vector<Len> distance_;
    Heuristics hdistance_;
    // Coordinates of the nodes
    std::vector<std::pair<Len,Len>> xy_;

public:
    AStar(int n, Adj adj, Adj cost, std::vector<std::pair<Len,Len>> xy)
        : n_(n), adj_(adj), cost_(cost), distance_(n_, MAX_), xy_(xy)
    {;}

    // See the description of this method in the starter for friend_suggestion
    void clear() {
        distance_=vector<Len>(n_, MAX_);
    }
    long long potential(int a, int t){
        long long pi_f=sqrt(pow(xy_[a].first-xy_[t].first,2)+pow(xy_[a].second-xy_[t].second,2));
        return pi_f;
    }

    // See the description of this method in the starter for friend_suggestion
    void visit(Extract& e, pair<Len,int> u, int t) {
        for(int i=0; i<adj_[u.second].size();i++){
            int v=adj_[u.second][i];
            int w=cost_[u.second][i];
            //cout<<"Node -> "<<v<<" ,distance: "<<w<<'\n';
            long long h=potential(v,t);
            //cout<<"heuristics: "<<h<<'\n';
            //cout<<" - "<<distance_[side][v]<<" "<<distance_[side][u.second]+w<<'\n';
            if(distance_[v]>distance_[u.second]+w){
                if(distance_[v]!=MAX_){
                    e.erase(e.find(make_pair(hdistance_[v],v)));
                }
                //cout<<"new distance="<<distance_[side][v]+h<<'\n';
                distance_[v]=distance_[u.second]+w;
                hdistance_[v]=distance_[v]+h;
                if(((*(e.begin())).first==hdistance_[v])&&(distance_[(*(e.begin())).second]>distance_[v])){
                    e.insert(make_pair(distance_[v]+h-1,v));
                }else{
                    e.insert(make_pair(distance_[v]+h,v));
                }
            }
        }
    }


    // Returns the distance from s to t in the graph
    Len query(int s, int t) {
        clear();
        Extract e;
        e.insert(make_pair(0,s));
        distance_[s]=0;
        pair<Len,int> v;
        while(e.size()!=0){
            v=*(e.begin());
            //std::cout<<v.second+1<<'\n';
            if(v.second==t){
                break;
            }
            e.erase(e.begin());
            visit(e,v,t);
        }
        if(distance_[t]==MAX_){
            return -1;
        }else{
            return distance_[t];
        }
    }
};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    std::vector<std::pair<Len,Len>> xy(n);
    for (int i=0;i<n;++i){
        int a, b;
        scanf("%d%d", &a, &b);
        xy[i] = make_pair(a,b);
    }
    Adj adj(n);
    Adj cost(n);
    for (int i=0; i<m; ++i) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        adj[u-1].push_back(v-1);
        cost[u-1].push_back(c);
    }

    AStar astar(n, adj, cost, xy);

    int t;
    scanf("%d", &t);
    for (int i=0; i<t; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        printf("%lld\n", astar.query(u-1, v-1));
    }
}
