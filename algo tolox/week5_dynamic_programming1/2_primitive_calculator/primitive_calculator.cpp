#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> optimal_sequence(int n)
{
    vector<int> dp(n+1);
    dp[1]=0;
    for(int i =2; i<=n; i++)
    {
        dp[i]=dp[i-1]+1;
        if(i%3==0) dp[i]= min(dp[i], dp[i/3]+1);
        else if(i%2==0) dp[i]= min(dp[i], dp[i/2]+1);
    }
    vector<int>seq;
    for(int i = n; i>=1;)
    {
        seq.push_back(i);
        if(i%3==0 && dp[i]==dp[i/3]+1)i=i/3;
        if(i%2==0 && dp[i]==dp[i/2]+1)i=i/2;
        else i=i-1;
    }
    reverse(seq.begin(), seq.end());
    return seq;
}


int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
