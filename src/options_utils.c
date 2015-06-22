#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "got.h"

int set_options(t_options *options, int argc, char **argv)
{
  int	c;

  while ((c = getopt(argc, argv, "vc:h")) != -1)
    switch (c)
      {
      case 'v':
	show_version_info();
	return (1);
	break;
      case 'c':
	options->character = optarg;
	break;
      case 'h':
	printf("GoT Help:\n"
	       "Usage: %s [-options]\n"
	       "Options:\n"
	       "v: show version info\n"
	       "h: show help\n"
	       "c CHARACTER: select a CHARACTER's quotes\n",
	       argv[0]);
	return (1);
	break;
      case '?':
	if (optopt == 'c')
	  fprintf(stderr, "Option -%c requires an argument.\n", optopt);
	else if (isprint(optopt))
	  fprintf(stderr, "Unknow option '-%c'.\nUse -h for help\n", optopt);
	else
	  fprintf(stderr, "Unknow option character '\\x%x'.\nUse -h for help\n", optopt);
	return (1);
      default:
	abort();
      }
  return (0);
}
