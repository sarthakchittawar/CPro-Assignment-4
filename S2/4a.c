#include <stdio.h>

int main(int argc, char *argv[])
{
    double count = 0, temp, var, sum = 0;
    double mean, variance;

    FILE *fp1, *fp2;
    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "w");

    while (fscanf(fp1, "%lf", &temp) != EOF)
    {
        count++;
        sum += temp;
    }
    mean = sum / count;

    fprintf(fp2, "%lf\n", mean);

    fclose(fp1);
    fclose(fp2);

    /*fseek(fp, 0, 0);

    count = 0, sum = 0, var = 0, temp = 0, mean = 0, variance = 0;
    while (fscanf(fp, "%lf", &temp) != EOF)
    {
        count++;
        sum += temp;
        var += temp * temp;
        mean = sum / count;
        variance = var / count - mean * mean;
        printf("%lf\n", variance);
    }

    fseek(fp, 0, 0);
    double rcount = 0;
    while (fscanf(fp, "%lf", &temp) != EOF)
    {
        if (0.8 * mean <= temp && temp <= 1.2 * mean)
        {
            rcount++;
        }
    }

    double perc = rcount / count * 100;
    printf("\n%lf %%\n", perc);
    fclose(fp);*/
}
