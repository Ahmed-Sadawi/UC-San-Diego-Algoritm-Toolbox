#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int knap_w_rep(int W, vector<int>&wieghts, vector<int>&values)
{
    vector<int> dp (W+1,0);
    for(int w = 1; w<=W; w++)
    {
        //cout<<w<<endl;
        for(int i =0; i<wieghts.size(); i++)
        {
            cout<<dp[w]<<" ";
            if(wieghts[i]<=w)
            {
                dp[w]=max( dp[w], dp[w-wieghts[i]]+values[i] );
            }
        }
        //cout<<endl;
    }
    return dp[W];
}
int main() {
    int W = 4;
    vector<int> weights = {1,2,3};
    vector<int> values = {2, 4, 5};

    int max_value = knap_w_rep(W, weights, values);
    cout << "Maximum value = " << max_value << endl;

    return 0;
}

