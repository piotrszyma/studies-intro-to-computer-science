#include <stdio.h>

double intpower(double x, int n);
int ilosc = 0;
int main(void)
{
    double a=0.0, wynik=0.0;
    int b=0;
    printf("Program do potegowania - a ^ b. Podaj a: \n");
    scanf("%lf", &a);
    printf("Podaj b: \n");
    scanf("%d", &b);

    printf("\nWynik: %f", intpower(a, b));

    printf("\nIlosc wymnozen: %d \n", ilosc);
    ilosc = 0;

    return 0;
}

double intpower(double x, int n)
{
    if(n==0)
    {
        return 1;
    }
    else if(n==1)
    {
        return x;
    }
    else if(n%2==0)
    {
        ilosc++;
        return intpower(x, n/2) * intpower(x, n/2);
    }
    else
    {
        ilosc++;
        return intpower(x, n-1) * intpower(x, 1);
    }


}
