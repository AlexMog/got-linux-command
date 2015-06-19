#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "got.h"

int main(void)
{
  t_quote *quote;

  srand(time(NULL) * getpid());

  quote = &got_quotes[get_random(0, GOT_QUOTES_SIZE - 1)];
  printf("%s\n~%s\n", quote->quote, quote->author);
  return (0);
}
