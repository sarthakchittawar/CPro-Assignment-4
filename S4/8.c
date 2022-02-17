#include <stdio.h>
#include <string.h>

#define MAXLEN 15

int main(int argc, char *argv[])
{
    FILE *f1, *f2, *f3;

    f1 = fopen(argv[1], "r");
    f2 = fopen(argv[2], "r");
    f3 = fopen(argv[3], "w");

    char temp[MAXLEN];
    char new[MAXLEN];
    int flag = 0;
    if (fscanf(f1, "%s", temp) == EOF)
    {
        flag = 1;
    }
    if (fscanf(f2, "%s", new) == EOF)
    {
        flag = 2;
    }
    if (flag == 1)
    {
        fprintf(f3, "%s\n", new);
    }
    else if (flag == 2)
    {
        fprintf(f3, "%s\n", temp);
    }
    else
    {
        if (strcmp(temp, new) <= 0)
        {
            fprintf(f3, "%s\n", temp);
            strcpy(temp, new);
        }
        else
        {
            fprintf(f3, "%s\n", new);
            FILE *fn = f2;
            f2 = f1;
            f1 = fn;
        }
        int a = 0, b = 0;
        flag = 0;
    begin:

        while ((a = fscanf(f1, "%s", new)) != EOF && strcmp(new, temp) <= 0)
        {
            fprintf(f3, "%s\n", new);
        }
        if (a == -1)
        {
            flag = 1;
        }

        fprintf(f3, "%s\n", temp);
        strcpy(temp, new);

        while ((b = fscanf(f2, "%s", new)) != EOF && strcmp(new, temp) <= 0)
        {
            fprintf(f3, "%s\n", new);
        }
        if (b == -1)
        {
            flag = 2;
        }

        fprintf(f3, "%s\n", temp);
        strcpy(temp, new);
        if (flag == 1)
        {
            while (fscanf(f2, "%s", temp) != EOF)
            {
                fprintf(f3, "%s\n", temp);
            }
        }
        else if (flag == 2)
        {
            while (fscanf(f1, "%s", temp) != EOF)
            {
                fprintf(f3, "%s\n", temp);
            }
        }
        else
        {
            goto begin;
        }
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}
