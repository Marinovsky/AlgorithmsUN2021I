#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Edge {
    int from;
    int to;
};

struct ConvertGSMNetworkProblemToSat {
    int numVertices;
    vector<Edge> edges;
    vector<string> clauses;
    vector<int> out;

    ConvertGSMNetworkProblemToSat(int n, int m) :
        numVertices(n),
        edges(m),
        out(n,0)
    {  }
    bool two_edges(){
        for(auto e: edges){
            out[e.from-1]++;
            if(out[e.from-1]>=3){
                return false;
            }

            out[e.to-1]++;
            if(out[e.to-1]>=3){
                return false;
            }

        }
        return true;
    }
    void single_color(){
        string temp="";
        for(int i=0; i<numVertices;i++){
            for(int j=1; j<=3;j++){
                temp+=to_string(3*(i)+j)+" ";
            }
            temp+="0";
            clauses.push_back(temp);
            unique_color(i);
            temp="";
        }
    }
    void unique_color(int i){
        string temp;
        for(int j=1; j<=3;j++){
            for(int k=j+1;k<=3;k++){
                temp="-"+to_string(3*(i)+j)+" -"+to_string(3*(i)+k)+" 0";
                clauses.push_back(temp);
            }
        }
    }
    void adjacent_color(){
        string temp;
        for(auto e:edges){
            for(int i=1;i<=3;i++){
                temp="-"+to_string((e.from-1)*(3)+i)+" -"+to_string((e.to-1)*(3)+i)+" 0";
                clauses.push_back(temp);
            }
        }
    }
    void makeSAT(){
        single_color();
        adjacent_color();
    }


    void printEquisatisfiableSatFormula() {
        // This solution prints a simple satisfiable formula
        // and passes about half of the tests.
        // Change this function to solve the problem.
        makeSAT();
        cout<<clauses.size()<<" "<<(numVertices*3)<<'\n';
        for(auto clause:clauses){
            cout<<clause<<'\n';
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    ConvertGSMNetworkProblemToSat converter(n, m);
    for (int i = 0; i < m; ++i) {
        cin >> converter.edges[i].from >> converter.edges[i].to;
    }

    converter.printEquisatisfiableSatFormula();

    return 0;
}
