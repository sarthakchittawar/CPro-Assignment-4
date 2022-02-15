#include <stdio.h>
#include <stdlib.h>

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
    f2 = fopen(argv[1], "r");
    int ar[(int)1e6];
    
    for (int i = 0; i < 127; i++)
    {
        ar[i] = fgetc(f2) - '0';
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

    FILE *f3;
    f3 = fopen(argv[2], "r");

    FILE *f4;
    f4 = fopen(argv[3], "w");

    char ch;
    int i = 0;
    while ((ch = fgetc(f3)) != EOF)
    {
        int br[8];
        br[0] = ch - '0';
        for (int j = 1; j < 8; j++)
        {
            br[j] = fgetc(f3) - '0';
        }
        int cr[8];
        for (int j = 0; j < 8; j++)
        {
            if (i >= (int)1e6 - 127)
            {
                arraySet(ar);
                i = -127;
            }
            if (br[j] != ar[i + 127])
            {
                cr[j] = 1;
            }
            else
            {
                cr[j] = 0;
            }
            i++;
        }
        int asc = 0;
        for (int j = 0; j < 8; j++)
        {
            if (cr[7 - j] == 1)
            {
                for (int k = 0; k < j; k++)
                {
                    cr[7 - j] *= 2;
                }
                asc += cr[7 - j];
            }
        }
        unsigned char ans = asc;
        fprintf(f4, "%c", ans);
    }

    fclose(f4);
    fclose(f2);
    fclose(f3);
}
