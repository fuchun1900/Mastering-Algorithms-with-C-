#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int schoolNo, score, n, *school, *scores ,max = 0;

    scanf("%d", &n);
    scores = (int * )calloc(n, sizeof(int));
   for (int i = 0; i < n; i++)
   {
        while (scanf("%d%d", &schoolNo, &score) != 2)
        { }
        scores[schoolNo - 1] += score;
   }
    
   for (int i = 0; i < n; i++)
   {
        if (scores[i] > max)
        {
            max = scores[i];
            schoolNo = i + 1;
        }
   }
   printf("%d %d",schoolNo,max);

   free(scores);
   return 0;

}