#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    n=(n+2)%60;
    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;
    
    for (long long i = 2; i <= n; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%10;
        
    }

    return (current-1+10)%10;
}

int main() {
    long long n ;
    std::cin >> n;
    std::cout << fibonacci_sum_naive(n);
}
