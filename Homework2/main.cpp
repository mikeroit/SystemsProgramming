#include <iostream>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include "Collection.h"

//Mike's code starts here
//Maze data structure
//

struct Maze
{
    public:
        uint64_t* myMaze; 
        int numRows; 
        int numCols; 
};

void InitializeMaze(Maze &m)
{
    //Constants
    int NUM_ROWS = 32;
    int NUM_COLS = 32;
    int MAZE_ARRAY_SIZE = 16;
    

    //allocate Maze
    m.myMaze = new uint64_t[16];
    //init Maze
    for(int i = 0; i < MAZE_ARRAY_SIZE; i++)
    {
        m.myMaze[i] = 0;
    }
}

void PrintMaze(const Maze &m)
{
    //Constants
    int NUM_ROWS = 32;
    int NUM_COLS = 32;
    int MAZE_ARRAY_SIZE = 16;
    int NUM_BITS = 64;

    //for each of the 16 row structures
    for(int i = 0; i < NUM_ROWS; i++)
    {
        //for each of the 64 bits in the structure
        for(int j = 0; j < NUM_BITS; j++)
        {
            //extract the bit
            int myBit = ((m.myMaze[i] >> j) && 0x00);

            //print based on result
            if(myBit == 0)
            {
                std::cout << " X";
            }
            else
            {
                std::cout << "  ";
            }
        }
        //print a new line
        std::cout << std::endl;
    }
}

void SetWalkable(Maze &m, int row, int column) 
{
    //grab true row index
    int rowIndexInMemory = row / 2;
    //grab true col index
    int colIndexInMemory = column;
    if(! (row % 2 == 0))
    {
        colIndexInMemory += 32;
    }

    //set walkable
    m.myMaze[rowIndexInMemory] = (m.myMaze[rowIndexInMemory] & (0x01 << colIndexInMemory));
}
bool GetCellValue(const Maze &m, int row, int column) 
{
    //grab true row index
    int rowIndexInMemory = row / 2;
    //grab true col index
    int colIndexInMemory = column;
    if(! (row % 2 == 0))
    {
        colIndexInMemory += 32;
    }

    return ((m.myMaze[rowIndexInMemory] >> colIndexInMemory) & 0x01) == 1;
}

int main(int argc, const char * argv[])
{
  //seeding the random number generator
  /*
  srand((int)time(NULL));
  Maze m = MakeMaze();
  PrintMaze(m);
  */
  
  return 0;
}
