#include <stdio.h>
int main(void)
{
    short number, Ashout, Apaddle, Bshout, Bpaddle;
    int Alose = 0, Blose = 0;

    scanf("%hd",&number);
    while (number--)
    {
        scanf("%hd %hd %hd %hd",&Ashout,&Apaddle,&Bshout,&Bpaddle);
        if ((Ashout + Bshout == Apaddle) && (Ashout + Bshout == Bpaddle))
            continue;
        else if (Ashout + Bshout == Bpaddle)
            Alose++;
        else if (Ashout + Bshout == Apaddle)
            Blose++;
        else
            continue;
    }
    printf("%d %d",Alose,Blose);

    return 0;
}