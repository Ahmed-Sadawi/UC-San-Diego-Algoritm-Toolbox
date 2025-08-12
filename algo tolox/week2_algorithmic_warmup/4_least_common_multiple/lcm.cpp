#include <iostream>
using namespace std;
long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}
int gcd_opt(int a, int b) {
	if (b == 0)
		return a;
	int a_prime = a % b;
	return gcd_opt(b, a_prime);
}
long long int  icm_opt(long long int a, long long int b)
{
 long long int icm = (a*b)/gcd_opt(a,b);
  return icm;
}


int main() {
  int a, b;
  std::cin >> a >> b;
  //std::cout << lcm_naive(a, b) << std::endl;
  cout<<icm_opt(a,b);
  return 0;
}
