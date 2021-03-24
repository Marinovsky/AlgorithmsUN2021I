#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
struct item{
    int value;
    int weight;
};

double get_optimal_value(int cap, vector<item> v) {
  double value = 0.0;

  // write your code here
  std::sort(v.begin(), v.end(), [](item a, item b) {
        return ((double)a.value/(double)a.weight) > ((double)b.value/(double)b.weight);
  });
  for(int i=0; i<v.size();i++){
    if(cap<=0){
        return value;
    }else{
        double a=std::min(v[i].weight, cap);
        value+=a*((double)(v[i].value)/(double)(v[i].weight));
        cap-=a;
    }
    /*
    if(v[i].weight>=cap){
        double temp=(double)cap/(double)(v[i].weight);
        value+=temp*(v[i].value);
        break;
    }else{
        value+=(v[i].value);
        cap=cap-(v[i].weight);
    }
    */
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<item> objects(n);
  for (int i = 0; i < n; i++) {
    item temp;
    std::cin >> temp.value >> temp.weight;
    objects[i]=temp;
  }
  /*
  for(int j=0; j<5;j++){
  std::cout<<"Case "<<j<<'\n';
  int n;
  n=rand()%5;
  std::cout<<n<<' ';
  vector<item> objects(n);
  int capacity;
  capacity=(rand()%10)*2;
  std::cout<<capacity<<'\n';
  for(int i=0;i<n;i++) {
    item temp;
    temp.value=(rand()%5)*2;
    temp.weight=(rand()%5+1)*2;
    std::cout<<temp.value<<' '<<temp.weight<<'\n';
    objects[i]=temp;
  }
  */
  double optimal_value = get_optimal_value(capacity, objects);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  //}

  return 0;
}
