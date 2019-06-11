#include <stdio.h>
#include <string.h>


#define DLUGOSC 100

int getString(char s[]);
int czyPalindrom(char*); //deklaracja funkcji czyPalindrom

int main(void)
{
    char linia[DLUGOSC]; //tworzymy tablice znakow zawierajaca palindrom

    printf("Podaj ciag znakow do sprawdzenia:\n");

    getString(linia);


    if(czyPalindrom(linia)) //wywolanie funkcji czyPalindrom
    {
        printf("TAK!\n");
    }
    else
    {
        printf("NIE!\n");
    }

    return 0;
}


int czyPalindrom(char *linia) //definicja funkcji czyPalindrom
{
    int dlugosc=strlen(linia); //sprawdzenie dlugosci palindromu
    for(int i=0, j=dlugosc-1; i<=j; i++, j--) //petla porownujaca znaki w palindromie
    {
        if(linia[i]!=linia[j])
        {
            return 0;
        }

    }
    return 1;
}

int getString(char s[])
{

    char ch;
    int i=0;

    while( (ch = getchar()) != '\n'   &&   ch != EOF )
    {
        s[i] = ch;
        ++i;
    }

    s[i] = '\0';

    fflush(stdin);

    return i;
}
