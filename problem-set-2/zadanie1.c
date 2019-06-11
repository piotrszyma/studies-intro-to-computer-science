#include <stdio.h>

int main(void)
{
    int rok;
    printf("Program sprawdza czy podany rok R jest przestepny.\nPodaj rok R: ");
    scanf("%d", &rok);

    if(((rok%4==0)&&(rok%100!=0))||(rok%400==0))
    {
        printf("Rok R jest przestepny");
    }
    else
    {
        printf("Rok R jest zwykly");
    }
    return 0;
}
