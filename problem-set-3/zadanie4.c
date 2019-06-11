#include <stdio.h>


#define WIELKOSC 30

//******************************************

void Rzym(char*, char, char, char, int);

//******************************************


int wielkosc = 0;
int ite = 0;

int main(void)
{
    int arabska;
    int tys=0, set=0, dzie=0, jedn=0;

    printf("Konwerter liczb arabskich na rzymskie\n");
    printf("Podaj liczbe arabska: ");

    scanf("%d", &arabska);

    while(arabska<0||arabska>4000)
    {
    printf("Podaj liczbe z zakresu 0-4000\n");
    scanf("%d", &arabska);

    }
    int liczba=arabska;


    while(arabska>=1000)
    {
        arabska-=1000;
        tys++;
    }


    while(arabska>=100)
    {
        arabska-=100;
        set++;
    }

    while(arabska>=10)
    {
        arabska-=10;
        dzie++;
    }

    while(arabska>0)
    {
        arabska-=1;
        jedn++;
    }

    char rzym[WIELKOSC];


    while(tys>0)
    {
        rzym[ite]='M';
        wielkosc++;
        tys--;
        ite++;
    }
    char a,b,c;


    a='C', b='M', c='D';
    Rzym(rzym, a, b, c, set);

    a='X', b='C', c='L';
    Rzym(rzym, a, b, c, dzie);

    a='I', b='X', c='V';

    Rzym(rzym, a, b, c, jedn);


    ite=0;

    while(ite<wielkosc)
    {
        printf("%c", rzym[ite]);
        ite++;
    }


    return 0;
}


void Rzym(char* rzym, char a, char b, char c, int dzie)
{
    if(dzie==9)
    {
        rzym[ite]=a;
        rzym[ite+1]=b;
        ite+=2;
        wielkosc+=2;
        dzie-=9;
    }
    else if(dzie>=5)
    {
        rzym[ite]=c;
        ite+=1;
        wielkosc+=1;
        dzie-=5;
        while(dzie>0)
        {
            rzym[ite]=a;
            ite+=1;
            wielkosc+=1;
            dzie-=1;
        }
    }
    else if(dzie==4)
    {

        rzym[ite]=a;
        rzym[ite+1]=c;
        ite+=2;
        wielkosc+=2;
        dzie-=4;

    }
    else
    {
        while(dzie>0)
        {
            rzym[ite]=a;
            ite+=1;
            wielkosc+=1;
            dzie-=1;
        }
    }
}
