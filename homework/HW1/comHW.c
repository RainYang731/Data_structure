#include <stdio.h>
#include <time.h>
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
    int n, k;
    volatile int vn;                     /* 見下方註解 */
    volatile unsigned long long sink;    /* 見下方註解 */
    struct timespec t0, t1;
    int i;

    printf("輸入k值:");
    scanf("%d", &k);

    while(1){
        printf("輸入n值:");
        scanf("%d", &n);
        if(n==0)return 0;
        vn = n;

        clock_gettime(CLOCK_MONOTONIC, &t0);
        for (i = 0; i < k; i++) sink = fib(vn);
        clock_gettime(CLOCK_MONOTONIC, &t1);

        printf("F(%d) = %llu\n", n, sink);
        printf("%.3f us per call (k = %d)\n",
            ((double)(t1.tv_sec - t0.tv_sec) * 1e9 +
                (double)(t1.tv_nsec - t0.tv_nsec)) / 1000.0 / k, k);
        printf("\n");
    }
    return 0;
}


