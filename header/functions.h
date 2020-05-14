#ifndef FUNCTIONS
#define FUNCTIONS

int countWorld(FILE *file);
void randomWorld(FILE *file, int random, char *str);
char readCaracter();
char *hidden(int len);

BOOL matches(char l, char *wrd, char *h_wrd);
BOOL win(char *wrd, char *h_wrd);
void displayWin(char *sct_wrd);

#endif