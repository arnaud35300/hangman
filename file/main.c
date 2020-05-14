#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../header/macros.h"
#include "../header/functions.h"

int main(int argc, char *argv[])
{
    int i = 0, f_len = 0, random = 0;
    char letter = 0, world[MAX_SIZE] = "", *hidden_world = NULL, round = 0;

    // file
    FILE *file = NULL;
    file = fopen("world.txt", "r");

    if (file == NULL)
        exit(0);

    f_len = countWorld(file);

    srand(time(NULL));
    random = (rand() % (f_len - MIN + 1)) + MIN;

    // assign world
    randomWorld(file, random, world);

    fclose(file);

    printf("Welcome to the hangman !\n");

    hidden_world = hidden(strlen(world) - 1);

    for (i = 0; i < REPLAY; i++)
    {
        printf("you have %d moves left to play\n", (REPLAY - i));
        printf("What is the secret world ? %s \n", hidden_world);

        letter = readCaracter();
        round = matches(letter, world, hidden_world);

        if (round)
            i--;

        if (win(world, hidden_world))
        {
            displayWin(world);
            return 0;
        }
    }
    return 0;
}