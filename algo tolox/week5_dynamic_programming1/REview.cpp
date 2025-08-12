#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

int get_change(int m)
{
  vector<int>dp(m+1,m);
  dp[0]=0;
  vector<int>coins={1,3,4};
  for(int i =1; i<=m; i++)
  {
    for(int coin : coins)
    {
      if(i>=coin)
      {
        dp[i]=min(dp[i],dp[i-coin]+1);
      }
    }
     //cout<<dp[i]<<" ";to ensure the correctance of dp taple
  }
  
  //cout<<endl;
  return dp[m];
}

vector<int> optimal_sequence(int n)
{
  vector<int>dp(n+1,n);
  dp[1]=0;
   for(int i=2; i<=n; i++)
   {
    dp[i]=dp[i-1]+1;
    if(i%3==0)dp[i]=min(dp[i],dp[i/3]+1);
    else if(i%2==0)dp[i]=min(dp[i],dp[i/2]+1);
   }

  vector<int>seq;
  for(int i=n; i>=1;)
  {
    seq.push_back(i);
    if(i%3==0 && dp[i]==dp[i/3]+1) i=i/3;
    else if(i%2==0 && dp[i]==dp[i/2]+1) i=i/2;
    else i=i-1;
  }
  reverse(seq.begin(), seq.end());
  return seq;
}

int edit_distance(const string &str1, const string &str2)
{
  int n = str1.size();
  int m = str2.size();
  vector<vector<int>> dp(n+1,vector<int>(m+1));
  for(int i=0; i<n; i++)dp[i][0]=i;
  for(int i=0; i<m; i++)dp[0][i]=i;

  for(int i=1; i<=n; i++)
  {
    for(int j=1; j<=m; j++)
    {
      int inser = dp[i][j-1]+1;
      int delet = dp[i-1][j]+1;
      int match = dp[i-1][j-1];
      int disma = dp[i-1][j-1]+1;
      
      if(str1[i]==str2[i])
      {
        dp[i][j]=min({inser,delet,match});
      }else{
        dp[i][j]=min({inser,delet,disma});
      }
    }
  }
  return dp[n][m];
}
  

int lcs2(vector<int> &a, vector<int> &b)
{
  int n = a.size();
  int m = b.size();

  vector<vector<int>> dp(n+1, vector<int>(m+1,0));
  for(int i=1; i<=n; i++)
  {
    for(int j =1; j<=m; j++)
    {
      if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
      else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
  }
return dp[n][m];
}

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c)
{
  int n = a.size(), m = b.size(), k = b.size();
  vector<vector<vector<int>>> dp (n+1,vector<vector<int>>(m+1,vector<int>(k+1,0)));
  for(int i=1; i<=n; i++)
  {
    for(int j=1; j<=m; j++)
    {
      for(int l=1; l<=k; i++)
      {
        if(a[i-1]==b[j-1] && b[j-1]==c[l-1])
        {
          dp[i][j][l] = dp[i-1][j-1][l-1]+1;
        }else{
          dp[i][j][l] = max({dp[i-1][j][l], dp[i][j-1][l], dp[i][j][l-1]});
        }
      }
    }
  }
  return dp[n][m][k];
}


// we need to compute this ac*10^n +((a+b)(c+d)-ac-bd)10^n+bd 
long long int karatsupa( long long x, long long y)
{
  if(x<10 || y<10)return x*y;//base case
  int m = max((int) log10(x)+1, (int) log10(y)+1);
  int n = m/2;
  
  long long a = x/pow(10,n);
  long long b = x%(long long)pow(10,n);
  long long c = y/pow(10,n);
  long long d = y%(long long)pow(10,n);

  long long ac  = karatsupa(a,c);
  long long mid = karatsupa(a+b,c+d);
  long long bd  = karatsupa(b,d);

  return ac*pow(10,2*n)+(mid-ac-bd)*pow(10,n)+bd;
}

vector<int> optimal_sequence(int n)
{
  vector<int> dp (n+1);
  dp[1]=0;
  for(int i=2; i<=n; i++)
  {
    dp[i]=dp[i-1]+1;
    if(i%3==0)dp[i]=min(dp[i],dp[i/3]+1);
    else if(i%2==0)dp[i]=min(dp[i],dp[i/2]+1);
  }
  vector<int>seq;
  for(int i=n; i>=n;)
  {
    seq.pop_back(i);
    if(i%3==0 && dp[i]=dp[i/3]+1) i=i/3;
    else if(i%2==0 && dp[i]=dp[i/2]+1) i=i/2;
    else i=i-1;
  }
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
  
