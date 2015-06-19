#include <stdlib.h>

int get_random(int min, int max)
{
  return rand() % (max - min) + min;
}
