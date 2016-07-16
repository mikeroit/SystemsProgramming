//
//  bearHelper.cpp
//  FunctionTemplates
//
//  Created by Computer Science on 1/27/16.
//  Copyright (c) 2016 Computer Science. All rights reserved.
//

#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <unordered_map>
#include <fstream>
#include "bearHelper.h"

/*
 * Counts the number of words in a file named f
 * parameter: file name
 * return: number of words in file
 */
int GetNumEntriesInFile(const char *f)
{

  //0. Declare a return value, temp int
  int returnVal;
  int temp;


  //1. Open the file for reading 
  FILE myFile = fopen(f,  "r");

  //2. Count the number of words in file.  Hint: You can count the number of '\n' characters in file. Use fgetc to read one character at a time.
  if(myFile == NULL) perror ("Error opening file")
  
  fseek(myFile, 0, SEEK_SET);
  do
  {
      temp = fgetc(myFile);
      if( fgetc(myFile) == "\n"  ) returnVal++;

  }while(temp != NULL);
  
  //3. close file
  fclose(myFile);
  
  //4.return count
  return returnVal;
  
}


/*
 * Creates an array of strings of size count and populates it with words in file named f
 * parameter: f - file name, cout - number of words in file
 * return: An array of c-strings
 */
char **ReadWords(const char *f, int count)
{
  
  //1. Open file for reading
  FILE myFile = fopen(f,  "r");
  if(myFile == NULL) perror ("Error opening file")

  //2. Allocate the array of c-strings
  char* myLetters = new char[count];

  //3. For each word in the file
  for(int i = 0; i < count; i++)
  {
    //3.a Determine the length of word
    //   (hint: use ftell to determine the location of the pointer in file before you start counting the letters, use fgetc to read a single character, then fseek to the location of the start of the word and read it).
    int location = ftell(myFile);

    //3.b Allocate a string long enough to store word
    char* my
  }
  //3.c store word in array of words

  //4. close file

  //5. return array of words
  
}



/*
 * Returns true if all letters in "letters" are in group of letters "group" (duplicates should be accounted for)
 * therefore the letters: "ee" are in group "tree" but not in group "tea"
 *
 * parameter: letters - list of letters, group - a collection of letter
 * return: true of all letters are in set
 */
bool AllLettersInSet(const char *letters, const char *group)
{
    int lSet[26]; int sSet[26];
  
    for(int i = 0; i < 26; i++)
    {
        lSet[i]= sSet[i] = 0;
    }

    for(const char *t = group; *t; t++)
    {
        lSet[tolower(*t) - 97]++;
    }
    
    for(const char *t = group; *t; t++)
    {
        sSet[tolower(*t) - 97]++;
    }

    for(int i = 0; i < 26; i++)
    {
        if(lSet[i] > sSet[x]) return false;
    }

    return true

}

