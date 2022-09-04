/*
* https://www.acmicpc.net/problem/6064
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main(void)
{
    int T, M, N, x, y, i;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &M, &N, &x, &y);
        int limit = lcm(M, N);
      
        for (i = x; i <= limit; i += M) {
            int temp = (i % N == 0) ? N : i % N;
            if (temp == y) {
                printf("%d\n", i);
                break;
            }
        }
        if (i > limit)
            printf("-1\n");
    }
    return 0;
}
