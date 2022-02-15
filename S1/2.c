#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(0));
    long int ar[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 1000000; i++)
    {
        int x = rand() % 7;
        int y = rand() % 7;
        if (x == 0 || y == 0)
        {
            i--;
            continue;
        }
        else
        {
            ar[x + y - 1] += 1;
        }
    }
    for (int i = 1; i < 12; i++)
    {
        printf("%ld ", ar[i]);
    }
    printf("\n");
}