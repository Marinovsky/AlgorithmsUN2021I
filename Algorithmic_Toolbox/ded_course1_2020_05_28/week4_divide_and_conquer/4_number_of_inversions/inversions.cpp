#include <iostream>
#include <vector>
#include <utility>

using std::vector;
using std::pair;
using std::cout;

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  //write your code here
  return number_of_inversions;
}
pair<vector<int>, long long> Merge(pair<vector<int>, long long> b, pair<vector<int>, long long> c){
    int count=0;
    vector<int> v;
    vector<int> min=;
    vector<int> max;

    int j=0;
    for(int i=0; i<min_;i++){
        if(j<b.first.size()){
            if(b.first[j]<=c.first[i]){
                v.push_back(c.first[i]);
            }else{
                count++;
                j++;
                i--;
            }
        }else{
            break;
        }
    }
    if(i==min_)
}

pair<vector<int>, long long> mergeSort(pair<vector<int>, long long> &a, int l, int r){
    if((r-l)==1){
        return a;
    }else{
        int m=((r-l)/2)+1;
        pair<vector<int>, long long> b=mergeSort(a,l,m-1);
        pair<vector<int>, long long> c=mergeSort(a,m+1,r);
        pair<vector<int>, long long> res=Merge(b,c);
        return res;
    }
}

int main() {
  int n;
  std::cin >> n;
  vector<int> arr(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> arr[i];
  }
  pair<vector<int>, long long> a=make_pair(arr, 0);
  std::cout << mergeSort(a, 0, a.first.size()).second << '\n';
}
