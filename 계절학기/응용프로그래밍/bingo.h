#ifndef BINGO_H
#define BINGO_H

#define SIZE 5

extern int ubingo[SIZE][SIZE];
extern int cbingo[SIZE][SIZE];
extern int checked[25];
extern int count;

void initialize();
void erase_bingo(int arr[][SIZE], int number);
void print_bingo(int arr[][SIZE]);
void print_winner(int winner);
int get_number(int from);
int check_bingo(int arr[][SIZE]);
void swap(int *x, int *y);
void set_rand(int *array);

#endif