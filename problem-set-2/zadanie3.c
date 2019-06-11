#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    double a = 1000/M_E; // 1000 / E  (E - stala Eulera)
    double b = 2*M_PI*1000; // 2 * PI * 1000 (PI - stala Pi)
    double c = 0.0005; // 1/2000 = 0.005
    double d = a * pow(b,c); //przyblizenie za pomoc¹ wzoru Stirlinga dla n=1000
    printf("%f", d);
    return 0;
}
