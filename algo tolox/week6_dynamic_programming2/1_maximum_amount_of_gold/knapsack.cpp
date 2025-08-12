#include <iostream>
#include <vector>
#include<algorithm>
using std::vector;
using namespace std;
int optimal_weight(int W, const vector<int> &we) {
  //write your code here
  int n = we.size();
  vector<vector<int>> dp (n+1,vector<int>(W+1,0));
  for(int i=1; i<=n; i++)
  {
    for(int w=1; w<=W; w++)
    {
      dp[i][w]=dp[i-1][w];
      if(w>=we[i-1])
      {
        int val = dp[i-1][w-we[i-1]]+we[i-1];
        dp[i][w]= max(dp[i][w],val);
      }
    }
  }

  return dp[n][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
