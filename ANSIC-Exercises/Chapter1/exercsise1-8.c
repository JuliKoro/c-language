// Exercise 1-8. Write a program to count blanks, tabs, and newlines

#include <stdio.h>

int main(void)
{
  int blanks_nr = 0;
  int tabs_nr = 0;
  int newlines_nr = 0;

  char c;

  while ((c = getchar()) != EOF)
  {
    if (c == ' ') // blanks
    {
      ++blanks_nr;
    }
    else if (c == '\t') // tabs
    {
      ++tabs_nr;
    }
    else if (c == '\n') // newlines
    {
      ++newlines_nr;
    }
  }

  printf("blanks_nr: %d\ntabs_nr: %d\nnewlines_nr: %d\n",
         blanks_nr, tabs_nr, newlines_nr);

  return 0;
}