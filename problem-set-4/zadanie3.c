#include <stdio.h>

int main()
{
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter k: ");
    scanf("%d",&k);

    Combination(n, k);

    return 0;
}

Combination(int n, int k)
{
    int *data;

    data=(int*)calloc(k,sizeof(int));

    Comb(n, k, data, 0, 1);

    free(data);

}

static int iter = 1;

Comb(int n, int k, int *data, int index, int start)
{
    if(index==k)
    {
        printf("%03d. ", iter);
        for(int i=0; i<k; i++)
        {

            printf("%3d ", data[i]);

        }
        iter++;
        printf("\n");
        return;
    }
    else
    {
        for(int j=start; j<=n-k+index+1; j++)
        {

            data[index] = j;

            Comb(n, k, data, index+1, j+1);

        }
    }
}
