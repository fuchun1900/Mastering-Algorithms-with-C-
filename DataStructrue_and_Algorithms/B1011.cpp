#include <stdio.h>
#include <stdbool.h>
int main(void)
{
    int number, start = 0;
    long a, b, c;
    scanf("%d", &number);
    while (start++ < number)
    { 
        scanf("%ld %ld %ld",&a,&b,&c);
       (a + b > c)? printf("Case #%d: true\n",start):printf("Case #%d: false\n",start);
    }

    return 0;
}