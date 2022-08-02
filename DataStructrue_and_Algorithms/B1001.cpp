#include <stdio.h>
int main (void)
{
    int step = 0, start, n;
    printf("Please enter the integer number : ");
    while (scanf("%d", &n) != 1)
    {
         printf("Please enter the integer number again : ");
    }
    start = n;
    while (start != 1)
    {
        if (start % 2 == 0)
            start /= 2;
        else
            start = (3 * start +1) /2;
        step += 1;
    }

    printf("%d", step);

    return 0;
}