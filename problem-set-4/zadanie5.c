#include <stdio.h>

void RuchySkoczka(int x, int y, int nr_ruchu);

int ruchy[8][2] = {{2, 1}, {2, -1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}};

static int plansza[8][8];

int kolejny(int x, int y);

//***********************************************************************

int main(void)
{

    int x=-1, y=-1;

    while(x<1||x>8||y<1||y>8)
    {
        printf("Podaj wspolrzedne (od 1 do 8) :\n");
        printf("X: ");
        scanf("%d", &x);
        printf("Y: ");
        scanf("%d", &y);
    }

    RuchySkoczka(y-1, x-1, 1);

    return 0;


}
//***********************************************************************

int kolejny(int x, int y)
{
    int min=9;
    int wsp_min=9;
    int pot_min=9;
    int pot_wsp_min=9;
    int a, b;
    int c, d;
    for(int i=0; i<8; i++)
    {
        a = x+ruchy[i][0];
        b = y+ruchy[i][1];

        if(a>=0 && a<8 && b>=0 && b<8 && plansza[a][b]==0)
        {
            pot_min = 0;
            for(int j=0; j<8; j++)
            {
                c = a + ruchy[j][0];
                d = b + ruchy[j][1];

                if(c>=0 && c<8 && d>=0 && d<8 && plansza[c][d]==0)
                {
                    pot_min++;
                }
            }

            if(pot_min<min)
            {
                min = pot_min;
                wsp_min = i;
            }
        }
    }
    return wsp_min;
}



//***********************************************************************


void RuchySkoczka(int x, int y, int nr_ruchu)
{

    if(nr_ruchu > 64)
    {


        printf("\n+----+----+----+----+----+----+----+----+\n");
        for(int i=0; i<8; i++)
        {
            for(int j=0; j<8; j++)
                printf("|%3d ",plansza[i][j]);
            printf("|\n+----+----+----+----+----+----+----+----+\n");
        }
        printf("\n");

        return;
    }
    int z = 0;
    plansza[x][y]=nr_ruchu;
    z = kolejny(x, y);
    x=x+ruchy[z][0];
    y=y+ruchy[z][1];
    RuchySkoczka(x, y, nr_ruchu+1);


}
