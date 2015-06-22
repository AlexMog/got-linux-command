#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "got.h"

void show_version_info(void)
{
  printf("GoT v%s developped by AlexMog <http://github.com/AlexMog> under the MIT license.\n", VERSION);
}

int main(int argc, char *argv[])
{
  t_quote*	quote;
  int		size, selected;
  t_options	options;

  bzero(&options, sizeof(options));
  if (set_options(&options, argc, argv))
    return (1);
  srand(time(NULL) * getpid());
  quote = NULL;
  if (options.character == NULL || strlen(options.character) == 0)
    quote = get_normal_quote(&size, &selected);
  else
    quote = get_character_quote(&options, &size, &selected);
  if (quote != NULL)
    {
      printf("Quote %d/%d:\n", selected + 1, size);
      printf("%s\n~%s\n", quote->quote, quote->author);
    }
  else
    printf("I can't found any quotes, my lord!\n~GoT, Lord commander of the Linux Commands\n");
  return (0);
}
