// Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.

#include <stdio.h> 

#define MAXLINE 1000

int get_line(char line[], int max_line_len);
void remove_trailing_blanks(char line[], int length);

int main(void)
{
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        remove_trailing_blanks(line, len);
        printf("%s", line);
    }

    return 0;
}

/* getline:  read a line into s, return length  */ 
int get_line(char s[], int lim) 
{ 
    int c, i;

    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) 
        s[i] = c; 
    if (c == '\n') { 
        s[i] = c; 
        ++i; 
    } 
    s[i] = '\0';

    while(c != EOF && c != '\n')
    {
        ++i;
        c = getchar();
    }
  
    if (c == '\n')
        ++i;

    return i; 
}

void remove_trailing_blanks(char line[], int length)
{
    int i;
    for (i = length - 2; line[i] == ' ' || line[i] == '\t'; --i)
        ;

    line[i + 1] = '\n';
    line[i + 2] = '\0';
}