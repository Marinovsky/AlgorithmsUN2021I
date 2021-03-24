#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;
using std::cout;

struct Segment {
  int start, end;
};

void optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  bool match;
  vector<Segment> segments_chosen;
  for(Segment c: segments){
    match=false;
    if(segments_chosen.empty()){
        segments_chosen.push_back(c);
    }else{
        for(int i=0;i<segments_chosen.size();i++){
            if(((segments_chosen[i].start<=c.start)&&(c.start<=segments_chosen[i].end))||((segments_chosen[i].start<=c.end)&&(c.end<=segments_chosen[i].end))){
                //cout<<c.start<<' '<<c.end<<'\n';
                //cout<<segments_chosen[i].start<<' '<<segments_chosen[i].end<<'\n';
                segments_chosen[i].start=std::max(c.start,segments_chosen[i].start);
                segments_chosen[i].end=std::min(c.end,segments_chosen[i].end);
                //cout<<"after: "<<segments_chosen[i].start<<' '<<segments_chosen[i].end<<'\n';
                match=true;
            }
        }
        if(!match){
            segments_chosen.push_back(c);
        }
    }
  }
  std::sort(segments_chosen.begin(),segments_chosen.end(), [](Segment a, Segment b){
            return a.start < b.start;
       });
  cout<<segments_chosen.size()<<'\n';
  for(Segment c:segments_chosen){
    cout<<c.start<<' ';
  }
  cout<<'\n';
  /*
  for (size_t i = 0; i < segments.size(); ++i) {
    points.push_back(segments[i].start);
    points.push_back(segments[i].end);
  }
  */
}

int main() {
  /*
  for(int j=0; j<10;j++){
  cout<<"Caso: "<<j<<'\n';
  int n;
  n=rand()%5;
  //std::cin >> n;
  cout<<n<<'\n';
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
        segments[i].start=rand()%5;
        segments[i].end=rand()%5+segments[i].start;
        cout<<segments[i].start<<' '<<segments[i].end<<'\n';
    //std::cin >> segments[i].start >> segments[i].end;
  }
  optimal_points(segments);
}
*/
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
       std::cin >> segments[i].start >> segments[i].end;
  }
  std::sort(segments.begin(),segments.end(), [](Segment a, Segment b){
            return a.start < b.start;
       });
  optimal_points(segments);
  /*
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
  */
}
