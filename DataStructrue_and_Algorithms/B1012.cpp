#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void calculate(int * arr , int n);
int main(void)
{
    int * arr, n;
    double A4;

    while (scanf("%d",&n) != 1)
    {
        while (getchar() != '\n')
            continue;
        puts("Please try again.");
    }
    arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d",&arr[i]);
    calculate(arr,n);
    
    return 0;
}

void calculate(int * arr, int n)
{
    int A1 = 0, A3 = 0, A5 = 0, count1 = 0 ,count2 = 0;
    double A4  = 0.0 , A2 = 0.01;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 5 == 0 && arr[i] % 2 == 0)
            A1 += arr[i];
        if (arr[i] % 5 == 1)
            A2 = A2 + pow(-1, count1++ ) * arr[i];
        if (arr[i]% 5 == 2)
            A3++;
        if (arr[i] % 5 == 3)
        {
            count2 ++;
            A4 += arr[i];
        }
        if (arr[i] % 5 == 4)
        {
            if(arr[i] > A5)
                A5 = arr[i];
        }
    }
    (A1 != 0)? printf("%d ",A1) : printf("N ");
    (A2 != 0.01)? printf("%.0lf ",A2 - 0.01) : printf("N ");
    (A3 != 0)? printf("%d ",A3) : printf("N ");
    (A4 != 0.0)? printf("%.1lf ",A4 / count2) : printf("N ");
    (A5 != 0.0)? printf("%d",A5) : printf("N");
    free(arr);
}