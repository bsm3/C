#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix
{
    int row, i[3], x[6], y, ch;
    int i1;
    char * arr;

}matrix;


void gotoxy(int, int);
void pr(matrix *, int);
void update(matrix *, int);
void size(matrix *, int);

#endif // MATRIX_H
