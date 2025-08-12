#include <iostream>
#include <vector>
using namespace std;


long long get_fibonacci_partial_sum_naive(long long from, long long to) {
       
    long long pervious = 0;
    long long current  = 1;

    long long to_result=0;
    long long from_result=0;

    from=(from+1)%60;
    to=(to+2)%60;
    if (to < from) to += 60; // Handle wrap-around

    for (long long i = 1; i <= to; ++i) {
       long long tmp_previous = pervious;
        pervious = current;
        current = (tmp_previous + current)%10;

        if(i==from)from_result=pervious;
        if(i==to)to_result=pervious;
        
    }
    return (to_result - from_result+10) % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
