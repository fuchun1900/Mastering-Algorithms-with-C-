#include <stdio.h>
void prt(int n, char c);
int main(void)
{
    int n;
    char c;

    while (scanf("%d %c",&n, &c) != 2)
    {
        printf("Trt again.");
    }
    prt(n,c);

    return 0;
    
}

void prt(int n, char c)
{
    int middle = n / 2;
    for (int i = 0; i <  middle * 2; i++)
    {
        if(i == 0 || i == middle * 2 - 2)
        {
            for (int j = 0; j < n; j++)
                printf("%c", c);
        }
        else if (i % 2 == 0 )
        {
            printf("%c",c);
            for (int j = 1; j < n - 1; j++)
                printf(" ");
            printf("%c",c);
        }
        else
            printf("\n");
    }
}