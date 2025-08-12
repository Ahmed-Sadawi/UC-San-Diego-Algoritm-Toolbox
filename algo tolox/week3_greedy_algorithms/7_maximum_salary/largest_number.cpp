#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using std::vector;
using std::string;

string largest_number(vector<string> a) {
  sort(a.begin(), a.end(), [](const string &a, const string &b){
    return (a+b)>(b+a);
  });

  std::stringstream ret;
   for(auto &i : a)
   {
    ret<<i;
   }
   string result;
  ret >> result;
  return result;
  }
  


int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
