/*
Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number 
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. 
Should n be a variable or a symbolic parameter? 
*/

#include <stdio.h>

#define TAB_LENGTH 8

int main(void)
{
    int c;
    unsigned int nr_of_spaces;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            nr_of_spaces = TAB_LENGTH;

            while (nr_of_spaces)
            {
                putchar(' ');
                --nr_of_spaces;
            }
        }
        else 
        {
            putchar(c);
        }
    }
    return 0;
}