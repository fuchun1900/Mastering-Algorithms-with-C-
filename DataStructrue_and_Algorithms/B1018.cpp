#include <stdio.h>
#include <stdlib.h>
int trans(char c);
char maxwin(char * carr, int * arr);
int main(void)
{
    int num, awin = 0, alose = 0, bwin = 0, blose = 0, adraw = 0, bdraw = 0;
    char * a, * b;

    while (scanf("%d",&num) != 1)
    {
        while (getchar() != '\n')
            continue;
        puts("Please try again.");
    }
    a = (char * )malloc(num * sizeof(char));
    b = (char * )malloc(num * sizeof(char));
    char c[3] = {'B','C','J'};
    int acount[3] = {0};
    int bcount[3] = {0};
    for (int i = 0; i < num; i++)
    {
        while ((a[i] = getchar()) == ' ' || a[i] == '\n' )
            continue;
        while ((b[i] = getchar()) == ' ' || b[i] == '\n' )
            continue;
    }
    for (int i = 0; i < num; i++)
    {
        if (trans(a[i]) != -1 && trans(b[i]) != -1)
        {
            int result = (trans(a[i]) - trans(b[i]) + 4) % 3 - 1;
            switch (result)
            {
            case -1:
                awin++;
                blose++;
                acount[trans(a[i])]++;
                break;
            case 0:
                adraw++;
                bdraw++;
                break;
            case 1:
                alose++;
                bwin++;
                bcount[trans(b[i])]++;
                break;
            default:
                break;
            }
        }
        else
        {
            printf("wrong inout");
            free(a);
            free(b);
            return 0;
        }
    }
    printf("%d %d %d\n",awin,adraw,alose);
    printf("%d %d %d\n",bwin,bdraw,blose);
    printf("%c %c",maxwin(c,acount),maxwin(c,bcount));
    
    free(a);
    free(b);
    return 0;
    
}

int trans(char c)
{
    switch (c)
    {
    case 'B':
        return 0;
    case 'C':
        return 1;
    case 'J':
        return 2;
    default:
        return -1;
    }
}


char maxwin(char * carr, int * arr)
{
    int max = 0, count;
    for (int i = 0; i < 3; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
            count = i;
        }
    }
    return carr[count];
}