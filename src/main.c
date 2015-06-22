#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "got.h"

int main(void)
{
  t_quote	quote;
  int		size, selected;

  srand(time(NULL) * getpid());

  size = (int)(sizeof(got_quotes) / sizeof(got_quotes[0]));
  selected = get_random(0, size);

  printf("Quote %d/%d:\n", selected + 1, size);
  quote = got_quotes[selected];
  printf("%s\n~%s\n", quote.quote, quote.author);
  return (0);
}
