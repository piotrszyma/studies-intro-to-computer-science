#include <stdio.h>

int x = 0;
void Perm(int*,int);
void Show(int *tab);
int main(void)
{



    int n,*ptr;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    ptr=(int*)calloc(n+1,sizeof(int));

    for(int i=0; i<n; i++)
    {
        ptr[i] = i+1;
    }
    ptr[n]=-1;

    Perm(ptr, n);

    return 0;
}

static int iter = 1;


void Perm(int *tab, int n)
{

    if(n==1)
    {
        printf("%02d. ", iter);
        Show(tab);
        iter++;
        printf("\n");

    }
    else
    {
        for(int i=0; i<n; i++)
        {
            swap(tab, i, n-1);
            Perm(tab, n-1);
            swap(tab, i, n-1);
        }

    }

}

void Show(int *tab)
{
    int i=0;
    while(tab[i]!=-1)
    {
        printf("%d ", tab[i]);
        i++;
    }
    i=0;
}
void swap(int *tab, int x, int y)
{
    int tmp;
    tmp = tab[x];
    tab[x] = tab[y];
    tab[y] = tmp;
}
