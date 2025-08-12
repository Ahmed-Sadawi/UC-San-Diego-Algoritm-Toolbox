#include <iostream>
using namespace std;
int get_change(int m) { //28/10
  int result=0; // 2
  // m = 
  while(m>0)
  {
    result+=(m/10);
    m-=(m/10)*10;
    result+=(m/5);
    m-=(m/5)*5;
    result+=m/1;
    m-=m;
  }
 return result;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
  
}
