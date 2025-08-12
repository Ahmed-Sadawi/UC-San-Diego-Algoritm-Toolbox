#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
// we need to compute this ac*10^n +((a+b)(c+d)-ac-a=bd)10^m+bd 
long long int karatsupa( long long x, long long y){
    if(x <10 || y<10)return x*y;//base case 

   int n = max((int)log10(x)+1, (int)log10(y)+1);//number of digits
   int m = n/2;  

    long long high_x=x/pow(10,m);
    long long low_x=x%(long long)pow(10,m);
    long long high_y=y/pow(10,m);
    long long low_y=y%(long long)pow(10,m);

    long long ac = karatsupa(high_x,high_y);
    long long mid = karatsupa(high_x+low_x,high_y+low_y);
    long long bd = karatsupa(low_x,low_y);

    return ac*pow(10,m*2)+(mid-ac-bd)*pow(10,m)+bd;
}
int main() {
    long long num1, num2;
    cout << "Enter two numbers to multiply: ";
    cin >> num1 >> num2;

    cout << "Product: " << karatsupa(num1, num2) << endl;
    return 0;
}
