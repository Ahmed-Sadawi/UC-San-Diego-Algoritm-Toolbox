#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int min_time_naive(int n, vector<int>times)//{5,3,8,1}
{
    int minTime =0;
    vector<int>treated(n,0);
    for(int i=0; i<n; i++)
    {
        int min=INT_MAX;
        int minInd=0;
        for(int j=0; j<n; j++)
        {
            if(treated[j]==0 && times[j]<min)
            {
                min=times[j];
                minInd=j;
            }
           
        }
     minTime+=(n-i-1)*min;
     treated[minInd]=1;
    }
    return minTime;
}



int min_time_opt(int n, vector<int>times)
{
    int waiting_time =0;
    sort(times.begin(), times.end());
    for(int i=0; i<n; i++)
    {
        waiting_time+=(n-i-1)*times[i];
    }
    return waiting_time;
}


int main()
{
    cout<<min_time_naive(3,{15,20,10})<<endl;
    cout<<min_time_opt(3,{15,20,10});
    
}