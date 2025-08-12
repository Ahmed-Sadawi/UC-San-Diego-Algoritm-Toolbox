#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int knapsack_without_rep(int W, const vector<int>& weights, const vector<int>& values)
{
    int n = values.size();
    vector<vector<int>> dp (n+1, vector<int>(W+1,0));
    for(int i = 1; i<=n; i++)
    {
        for(int w=1; w<=W; w++)
        {
            dp[i][w]=dp[i-1][w];
            if(w>=weights[i-1])
            {
               int val=dp[i-1][w-weights[i-1]]+values[i-1];
               dp[i][w]=max(dp[i][w],val);
            }
        }
    }
    return dp [n][W];
}
int main() {
    int W = 5;
    vector<int> weights = {1,3,4};
    vector<int> values = {1,4,5};

    int max_value = knapsack_without_rep(W, weights, values);
    cout << "Maximum value = " << max_value << endl;

    return 0;
}
