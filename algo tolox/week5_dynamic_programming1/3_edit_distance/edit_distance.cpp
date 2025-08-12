#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
using namespace std;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  int n = str1.size(), m = str2.size();
    vector<vector<int>> D(n + 1, vector<int>(m + 1));

    // Initialize base cases
    for (int i = 0; i < n; i++) D[i][0] = i;
    for (int j = 0; j < m; j++) D[0][j] = j;

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int insertion = D[i][j - 1] + 1;
            int deletion = D[i - 1][j] + 1;
            int match = D[i - 1][j - 1];  // No cost if characters match
            int mismatch = D[i - 1][j - 1] + 1;  // Cost of 1 if characters do not match

            if (str1[i - 1] == str2[j - 1])
                D[i][j] = min({insertion, deletion, match});
            else
                D[i][j] = min({insertion, deletion, mismatch});
        }
    }
    return D[n][m];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
