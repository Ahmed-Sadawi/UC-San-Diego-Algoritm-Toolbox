#include <iostream>
#include<algorithm>
#include <vector>
#include <climits>
#include<cmath>
#include<map>
using namespace std;

    const int MOD = 1337;

    // Fast power (binary exponentiation): computes (a^k) % MOD
    int powerMod(int a, int k) {
    a %= 1337;
    int result = 1;
    for (int i = 0; i < k; ++i) {
        result = (result * a) % 1337;
    }
    return result;
}

    // Recursive divide and conquer function
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;

        int lastDigit = b.back();
        b.pop_back();

        int part1 = powerMod(superPow(a, b), 10);   // a^[rest]^10 % MOD
        int part2 = powerMod(a, lastDigit);         // a^d % MOD

        return (part1 * part2) % MOD;
    }


int main() {
//   vector<int>vec = {1,5,1,1,6,4};
//   wigglesort0(vec);
//   for(int nums : vec)cout<<nums<<endl;

vector<int>ve = {3,5,4};
 cout<< superPow(2,ve);
  return 0;
}
