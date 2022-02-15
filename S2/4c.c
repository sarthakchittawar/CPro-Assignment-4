#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2, *fp3;
    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "r");
    fp3 = fopen(argv[3], "w");
    
    double mean;
    fscanf(fp2, "%lf", &mean);

    double rcount = 0, count = 0, temp;
    while (fscanf(fp1, "%lf", &temp) != EOF)
    {
        if (0.8 * mean <= temp && temp <= 1.2 * mean)
        {
            rcount++;
        }
        count++;
    }
    double perc = rcount / count * 100;
    fprintf(fp3, "%lf", perc);

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}