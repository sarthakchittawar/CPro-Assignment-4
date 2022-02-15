#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(0));
    int ar[(int)1e6];
    double c0 = 0, c1 = 0;
    double p0 = 0, p1 = 0;

    for (int i = 0; i < 127; i++)
    {
        ar[i] = rand() % 2;
    }
    for (int i = 127; i < 1e6; i++)
    {
        if (ar[i - 1] != ar[i - 127])
        {
            ar[i] = 1;
            c1 += 1;
        }
        else
        {
            ar[i] = 0;
            c0 += 1;
            if (ar[i - 1] == 0)
            {
                p0 += 1;
            }
            else
            {
                p1 += 1;
            }
        }
    }
    if (ar[(int)1e6 - 1] = 0)
    {
        c0 -= 1;
    }
    printf("Using given formula:\n");
    printf("P(0|0) = %lf\nP(0|1) = %lf\n", p0 / c0, p1 / c0);

    c0 = c1 = p0 = p1 = 0;
    for (int i = 0; i < 1e6; i++)
    {
        ar[i] = rand() % 2;
    }
    for (int i = 127; i < 1e6; i++)
    {
        if (ar[i] == 0)
        {
            c0 += 1;
            if (i != 0)
            {
                if (ar[i - 1] == 0)
                {
                    p0 += 1;
                }
                else
                {
                    p1 += 1;
                }
            }
        }
        else
        {
            c1 += 1;
        }
    }
    if (ar[(int)1e6 - 1] = 0)
    {
        c0 -= 1;
    }
    printf("\n\nUsing rand()%%2 approach:\n");
    printf("P(0|0) = %lf\nP(0|1) = %lf\n", p0 / c0, p1 / c0);
}