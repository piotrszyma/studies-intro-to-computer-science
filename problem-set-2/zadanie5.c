#include <stdio.h>

int main(void)
{
    printf("Liczby doskonale mniejsze od 1000:\n");
    for(int i=1; i<1000; i++)
    {
        if(sum_dzie(i)==i)
        {
            printf("%d\n", i);
        }
    }
    printf("Zaprzyjaznione pary liczb (n, m), gdzie n,m to rozne liczby naturalne mniejsze od 1000\n");
    for(int i=1; i<1000; i++)
    {
        for(int j=i; j<1000; j++)
        {
        if((sum_dzie(i)==j) && (sum_dzie(j)==i) && j!=i)
        {
            printf("(%d, %d); ", i, j);
        }
        }
    }
	return 0;
}

int sum_dzie(int n)
{
    int sum_dzie=0;
    for(int i=1; i<n; i++)
    {
        if(n%i==0) {sum_dzie+=i;}
    }

    return sum_dzie;

}
