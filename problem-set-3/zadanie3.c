#include <stdio.h>
#include <math.h>


double f(double x);
double rozwiazanie(double a, double b, double eps);
double max(double, double);
double min(double, double);

int main(void)
{
    double a=1.0, b=0.0, eps;
    while(a>b)
    {
        printf("Podaj a:");
        scanf("%lf",&a);
        printf("Podaj b:");
        scanf("%lf",&b);
        printf("Podaj epsilon [w postaci 10^(-k), gdzie k nalezy do calkowitych] (np 0.0001):");
        scanf("%lf",&eps);
    }
    rozwiazanie(a,b,eps);

    return 0;
}


double rozwiazanie(double a, double b, double eps)
{
    double epsk=0.0;
    while(eps!=1)
    {
        eps*=10.0;
        epsk+=1.0;
    }
    double dokladnosc = 1.0;
    double k=1.0;

    while(k<=epsk)
    {
        dokladnosc*=0.1;
        double x = 0.0;
        while(1)
        {
            if(f(a+x*dokladnosc) * f(a+(x+1)*dokladnosc) <= 0 )
            {
                a = a+x*dokladnosc;
                break;
            }
            x+=1.0;
        }
        k+=1.0;
    }

    printf("%0.10f\n", a);

    return 0;
}


double f(double x)
{
    return cos(x/2.0);
}
