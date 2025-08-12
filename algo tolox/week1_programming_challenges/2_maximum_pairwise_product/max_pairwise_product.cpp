#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long MaxPairwiseProduct(const vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            if(((long long)(numbers[first])*numbers[second]>max_product))
            {
                max_product=((long long)(numbers[first]))*numbers[second];
            }
        }
    }
    return max_product;
}
long long MaxPairwiseProductFast(const vector<int>& numbers)
{
    int n = numbers.size();
    int maxind=-1;
    for(int i=0; i<n; i++)
    {
        if((maxind==-1) || (numbers[i]>numbers[maxind]))maxind=i;
    }
    int maxind2 = -1;
    for(int x =0; x<n; x++)
    {
        if((x!=maxind) && ((maxind2==-1) || (numbers[x]>numbers[maxind2])))maxind2=x;
    }
    return ( (long long)(numbers[maxind]))*numbers[maxind2];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    long long result = MaxPairwiseProductFast(numbers);
    cout<<result;

    return 0;
}
