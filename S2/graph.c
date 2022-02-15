#include <stdio.h>

#define MAX 50

int main(int argc, char *argv[])
{
    FILE *fp1;
    fp1 = fopen(argv[1], "r");

    double ar[MAX];
    double sum = 0, sumsq = 0;
    int i = 0;
    while (fscanf(fp1, "%lf", &ar[i]) != EOF)
    {
        sumsq += ar[i] * ar[i];
        sum += ar[i];
        if (i != 0)
        {
            printf("%lf\n", (sumsq - (sum * sum / (i + 1))) / i);
        }
        i++;
    }
    fclose(fp1);
}