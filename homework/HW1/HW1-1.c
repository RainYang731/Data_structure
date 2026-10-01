#include <stdio.h>
#include <stdlib.h>
unsigned long long fib(int n)
{
    unsigned long long *data = malloc(3 * sizeof(unsigned long long)),now = 1;
    *data = 0;*(data+now) = 1;
    for(int i=2;i<=n;i++){
        *(data+(now+1)%3) = *(data+now%3)+*(data+(now+2)%3);
        now = (now+1)%3;
    }
    now = *(data+now);
    free(data);
    if(n==0) return 0;
    return now;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%llu\n", fib(n));
    return 0;
}
