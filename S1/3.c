#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef long long ll;

const int MAX = 9;

int main(void)
{
    ll maxno = 10;

    for (int count = 0; count < MAX; count++)
    {
        srand(time(0));
        double x, y;
        int c = 0;
        for (int i = 0; i < maxno; i++)
        {
            x = (double)rand() / RAND_MAX;
            y = (double)rand() / RAND_MAX;

            if (floor(x) >= 1 && x != 1)
            {
                x -= floor(x);
            }
            else if (floor(x) <= -2)
            {
                x += floor(x);
            }
            if (floor(y) >= 1 && y != 1)
            {
                y -= floor(y);
            }
            else if (floor(y) <= -2)
            {
                y += floor(y);
            }
            if (x * x + y * y < 1)
            {
                c += 1;
            }
        }
        printf("%lf\n", (double)c / ((double)maxno + 1) * 4);
        maxno *= 10;
    }
}