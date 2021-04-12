#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define MIN(x, y) ((x)>(y)?(y):(x))
#define MAX(x, y) ((x)>(y)?(x):(y))

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
    /*
    cout<<"final heap: ";
    for(auto c: data_){
        cout<< c <<" ";
    }
    cout<<"\n";
    */
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  void GenerateSwaps() {
    swaps_.clear();
    // The following naive implementation just sorts
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap,
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation
    bool flag=false;
    for(int i=(data_.size()/2); i>=0;i--){
        siftDown(i);
    }
  }

 void siftDown(int i){
    int j=i;
    int l=(i*2)+1;
    if((l<data_.size())&&(data_[l]<data_[j])){
        j=l;
    }
    int r=(i*2)+2;
    if((r<data_.size())&&(data_[r]<data_[j])){
        j=r;
    }
    if(i!=j){
        int temp=data_[i];
        data_[i]=data_[j];
        data_[j]=temp;
        swaps_.push_back(pair<int, int>(i, j));
        /*
        for(auto c: data_){
            cout<< c <<" ";
        }
        cout<<"\n";
        */
        siftDown(j);
    }
 }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
