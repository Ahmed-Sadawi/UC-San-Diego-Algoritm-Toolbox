#include <iostream>
#include <vector>
using namespace std;
int get_change(int m) {
  vector<int>dp(m+1,m);
  dp[0]=0;
  vector<int> coins = {1,3,4};
  for(int i =1; i<=m; i++)
  {
    for(int coin : coins)
    {
      if(i>=coin)
      {
        dp[i]=min(dp[i],dp[i-coin]+1);
      }
    }
  }
  return dp[m];
}
//return m / 4;
int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
