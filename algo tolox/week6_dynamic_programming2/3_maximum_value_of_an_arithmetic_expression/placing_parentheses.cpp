#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <climits>
using namespace std;

// Function to perform the operation
int eval(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        default: return 0;
    }
}

// Function to find minimum and maximum values
long long get_maximum_value(const string &exp)
{
    vector<int>nums;
    vector<char>op;
    for(int i=0; i<exp.size(); i++)//Exrtact
    {
        if(i%2==0)nums.push_back(exp[i]-'0');
        else op.push_back(exp[i]);
    }

    int m = nums.size();
    vector<vector<int>>dp_max(m,vector<int>(m));
    vector<vector<int>>dp_min(m,vector<int>(m));

    for(int i =0; i<m; i++) dp_max[i][i]=dp_min[i][i]=nums[i];//Base case
    
    for(int len =1; len<m; len++)//len mean max numper of operations possibilities  
    {
        for(int i=0; i<m-len;i++)
        {
            int j=i+len;
            dp_max[i][j]=LLONG_MIN;
            dp_min[i][j]=LLONG_MAX;
            for(int k=i; k<j; k++) // k mean the first num of possibilities 
                                   // other hand len max numof poss __ k min numof poss
            {
               long long a = eval(dp_max[i][k], dp_max[k+1][j],op[k]);
               long long b = eval(dp_max[i][k], dp_min[k+1][j],op[k]);
               long long c = eval(dp_min[i][k], dp_max[k+1][j],op[k]);
               long long d = eval(dp_min[i][k], dp_min[k+1][j],op[k]);

                dp_max[i][j]=max(dp_max[i][j],max(a,max(b,max(c,d))));
                dp_min[i][j]=min(dp_min[i][j],min(a,min(b,min(c,d))));
            }
        }
    }
    return dp_max[0][m-1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}