#include <iostream>
#include <vector>

using std::vector;

/* This class implements a bit unusual scheme for storing edges of the graph,
 * in order to retrieve the backward edge for a given edge quickly. */
class FlowGraph {
public:
    struct Edge {
        int from, to, capacity, flow;
    };

private:
    /* List of all - forward and backward - edges */
    vector<Edge> edges;

    /* These adjacency lists store only indices of edges in the edges list */
    vector<vector<size_t> > graph;

public:
    explicit FlowGraph(size_t n): graph(n) {}

    void add_edge(int from, int to, int capacity) {
        /* Note that we first append a forward edge and then a backward edge,
         * so all forward edges are stored at even indices (starting from 0),
         * whereas backward edges are stored at odd indices in the list edges */
        Edge forward_edge = {from, to, capacity, 0};
        Edge backward_edge = {to, from, 0, 0};
        graph[from].push_back(edges.size());
        edges.push_back(forward_edge);
        graph[to].push_back(edges.size());
        edges.push_back(backward_edge);
    }

    size_t size() const {
        return graph.size();
    }

    const vector<size_t>& get_ids(int from) const {
        return graph[from];
    }

    const Edge& get_edge(size_t id) const {
        return edges[id];
    }

    void add_flow(size_t id, int flow) {
        /* To get a backward edge for a true forward edge (i.e id is even), we should get id + 1
         * due to the described above scheme. On the other hand, when we have to get a "backward"
         * edge for a backward edge (i.e. get a forward edge for backward - id is odd), id - 1
         * should be taken.
         *
         * It turns out that id ^ 1 works for both cases. Think this through! */
        if(id%2==0){
            edges[id].flow += flow;
            edges[id ^ 1].capacity += flow;
        }else{
            edges[id ^ 1].flow -= flow;
            edges[id].capacity -= flow;
        }
    }

    bool DFS(size_t head, size_t target, vector<size_t> &path, vector<size_t> &vis){
        //std::cout<<head<<'\n';
        for(auto v:graph[head]){
            if((vis[edges[v].to]!=1)&&(edges[v].capacity - edges[v].flow > 0)){
                vis[edges[v].to]=1;
                if(edges[v].to==target){
                    path.push_back(v);
                    return true;
                }else{
                    if(DFS(edges[v].to, target, path, vis)){
                        path.push_back(v);
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

FlowGraph read_data() {
    int vertex_count, edge_count;
    std::cin >> vertex_count >> edge_count;
    FlowGraph graph(vertex_count);
    for (int i = 0; i < edge_count; ++i) {
        int u, v, capacity;
        std::cin >> u >> v >> capacity;
        graph.add_edge(u - 1, v - 1, capacity);
    }
    return graph;
}

int max_flow(FlowGraph& graph, int from, int to) {
    int flow = 0;
    vector<size_t> path;
    vector<size_t> vis(graph.size(), 0);
    vis[0]=1;
    while(graph.DFS(0,graph.size()-1, path, vis)){
        size_t min_flow=10001;
        for(auto v: path){
            if((graph.get_edge(v).capacity-graph.get_edge(v).flow)<min_flow){
                min_flow=graph.get_edge(v).capacity-graph.get_edge(v).flow;
            }
        }
        for(auto v:path){
            graph.add_flow(v, min_flow);
        }
        flow+=min_flow;
        path.clear();
        std::fill(vis.begin(),vis.end(),0);
        vis[0]=1;
    }
    return flow;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    FlowGraph graph = read_data();

    std::cout << max_flow(graph, 0, graph.size() - 1) << "\n";
    /*
    vector<size_t> path;
    vector<size_t> vis(graph.size(), 0);
    std::cout<< graph.DFS(0, graph.size()-1, path, vis)<<'\n';
    
    for(auto c: path){
        std::cout<<graph.get_edge(c).from<<"->"<<graph.get_edge(c).to<<'\n';
    }
    */
    return 0;
}
