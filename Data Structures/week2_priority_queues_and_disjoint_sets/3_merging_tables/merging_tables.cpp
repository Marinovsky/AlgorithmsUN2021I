
#include <vector>
#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::vector;

struct DisjointSetsElement {
	long long size, parent, rank;

	DisjointSetsElement(long long size = 0, long long parent = -1, long long rank = 0):
	    size(size), parent(parent), rank(rank) {}
};

struct DisjointSets {
	long long size;
	long long max_table_size;
	vector <DisjointSetsElement> sets;

	DisjointSets(long long size): size(size), max_table_size(0), sets(size) {
	    for(long long i = 0; i < size; i++){
            DisjointSetsElement temp;
            sets[i]=temp;
	    }
		for (long long i = 0; i < size; i++)
			sets[i].parent = i;
	}

	long long getParent(long long table) {
		// find parent and compress path
		if(sets[table].size!=0){
            //cout<<"Find it! "<<table<<endl;
            return table;
		}else{
            sets[table].parent=getParent(sets[table].parent);
		}
	}

	void merge(long long destination, long long source) {
		long long realDestination = getParent(destination);
		long long realSource = getParent(source);
		if (realDestination != realSource) {
			// merge two components
			// use union by rank heuristic
			//if(sets[realDestination].rank>=sets[realSource].rank){
                sets[realSource].parent=realDestination;
                if(sets[realSource].rank==sets[realDestination].rank){
                    sets[realDestination].rank++;
                }
                sets[realDestination].size+=sets[realSource].size;
                sets[realSource].size=0;
                if(max_table_size<sets[realDestination].size){
                    max_table_size=sets[realDestination].size;
                }
			//}
		}
	}
};

int main() {
	long long n, m;
	cin >> n >> m;
	vector<long long> ans;
	DisjointSets tables(n);
/*
	for (auto &table : tables.sets) {
        cout<<table<<endl;
		cin >> table.size;
		tables.max_table_size = max(tables.max_table_size, table.size);
	}
*/
	for(int i=0; i<tables.sets.size();i++){
        DisjointSetsElement& table=tables.sets[i];
        cin>>table.size;
        tables.max_table_size = max(tables.max_table_size, table.size);
	}

	for (long long i = 0; i < m; i++) {
		long long destination, source;
		cin >> destination >> source;
                destination--;
                source--;
		tables.merge(destination, source);
	        //cout <<tables.max_table_size << endl;
        ans.push_back(tables.max_table_size);
	}
	for(int i=0; i<ans.size();i++){
        cout<<ans[i]<<endl;
	}
	return 0;
}
