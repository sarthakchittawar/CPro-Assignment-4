#include <stdio.h>
#include <string.h>
int charcount(int num, char *argv[], int n, int m, int ar[n][m])
{
    for (int i = 0; i < 95; i++)
    {
        ar[i][0] = 32 + i;
    }

    int asc;
    FILE *fp;
    fp = fopen(argv[num], "r");
    while ((asc = fgetc(fp)) != EOF)
    {
        ar[asc - 32][1] += 1;
    }
    fclose(fp);
}
int main(int argc, char *argv[])
{
    int ar[95][2];
    for (int i = 0; i < 95; i++)
    {
        ar[i][0] = 32 + i;
        ar[i][1] = 0;
    }
    FILE *fp;
    for (int i = 2; i < argc; i++)
    {
        charcount(i, argv, 95, 2, ar);
    }

    FILE *fp1;
    fp1 = fopen(argv[1], "w");
    for (int i = 0; i < 95; i++)
    {
        if ((48 <= ar[i][0] && ar[i][0] <= 57) || (65 <= ar[i][0] && ar[i][0] <= 90) || (97 <= ar[i][0] && ar[i][0] <= 122))
        {
            fprintf(fp1, "%c:%d\n", ar[i][0], ar[i][1]);
        }
    }
    fclose(fp1);
    return 0;
}
