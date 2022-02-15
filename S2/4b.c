#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2, *fp3;
    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "r");
    fp3 = fopen(argv[3], "w");

    double count = 0, sumsq = 0, num = 0, mean = 0, variance = 0;

    fscanf(fp2, "%lf", &mean);

    while (fscanf(fp1, "%lf", &num) != EOF)
    {
        sumsq += num * num;
        count++;
    }
    variance = sumsq / count - mean * mean;
    fprintf(fp3, "%lf\n", variance);
}