/*
Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or 
more blanks by a single blank. 
*/

#include <stdio.h>

int main(void)
{
    int c;
    int last_c = '\0'; // '\0' es EOF

    while ((c = getchar()) != EOF)
    {
        if (c != ' ' || last_c != ' ') // Imprime lo ingresado y si el anterior es espacio lo ignora
        {
            putchar(c);
        }

        last_c = c;
    }

    return 0;
}