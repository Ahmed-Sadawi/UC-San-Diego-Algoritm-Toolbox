#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int memo_knap(int w, vector<int>&weights, vector<int>&values, unordered_map<int, int>& memo)
{
    if(w==0)return 0; // base case

    if(memo.count(w))return memo[w];// we have computed 
    int maxval=0;
    for(int i=0; i<values.size(); i++)
    {
        if(weights[i]<=w){
         int val = memo_knap(w-weights[i],weights,values,memo)+values[i];
         if(val>maxval)maxval= val;  
        }
    }
    memo[w]=maxval;
    return memo[w];
}
int main() {
    int w = 4;
    vector<int> weights = {1,2,3};
    vector<int> values = {2, 4, 5};
    unordered_map<int, int> memo;
    int max_value = memo_knap(w, weights, values, memo);
    cout << "Maximum value in knapsack: " << max_value << endl;

    return 0;
}