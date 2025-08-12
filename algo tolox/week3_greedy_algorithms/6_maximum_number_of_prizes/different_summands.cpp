#include <iostream>
#include <vector>
#include <cmath>
using std::vector;

vector<int> optimal_summands(int n) {
    vector<int> summands;
    int sum = 0;
    int current = 1;

    while (sum + current <= n) {
        summands.push_back(current);   // Add the current integer to the summands
        sum += current;                // Update the sum
        current++;                     // Move to the next integer
    }

    // If there’s any remainder left after adding the largest number
    if (sum < n) {
        summands.back() += (n - sum); // Add the remaining part to the last element
    }

    return summands;
}


int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
