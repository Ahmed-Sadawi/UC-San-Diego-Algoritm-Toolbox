#include <iostream>
#include <vector>
using namespace std;


long long find_pisano_per(long long m)
{
    int i;
    long long pervious=0, current =1, next;
    for (i=0; i<m*m; i++)
    {
        next=(pervious+current)%m;
        pervious=current;
        current=next;

        if(pervious==0 && current==1)return i+1;
    }
    return i+1;
}
long long get_fibonacci_huge_naive(long long n, long long m) 
{
    long long pisano_per = find_pisano_per(m);
    long long reduce_n = n%pisano_per;
    long long previous = 0;
    long long current  = 1;

    for (long long i = 1; i <reduce_n; ++i)
    {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%m;
    }

    return reduce_n == 0 ? 0 : current;
}



int main() {
    long long n, m;
    std::cin >> n >> m;
    cout<<find_pisano_per(m)<<endl;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
