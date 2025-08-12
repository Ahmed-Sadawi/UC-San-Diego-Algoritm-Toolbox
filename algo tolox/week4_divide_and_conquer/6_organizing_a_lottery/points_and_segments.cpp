#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

// Function to count segments efficiently
vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
    vector<int> count(points.size());  // Result array
    vector<tuple<int,char,int>> events;
    for(auto s : starts)
    {
      events.emplace_back(s,'L',-1);
    }
    for(auto e : ends)
    {
      events.emplace_back(e,'R',-1);
    }
    for(int i=0; i<points.size(); i++)
    {
      events.emplace_back(points[i],'P',i);
    }

    sort(events.begin(),events.end());
    int active_segment = 0;
    for(auto [value,type,index] : events)
    {
      if(type=='L')active_segment++;
      else if(type=='P')count[index]=active_segment;
      else active_segment--;
    }

    return count;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      if (points[i]>=starts[j] && points[i]<=ends[j]) {
        cnt[i] += 1;
      }
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
