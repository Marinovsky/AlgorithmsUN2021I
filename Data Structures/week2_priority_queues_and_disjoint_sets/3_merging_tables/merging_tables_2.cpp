#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::vector;

class DisjointSets
{
private:
    int* sizes;
    int* rank;
    int* parent;
    int cap;
    int maximum;
public:
    DisjointSets(int size, vector<int> arr);
    int Find(int i);
    void merge(int dest, int src);
    int getMax(){
        return maximum;
    }
    void print();
};

DisjointSets::DisjointSets(int size, vector<int> arr){
        sizes=new int[size];
        rank=new int[size];
        parent=new int[size];
        cap=size;
        maximum=0;
        for(int i=0; i<size;i++){
            rank[i]=0;
            parent[i]=i;
            sizes[i]=arr[i];
            if(arr[i]>maximum){
                maximum=arr[i];
            }
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
        sizes[dest_root]+=sizes[src_root];
        sizes[src_root]=0;
        if(maximum<sizes[dest_root]){
            maximum=sizes[dest_root];
        }
    }
}
void DisjointSets::print(){
    cout<<"sizes : [ ";
    for(int i=0; i<cap;i++){
        cout<<sizes[i]<<", ";
    }
    cout<<" ]\n rank: [ ";
    for(int i=0; i<cap;i++){
        cout<<rank[i]<<", ";
    }
    cout<<" ]\n parent: [ ";
    for(int i=0; i<cap;i++){
        cout<<parent[i]<<", ";
    }
    cout<<" ]"<<endl;
}

int main(){
    int n, m, temp, d, s;
    cin>>n>>m;
    vector<int> values;
    vector<int> ans;
    for(int i=0; i<n;i++){
        cin>>temp;
        values.push_back(temp);
    }
    DisjointSets tables(n, values);
    //tables.print();
    for(int i=0; i<m;i++){
        cin>>d>>s;
        tables.merge(d-1,s-1);
        //cout<<tables.getMax()<<endl;
        ans.push_back(tables.getMax());
        //tables.print();
    }

    for(auto c: ans){
        cout<<c<<endl;
    }
}
