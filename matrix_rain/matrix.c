#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "matrix.h"
#include <time.h>
#include <unistd.h>


#define COLOR_1 "\033[38;5;15m"
#define COLOR_2 "\033[38;5;83m"
#define COLOR_3 "\033[38;5;28m"
#define COLOR_4 "\033[38;5;240m"
#define COLOR_5 "\033[38;5;238m"
#define RES "\033[0m"

#define BOLD "\033[1m"

extern int col;
extern int row;
extern int k;

void gotoxy(int x, int y)
{
    printf("\033[%d;%dH", x, y);
}

void update(matrix * mat, int i)
{
    mat[i].x[0] = 1;
    mat[i].x[1] = 1;
    mat[i].x[2] = 1;
    mat[i].x[3] = 1;
    mat[i].x[4] = 1;
    mat[i].i1 = 0;
    mat[i].i[0] = 0;
    mat[i].i[1] = 0;
    mat[i].i[2] = 0;
    mat[i].y = rand() % col + 1;
}

void size(matrix * mat, int n)
{
    mat[k].row = rand() % (n+1) + n;
}

void pr(matrix * mat, int count)
{
    for (int i = 0; i < count; i++)
   {
       if (mat[i].row >= mat[i].x[0])
       {
           gotoxy(mat[i].x[0], mat[i].y);
           printf(BOLD);
           printf(COLOR_1);
           printf("%c", mat[i].ch);
           fflush(stdout);
           mat[i].x[0]++;
       }
   }
   usleep(120000);

   for (int i = 0; i < count; i++)
   {
       if (mat[i].row >= mat[i].x[1])
       {
           gotoxy(mat[i].x[1], mat[i].y);
           printf(COLOR_2);
           printf("%c", mat[i].ch);
           fflush(stdout);
           mat[i].x[1]++;
       }
   }

   for (int i = 0; i < count; i++)
   {
       if(mat[i].i1 <= mat[i].row)
       {
           mat[i].arr[mat[i].i1] = mat[i].ch;
           mat[i].i1++;
       }
   }

   for (int i = 0; i < count; i++)
   {
       if (mat[i].i1 > mat[i].row / 2 / 2 && mat[i].i[0] <= (mat[i].row / 2 / 2) + 1)
       {
           gotoxy(mat[i].x[2], mat[i].y);
           printf(COLOR_3);
           printf("%c", mat[i].arr[mat[i].i[0]]);
           fflush(stdout);
           mat[i].x[2]++;
           mat[i].i[0]++;
       }
   }

   for (int i = 0; i < count; i++)
   {
       if (mat[i].i1 >= mat[i].row / 2 && mat[i].x[3] <= mat[i].row / 2 + 1)
       {
           gotoxy(mat[i].x[3], mat[i].y);
           printf(COLOR_4);
           printf("%c", mat[i].arr[mat[i].i[1]]);
           fflush(stdout);
           mat[i].x[3]++;
           mat[i].i[1]++;
       }
   }


   for (int i = 0; i < count; i++)
   {
       if(mat[i].x[0] >= mat[i].row)
       {
           mat[i].arr[mat[i].i[2]] = ' ';
           gotoxy(mat[i].x[4], mat[i].y);
           printf(" ");
           fflush(stdout);
           mat[i].x[4]++;
           mat[i].i[2]++;
       }
   }

   for (int i = 0; i < count; i++)
   {
       if (mat[i].x[4] > row)
       {
           update(mat, i);
       }
   }
}
