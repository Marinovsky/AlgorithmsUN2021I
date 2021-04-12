#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::max;

class DisjointSets
{
private:
    int* rank;
    int* parent;
    int cap;
public:
    DisjointSets(int size);
    int Find(int i);
    void merge(int dest, int src);
    void print();
};

DisjointSets::DisjointSets(int size){
        rank=new int[size];
        parent=new int[size];
        cap=size;
        for(int i=0; i<size;i++){
            rank[i]=0;
            parent[i]=i;
        }
}
int DisjointSets::Find(int i){
    if(parent[i]==i){
        return i;
    }else{
        parent[i]=Find(parent[i]);
        return parent[i];
    }
}
void DisjointSets::merge(int dest, int src){
    int src_root=Find(src);
    int dest_root=Find(dest);
    if(src_root!=dest_root){
        if(rank[src_root]>=rank[dest_root]){
            parent[src_root]=dest_root;
        }else{
            parent[dest_root]=src_root;
            if(rank[dest_root]==rank[src_root]){
                rank[src_root]++;
            }
        }
    }
}
void DisjointSets::print(){
    cout<<"rank: [ ";
    for(int i=0; i<cap;i++){
        cout<<rank[i]<<", ";
    }
    cout<<" ]\n parent: [ ";
    for(int i=0; i<cap;i++){
        cout<<parent[i]<<", ";
    }
    cout<<" ]"<<endl;
}


double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  D
  //write your code here
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
