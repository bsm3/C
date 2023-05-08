#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include "matrix.h"
#include <time.h>

int col;
int row;
int k = 0;
int cou = 2;

int main(void)
{
    int n, n1, cpy_cou = 2;
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    row = w.ws_row;
    col = w.ws_col;
    n = row / 2;
    srand(time(NULL));

    matrix mat[col];

    for(int i = 0; i < col; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            mat[i].x[j] = 1;
            if(j < 3)
                mat[i].i[j] = 0;
        }
        if(i < (col / 2) + (col / 2 / 2))
            mat[i].y = rand() % col + 1;
        mat[i].arr = malloc(sizeof(char) * row);
        mat[i].i1 = 0;
        mat[i].row = 0;
    }

    system("clear");
    printf("\033[?25l");

    while(1)
    {
        for(int i = 0; i < cou; i++)
        {
            mat[i].ch = rand() % 94 + 32;
            if(k < cou)
            {
                size(mat, n);
                k++;
            }
        }
        pr(mat, cou);

        if(cou < (col / 2) + (col / 2 / 2))
            cou += cpy_cou;
    }

    return 0;
}
