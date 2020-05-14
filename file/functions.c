#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "../header/macros.h"

int countWorld(FILE *file)
{
    int f_len = 0;
    char str[MAX_SIZE] = "";

    while (fgets(str, MAX_SIZE, file) != NULL)
    {
        f_len++;
    }

    return f_len;
}

void randomWorld(FILE *file, int random, char *str)
{
    int i = 1;

    rewind(file);

    while (fgets(str, MAX_SIZE, file) != NULL && i <= random)
    {
        i++;
    }
}

char readCaracter()
{
    char caracter = 0;

    caracter = getchar();
    caracter = toupper(caracter);

    // clear buffer -> read all caracters
    while (getchar() != '\n')
        ;

    return caracter;
}

char *hidden(int len)
{
    int i = 0;
    char *hidden = NULL;

    hidden = malloc(len * sizeof(char));

    if (hidden == NULL)
        exit(0);

    for (i = 0; i < len; i++)
    {
        hidden[i] = '*';
    }

    return hidden;
}

BOOL matches(char l, char *wrd, char *h_wrd)
{
    int i = 0, m = 0, len = strlen(wrd);

    for (i = 0; i < len; i++)
    {
        if (wrd[i] == l)
        {
            h_wrd[i] = wrd[i];
            m++;
        }
    }

    if (m == 0)
        return FALSE;

    return TRUE;
}

BOOL win(char *wrd, char *h_wrd)
{
    int i = 0, len = strlen(wrd) - 1;

    for (i = 0; i < len; i++)
    {
        if (wrd[i] != h_wrd[i])
            return FALSE;
    }

    return TRUE;
}

void displayWin(char *sct_wrd)
{
    printf("Congratulations, the secret word was good : %s\n", sct_wrd);
}
