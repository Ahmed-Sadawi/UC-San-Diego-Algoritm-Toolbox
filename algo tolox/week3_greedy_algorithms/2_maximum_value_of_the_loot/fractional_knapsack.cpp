#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) 
{
  int n = weights.size();
  double value = 0.0;
  
  while(capacity>0)
  {
    double big_frac =0.0;
    int big_Ind=-1;
    for(int i=0; i<n; i++)
  {
    if(weights[i]>0)
    {
      double ratio = (double)values[i]/weights[i];
     if(ratio>big_frac)
      {
      big_frac=ratio;
      big_Ind=i;
      }
    }
   
  }
  if (big_Ind == -1) break;

  double weightTotack = min(capacity,(int)weights[big_Ind]);
  value+=big_frac*weightTotack;
  
  capacity-=weightTotack;
  weights[big_Ind]-=weightTotack;
  }
  
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
