Please read the instructions carefully before starting the assignment

Overview

In this assignment you will implement code to randomly generate a maze.  The maze your code produces is a 32 x 32 grid stored in a flattened bit array where each cell is a one bit value of 0 - blocked off wall or 1 - passage.  When a cell is a passage then the four neighboring cells to its north, south, east and west will be walls.  The algorithm used is a backtracking random walk that starts by opening the cell in the center of the grid and then at every iteration the algorithm picks a random neighbor of the current open cell and sets it to 1 as well as the wall cell between the two cells.  The cells processed will be stored in a collection data structure provided for you for this purpose.  Once the generation of the maze is complete, you will print the maze using ASCII symbols as follows, if the cell is a wall then you will display " X" (note the extra space before X) and if the cell is open then you will display two empty spaces "  ".  Here is a sample of a generated maze using the algorithm described below and you can verify that you can reach any open cell from any other open cell:

Screen Shot 2016-01-13 at 8.48.52 PM.png

Starter Code:

The following zip file (HW2-starter.zipView in a new window) includes the following:

main.cpp - your code goes here
Collection.cpp, Collection.h  - Code provided for you to help you write the makeMaze function (see below).
Representation:

The grid is a 32 x 32 bit array where each cell is one bit
You will use uint64_t to store the cells so each uint64_t will store two rows of the grid.  Therefore you will need 16 uint64_t integers for the grid stored in a 1-dimensional array.
The array belongs to a struct that also owns two int variables storing the width (columns) and height (rows) of the grid.
For each cell/bit the value 0 is blocked or wall while the value 1 is an open room.
Printing the maze:

You will print the maze in ASCII characters based on the value of the cell/bit. 
If the bit is 0 then you print " X" (a space and X) 
If the bit is 1 then you print "  " (two spaces)
The extra space is to increase the width of the maze so it is closer to a square.
Structs and Functions Provided in Collection:

The following structs and functions are provided for you to help you complete the function that generates the maze:

struct Cell consisting of two integers: row and column representing the row and the column of a cell.
struct Collection: this struct holds the cells opened up by the algorithm (look at pseudo code below).
The following functions used to manipulate the Collection struct:
void AddCell(Collection& col, int row, int column) :  Adds the cell (row, column) to the collection

void RemoveCell(Collection& col, Cell c) :  Removes the cell (row, column) from the collection

Cell GetRandomCell(const Collection& col) :  Returns a Cell selected at random from the collection

bool CollectionIsEmpty(const Collection& col) : Returns true if the collection is empty and false otherwise

Structs and Functions to Implement:

The following structs and functions should be implemented by the student.  You are always welcome to add more functions to the list if you feel they are appropriate.

struct Maze : consists of an array of 16 uint64_t, the number of rows and number of columns in the maze
The following functions:
void InitializeMaze(Maze& m) : initializes the variables of the struct and populates all cells with value 0.

void PrintMaze(const Maze& m) : prints the maze passed

void SetWalkable(Maze& m, int row, int column) : for the given row and column, set the value of the bit to 1

bool GetCellValue(const Maze& m, int row, int column) : Return the value of the bit corresponding to row and column.
Maze MakeMaze( ) : Generate a random maze and return the maze

Pseudo Code for Maze Generation: 

The following is the algorithm used to generate the maze:

 Initialize maze by setting all cells to walls (0)
 declare a collection cellsToExpand to store cells explored
 add center cell to cellsToExpand.
 Open center cell (set it to 1)
 while cellsToExpand is not empty do
     currentCell <-- random cell from cellsToExpand   //note that the neighbors of this cell will be walls
     randomDirection <-- a random direction (north, south, east, west)
     if neighbor two steps away from currentCell in direction randomDirection is not out of bound and is blocked
             add neighboring cell (two steps away) to cellsToExpand
             open the selected neighboring cell and the wall between current cell and the selected neighbor. 
      end
      if currentCell is on the boundary or all its neighbors (two cells away) are open
            remove currentCell from cellsToExpand
      end     
 end 


 Submission

Your assignments MUST be in a folder named Homework2 and submitted in SVN.  You will lose points otherwise.

 Extra Credit (10 extra points)

Modify the maze generator to work for arbitrary dimensions.  Hint: You will need to use dynamic arrays using "new" (Memory management L6). 

 
