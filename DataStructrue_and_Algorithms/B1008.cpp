#include <stdio.h>
#include <stdlib.h>
void move_array(int * arr, int n, int m);
int main(void)
{
    int len;
    int static move;

    scanf("%d %d",&len, &move);
    int * arr = (int *)malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++)
        scanf("%d",&arr[i]);
    move_array(arr,len,move);

    return 0;
}

void move_array(int * arr, int n, int m)
{
    int temp;
    if (arr == NULL)
    {
        puts("Not avlible");
        return;
    }
    for (int i = 0; i < m % n; i++)
    {
        temp = arr[n - 1];
        for (int j = n - 1; j > 0; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[0] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d",arr[i]);
        if (i != n-1)
            putchar(' ');
    }
    free(arr);
}