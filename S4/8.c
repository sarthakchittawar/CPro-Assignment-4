#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 15

int read2();

int read1(FILE *f1, FILE *f2, FILE *f3, char b[])
{
    char a[MAXSIZE];
    if (fscanf(f1, "%s", a) != EOF)
    {
        if (strcmp(a, b) <= 0)
        {
            fprintf(f3, "%s\n", a);
            read1(f1, f2, f3, b);
        }
        else
        {
            fprintf(f3, "%s\n", b);
            read2(f1, f2, f3, a);
        }
    }
    else
    {
        fprintf(f3, "%s\n", b);
        return 1;
    }
}

int read2(FILE *f1, FILE *f2, FILE *f3, char a[])
{
    char b[MAXSIZE];
    if (fscanf(f2, "%s", b) != EOF)
    {
        if (strcmp(a, b) <= 0)
        {
            fprintf(f3, "%s\n", a);
            read1(f1, f2, f3, b);
        }
        else
        {
            fprintf(f3, "%s\n", b);
            read2(f1, f2, f3, a);
        }
    }
    else
    {
        fprintf(f3, "%s\n", a);
        return 2;
    }
}

int main(int argc, char *argv[])
{
    FILE *f1, *f2, *f3, *final;
    int fin;

    f1 = fopen(argv[1], "r");
    f2 = fopen(argv[2], "r");
    f3 = fopen(argv[3], "w");

    char a[MAXSIZE], b[MAXSIZE];
    fscanf(f1, "%s", a);
    fscanf(f2, "%s", b);
    if (strcmp(a, b) <= 0)
    {
        fprintf(f3, "%s\n", a);
        fin = read1(f1, f2, f3, b);
    }
    else
    {
        fprintf(f3, "%s\n", b);
        fin = read2(f1, f2, f3, a);
    }
    if (fin == 2)
    {
        final = f1;
    }
    else
    {
        final = f2;
    }
    while (fscanf(final, "%s", a) != EOF)
    {
        fprintf(f3, "%s\n", a);
    }
}