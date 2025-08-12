#include <iostream>
#include <vector>
using namespace std;
using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int>  stops) {
    stops.push_back(dist);
    stops.insert(stops.begin(), 0);
    int refill=0;
    int current_pos=0;
    for(int i=0; i<stops.size()-1; i++)
    {
        
        if(stops[i+1]-stops[i]>tank)return-1;
        if(stops[i+1]-current_pos>tank)
        {
            refill++;
            current_pos=stops[i];
        }
    }
    return refill;
}//[0,100,200,300,400,700]


int main() {
     int d = 0;
     cin >> d;
     int m = 0;
     cin >> m;
     int n = 0;
     cin >> n;

     vector<int> stops(n);
     for (size_t i = 0; i < n; ++i)
         cin >> stops.at(i);

     cout << compute_min_refills(d, m, stops) << "\n";
     //cout<<compute_min_refills(500,200,{100,200,300,400});
    return 0;
}
