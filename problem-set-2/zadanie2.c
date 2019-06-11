#include <stdio.h>

int main(void)
{
    float suma=0.0;
    int n=0;

    for(float i=1.0; i>0; i++)
    {
        suma+=(1/i);
        n=i;
        if(suma>=10.0){break;}
    }

    printf("%d", n);

    return 0;
}
