#include <stdio.h>

#define WIELKOSC 5000

void mnozenie(int* tab1, int* tab2); //zwraca iloczyn tab1 * tab2 do tab1

void konw(int n, int* tab); //konwertuje n do tablicy tab
void zeruj(int*);
int rozm(int* tab);
void wyswodw(int*);


int main(void)
{

    int tablica1[WIELKOSC], tablica2[WIELKOSC];

    int n=0;

    scanf("%d", &n);

    konw(n, tablica1); //100
    konw(n-1, tablica2); //99
    n-=2;

    while(n>0)
    {
        mnozenie(tablica1, tablica2);

        konw(n, tablica2);

        n--;
    }

    wyswodw(tablica1);





    return 0;
}

//******************************************************************************
void konw(int n, int* tab)
{
    tab[0]=0;
    tab[1]=-1;
    int ite=0;
    while(n>0)
    {
        tab[ite]=n%10;
        n/=10;
        ite++;
    }

    tab[ite]=-1;

}

//******************************************************************************

void mnozenie(int* tab1, int* tab2)
{
    int tab3[WIELKOSC];

    int x=0, y=0;

    int rozmiar=0;
    while(tab2[x]!=-1)
    {

        while(tab1[y]!=-1)
        {

            tab3[x+y]+=tab2[x]*tab1[y];
            rozmiar=x+y;
            y++;
        }
        y=0;


        x++;
    }
    tab3[rozmiar+1]=-1;



    x=0;




    x=1;


    while(tab3[x]!=-1)
    {

        tab3[x]+=tab3[x-1]/10;
        x++;
    }


    x=1;


    while(tab3[x]!=-1)
    {

        tab3[x-1]%=10;
        x++;
    }




    x=0;
    while(tab3[x]!=-1)
    {

        if(tab3[x+1]==-1)
        {

            if(tab3[x]<10)
            {
                tab3[x]%=10;
            }
            else
            {
                tab3[x+2]=-1;
                tab3[x+1]=tab3[x]/10;
                tab3[x]%=10;
            }

        }
        x++;
    }




    x=0;


    while(tab3[x]!=-1)
    {
        tab1[x]=tab3[x];
        x++;
    }
    tab1[x]=-1;

    zeruj(tab3);



}


//******************************************************************************

int rozm(int* tab)
{


    int n=-1;

    while(tab[n]!=-1)
    {
        n++;
    }


    return n;
}



void wyswodw(int* tablica1)
{

    int rozmiar=rozm(tablica1)-1;

    while(rozmiar>=0)
    {
        printf("%d", tablica1[rozmiar]);
        rozmiar--;
    }

    printf("\n");

}

void zeruj(int* tab)
{
    int i=0;
    while(tab[i]!=-1)
    {
        tab[i]=0;
        i++;
    }

    tab[i]=0;
}
