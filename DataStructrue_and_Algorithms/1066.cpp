#include <stdio.h>
int main(void)
{
    int Da, Db;
    long A, B, Pa = 0, Pb = 0;

    scanf("%ld %d %ld %d",&A,&Da,&B,&Db);
    do
    {
        if (A % 10 == Da)
            Pa = Pa * 10 + Da;
        A /= 10;
    } while (A >= 1);

     do
    {
        if (B % 10 == Db)
            Pb = Pb * 10 + Db;
        B /= 10;
    } while (B >= 1);

    printf("%ld",Pa+Pb);
    
    return 0;
}