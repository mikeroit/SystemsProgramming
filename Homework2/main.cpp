#include <iostream>
#include <cstdint>
#include <time.h>
#include <stdlib.h>
#include "Collection.h"

int main(int argc, const char * argv[])
{
  //seeding the random number generator
  srand((int)time(NULL));
  Maze m = MakeMaze();
  PrintMaze(m);
  
  return 0;
}