#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int minRefillsNaive(int distance, int tank, vector<int> stations)// 500, 200 , [0,100,200,300,400]
{
    stations.push_back(distance);

    int minrefill =0;
    int current_pos = 0;

    for(int i=0; i<stations.size(); i++)
    {
        if(stations[i]-current_pos > tank)
        {
            return -1;
        }

        if(stations[i+1]-current_pos>tank)
        {
            minrefill++;
            current_pos=stations[i];
        }
    }
    return minrefill;
}
int main()
{
    cout<<minRefillsNaive(500,200,{100,200,300,400});
}