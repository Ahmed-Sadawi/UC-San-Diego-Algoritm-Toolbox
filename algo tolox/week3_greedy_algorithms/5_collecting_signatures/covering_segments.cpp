#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {// {[1,3],[2,5],[5,6],[4,7]}
  vector<int> points;
  int n =segments.size();
  
    sort(segments.begin(), segments.end(),[](const Segment &a, const Segment &b){
      return a.end < b.end;
    });
 
   int lastpoient=-1;
  for (auto seg : segments) 
  {
    if(lastpoient<seg.start)
    {
      lastpoient=seg.end;
      points.push_back(lastpoient);
    }
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) { 
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
 
}
