#include <stdio.h>

long int next_divisor(long int n, long int s)
{
    for(int i = s; i <= sqrt(n); i++)
    {
        if(n % i == 0) return i;
    }
    return n;
}

int phi(long int n)
{
    long int p = n;
    int long i = 1;
    while (p != 1)
    {
        i = next_divisor(p,i+1);
        if (i == p)
        {
            n -= n/p;
            break;
        }
        n -= n/i;
        while (p % i == 0)
        {
            p /= i;
        }

    }

    return (int)n;
}

int main(void)
{
    long int n;
    printf("Podanie ujemnego n przerywa dzialanie programu.\n");
    while(1)
    {
        printf("Podaj n: ");
        scanf("%ld", &n);
        if(n < 0) break;
        printf("%d\n\n", phi(n));

    }
    return 0;
}
