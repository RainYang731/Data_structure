#include <stdio.h>

/* Complete fib_tail only. fib and main are already written - do not change them.
   a and b hold two consecutive Fibonacci numbers. The recursive call must be the last thing
   this function does. */
unsigned long long fib_tail(int n, unsigned long long a, unsigned long long b)
{
    if(n==0) return a;
    return fib_tail(n-1,b,a+b);
}

unsigned long long fib(int n)
{
    return fib_tail(n, 0, 1);
}

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%llu\n", fib(n));
    return 0;
}
