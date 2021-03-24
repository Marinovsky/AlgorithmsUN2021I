#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int tank, vector<int> & stops) {
    // write your code here
    int num_ref=0; int current_ref=0;int last_ref=0;
    int n=stops.size()-2;
    while(current_ref<=n){
        last_ref=current_ref;
        //cout<<"Current: "<<current_ref<<'\n';
        while((current_ref<=n)&&(stops[current_ref+1]-stops[last_ref]<=tank)){
            //cout<<stops[current_ref+1]<<' ';
            current_ref++;
        }
        //cout<<'\n';
        if(current_ref==last_ref){
            return -1;
        }
        if(current_ref<=n){
            num_ref++;
        }
    }
    return num_ref;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n+2);
    stops[0]=0;
    stops[n+1]=d;
    for (size_t i = 1; i < n+1; ++i)
        cin >> stops.at(i);
/*
    for(auto c: stops){
        cout<<c<<' ';
    }
    cout<<'\n';
*/
    if(stops[n+1]<stops[1]){
        cout<<-1<<'\n';
    }else{
        cout << compute_min_refills(m, stops) << "\n";
    }

    return 0;
}
