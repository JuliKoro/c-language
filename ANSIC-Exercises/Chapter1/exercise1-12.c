// Exercise 1-12. Write a program that prints its input one word per line.

#include <stdio.h>

int main(void)
{
    char c;
    char last_c = -1;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            if (c != last_c) putchar('\n');
        }
        
        else putchar(c); // para imprimir los caracteres unidos y saltear los ' ', '\t' y '\n'

        last_c = c;
    }

    return 0;
}