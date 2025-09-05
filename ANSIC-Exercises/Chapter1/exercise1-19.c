// Exercise 1-19. Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its input a line at a time.  

#include <stdio.h> 

#define MAXLINE 1000

int get_line(char line[], int max_line_len);
int length(char line[]);
void reverse(char line[]);

int main(void)
{
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        reverse(line);
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
  
    // flush out input stream if exceeding lim limit
    while (i >= lim - 1 && (c = getchar()) != '\n')
        ;
    if (c == '\n')
        ++i;

    return i; 
}

int length(char line[])
{
    int i;
    for (i = 0; line[i] != '\0'; i++)
        ;
    
    return i;
}

void reverse(char line[])
{
    int i_front = 0;
    int i_back = length(line);
    char temp;

    if(line[i_back - 1] == '\n') // hay un '\n'
    {
        i_back -= 2; // que empiece dos lugares atras
    }
    else // hay solo un '\0'
    {
        i_back -= 1;
    }

    while (i_back > i_front)
    {
        temp = line[i_front];
        line[i_front] = line[i_back];
        line[i_back] = temp;

        ++i_front;
        --i_back;
    }
}