#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(0));
    long int ar[6] = {0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 1000000; i++)
    {
        int x = rand() % 7;
        if (x == 0)
        {
            i--;
            continue;
        }
        else
        {
            ar[x - 1] += 1;
        }
    }
    for (int i = 0; i < 6; i++)
    {
        printf("%ld ", ar[i]);
    }
    printf("\n");
}
