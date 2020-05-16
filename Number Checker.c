/******************************************************************************
 * Description: The program accepts input from user for the seed for random
 *              seed generator. Also accepts input for numbers into an array. 
 *              Then program creates 1000 random values in another array
 *              from 1 - 1000 and then checks if the numbers are both in the 
 *              first array and second array.
 * Programmers: Sohan Pramanik   pramanis@purdue.edu
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define SIZE1 30
#define SIZE2 1000

void getInput(int *seed, int input[]);
void getRand(int random[]);
void getCheck(int input[], int random[], int count);
int getCount(int target, int random[]);

int main()
{
  int seed; // random seed generator
  int input[SIZE1] = {0}; // user inputted values into array (data set 1)
  int random[SIZE2]; // array with random numbers from 1-1000
  int count = 0; // number of integers in both arrays

  // function calls
  getInput(&seed, input);
  getRand(random);
  getCheck(input, random, count);

  return 0;
}

/******************************************************************************
 * Function:    getInput
 * Description: Take in the user input for the seed for random seed generator. 
 *              Also takes user input for values into desired array. 
 * Parameters:  seed, int, random seed generator
 *              input[], int, user inputted values into array (data set 1)
 * Return:      N/A
 ******************************************************************************/
void getInput(int *seed, int input[])
{

  int i = 0; // intializes for counter of input array
  int brk = 0; // checks if -1 is inputted to break

  // gets random seed
  printf("Enter seed value -> ");
  scanf("%d", seed);
  srand(*seed);

  printf("Enter up to 30 integers or -1 to exit -> ");

  // loop for putting user input into array
  while (i < SIZE1 && brk == 0)
  {
    int read = 0; // scans the number

    // scans for user input and puts into array
    scanf("%d", &read);

    // checks if -1 is inputted
    if (read == -1)
    {
      brk = 1;
    }
    else
    {
      input[i] = read;
      brk = 0;
    }

    i++;
  }

  return;
}

/******************************************************************************
 * Function:    getRand
 * Description: Takes the user input for the seed for random seed generator, and
 *              puts random integers from 1 - 1000 into another array.
 * Parameters:  random[], int, array for the random 1000 values
 * Return:      N/A
 ******************************************************************************/
void getRand(int random[])
{
  int i; // initializing counter for random generator

  // inserting random numbers from 1 - 1000 to array
  for (i = 0; i < SIZE2; i++)
  {
    random[i] = rand() % 1000 + 1;
  }

  return;
}

/******************************************************************************
 * Function:    getCheck
 * Description: Checks the first array filled with user inputted values, and 
 *              sees if values are same in both arrays.
 * Parameters:  random[], int, array for the random 1000 values
 *              input[], int, user inputted values into array (data set 1)
 *              count, int, number of integers in both arrays
 * Return:      N/A
 ******************************************************************************/
void getCheck(int input[], int random[], int count)
{
  int i; // initializing counter for data set 1
  int target; // gets target value from array set 1

  // gets each individual integer from first data set
  for (i = 0; i < SIZE1; i++)
  {
    target = input[i];
    count += getCount(target, random);
  }

  printf("\nTotal number of values found: %d\n", count);

  return;
}

/******************************************************************************
 * Function:    getCheck
 * Description: Using the first array filled with user inputted values, and 
 *              sees if values are same in both arrays, then returns 1 or 0.
 * Parameters:  random[], int, array for the random 1000 values
 *              target, int, gets target value from array set 1
 * Return:      found
 ******************************************************************************/
int getCount(int target, int random[])
{
  int j; // initializing counter for data set 2
  int found = 0; // flags when number is found in array

  // checks each digit in loop to find same number from data set 1
  for (j = 0; j < SIZE2; j++)
  {
    if (random[j] == target)
    {
      found = 1;
    }
  }

  return found;
}

