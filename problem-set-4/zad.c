#include <stdio.h>
int S[8][8];
int ruchy[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};

char skocz(int i,int j,int ruch)
{
    S[i][j]=ruch;
    if(ruch==64)
    {
        printf("\n+----+----+----+----+----+----+----+----+\n");
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
                printf("|%3d ",S[j][i]);
            printf("|\n+----+----+----+----+----+----+----+----+\n");
        }
        printf("\n");
        return 1;
    }
    for(int k=0;k<8;k++)
    {
        int I=i+ruchy[k][0],J=j+ruchy[k][1];
        if(I>=0 && I<8 && J>=0 && J<8 && S[I][J]==0)
            if(skocz(I,J,ruch+1))
                return 1;
    }
    S[i][j]=0;
    return 0;
}

int main(void)
{
    int x, y;
    scanf("%d %d", &x, &y);
    skocz(x-1, y-1, 1);
    return 0;
}
