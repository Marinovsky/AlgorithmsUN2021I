#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
/*
vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}
*/
vector<int> optimal_sequence(int n) {
    vector<int> v(n+1, 0);
    vector<int> result;
    result.push_back(n);
    v[0]=1;v[1]=0;
    int temp;
    for(int i=2; i<n+1;i++){
        temp=n+1;
        if(i%3==0){
            temp=v[i/3]+1;
        }
        if(i%2==0){
            if((v[i/2]+1)<temp){
                temp=v[i/2]+1;
            }
        }
        if((v[i-1]+1)<temp){
            temp=v[i-1]+1;
        }
        v[i]=temp;
    }
    int m=n;
    int temp2;
    /*
    for(int i=1; i<11;i++){
        cout<<v[i]<<' ';
    }
    cout<<'\n';
    */
    ///*
    while(m!=1){
        //cout<<"iteration: "<<m<<'\n';
        temp=m+1;
        if(m%3==0){
            temp=v[m/3]+1;
            temp2=m/3;
        }
        //cout<<temp<<' ';
        if(m%2==0){
            if((v[m/2]+1)<temp){
                temp=v[m/2]+1;
                temp2=m/2;
            }
        }
        //cout<<temp<<' ';
        if((v[m-1]+1)<temp){
            temp=v[m-1]+1;
            temp2=m-1;
        }
        //cout<<temp<<'\n';
        result.push_back(temp2);
        m=temp2;
    }
    //*/
    reverse(result.begin(), result.end());
    return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
