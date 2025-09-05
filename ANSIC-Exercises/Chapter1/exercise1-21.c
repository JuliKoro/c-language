/*
Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum 
number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. 
When either a tab or a single blank would suffice to reach a tab stop, which should be given 
preference? 
*/

#include <stdio.h>

#define TAB_LENGTH 8

int main(void)
{
    int c;
    unsigned int line_pos = 0;
    unsigned int nr_of_spaces = 0;

    while ((c = getchar()) != EOF)
    {
        ++line_pos;

        if (c == ' ')
        {
            ++nr_of_spaces;

            if (line_pos % TAB_LENGTH == 0 && nr_of_spaces > 1)
            {
                putchar('\t');
                nr_of_spaces = 0;
            }
        }
        else
        {
            while (nr_of_spaces)
            {
                putchar(' ');
                --nr_of_spaces;
            }

            if (c == '\n')
            {
                line_pos = 0;
            }

            putchar(c);
        }
    }

    return 0;
}

// NOTE: run: ./entab < file_in.txt > file_out.txt