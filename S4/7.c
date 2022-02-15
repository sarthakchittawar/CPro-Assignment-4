#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 20
typedef struct sr
{
    char *word;
    int count;
    struct sr *next;
} wordcount;

wordcount *head = NULL;

int bubbleSort(int n, char ans[n][MAXSIZE], int c)
{
    int swap_count = 0;
    if (c == 1)
    {
        return 1;
    }

    for (int i = 0; i < c - 1; i++)
    {
        if (strcmp(ans[i], ans[i + 1]) <= 0)
        {
            continue;
        }
        else
        {
            char tempstr[MAXSIZE];
            swap_count++;

            strcpy(tempstr, ans[i]);
            strcpy(ans[i], ans[i + 1]);
            strcpy(ans[i + 1], tempstr);
        }
    }
    if (swap_count > 0)
    {
        bubbleSort(n, ans, c - 1);
    }
}

int main(int argc, char *argv[])
{
    wordcount *record;

    FILE *fp;
    char asc;
    int count = 0;

    for (int num = 2; num < argc; num++)
    {
        fp = fopen(argv[num], "r");
        char ch[MAXSIZE];
        memset(ch, 0, strlen(ch));
        int checker = 0;
        while (checker == 0)
        {
            if ((asc = fgetc(fp)) == EOF)
            {
                checker = 1;
            }
            if (((int)asc >= 65 && (int)asc <= 90) || ((int)asc >= 97 && (int)asc <= 122))
            {
                strcat(ch, &asc);
            }
            else
            {
                if (strlen(ch) != 0)
                {
                    int flag = 0;
                    for (wordcount *currnode = head; currnode != NULL; currnode = currnode->next)
                    {
                        if (strcmp(currnode->word, ch) == 0)
                        {
                            currnode->count += 1;
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0)
                    {
                        record = (wordcount *)malloc(sizeof(wordcount));
                        record->word = (char *)malloc(strlen(ch) + 1);
                        strcpy(record->word, ch);

                        record->count = 1;
                        record->next = head;
                        head = record;
                        count++;
                    }
                    memset(ch, 0, strlen(ch));
                    continue;
                }
            }
        }
        fclose(fp);
    }
    FILE *fp1;
    fp1 = fopen(argv[1], "w");
    char ans[count][MAXSIZE];
    int c = 0;
    for (wordcount *currnode = head; currnode != NULL; currnode = currnode->next)
    {
        char ch[MAXSIZE];
        memset(ch, 0, strlen(ch));

        for (int i = 0; i < strlen(currnode->word); i++)
        {
            char curr = currnode->word[i];
            if (curr >= 33)
            {
                ch[strlen(ch)] = curr;
            }
        }
        strcpy(ans[c], ch);
        c++;
    }
    bubbleSort(count, ans, c);
    for (int i = 0; i < c; i++)
    {
        for (wordcount *currnode = head; currnode != NULL; currnode = currnode->next)
        {
            if (strcmp(currnode->word, ans[i]) == 0)
            {
                fprintf(fp1, "%s:%d\n", ans[i], currnode->count);
                break;
            }
        }
    }
}