#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void arraySet(int ar[(int)1e6])
{
    int br[(int)1e6];
    if (ar[(int)1e6 - 1] != ar[(int)1e6 - 127])
    {
        br[0] = 1;
    }
    else
    {
        br[0] = 0;
    }
    for (int i = 1; i < 1e6; i++)
    {
        if (i < 127)
        {
            if (br[i - 1] != ar[(int)1e6 + i - 127])
            {
                br[i] = 1;
            }
            else
            {
                br[i] = 0;
            }
        }
        else
        {
            if (br[i - 1] != br[i - 127])
            {
                br[i] = 1;
            }
            else
            {
                br[i] = 0;
            }
        }
    }
    for (int i = 0; i < 1e6; i++)
    {
        ar[i] = br[i];
    }
}
int main(int argc, char *argv[])
{
    FILE *f2;
    f2 = fopen(argv[2], "w");
    srand(time(0));
    int ar[(int)1e6];
    for (int i = 0; i < 127; i++)
    {
        ar[i] = rand() % 2;
        fprintf(f2, "%d", ar[i]);
    }
    for (int i = 127; i < 1e6; i++)
    {
        if (ar[i - 1] != ar[i - 127])
        {
            ar[i] = 1;
        }
        else
        {
            ar[i] = 0;
        }
    }
    FILE *f1;
    f1 = fopen(argv[1], "r");
    unsigned char ch;
    int i = 0;
    FILE *f3;
    f3 = fopen(argv[3], "w");
    while ((fscanf(f1, "%c", &ch)) != EOF)
    {
        int br[8];
        for (int j = 0; j < 8; j++)
        {
            br[7 - j] = (int)ch % 2;
            ch = (ch - br[7 - j]) / 2;
        }
        for (int j = 0; j < 8; j++)
        {
            if (i >= (int)1e6 - 127)
            {
                arraySet(ar);
                i = -127;
            }
            if (br[j] != ar[i + 127])
            {
                fprintf(f3, "%d", 1);
            }
            else
            {
                fprintf(f3, "%d", 0);
            }
            i++;
        }
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}