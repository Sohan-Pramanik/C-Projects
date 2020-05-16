/******************************************************************************
 * Description: This program takes in the integer number inputted by the user 
 *              from -99999 to 9999. Then it uses this number to switch it into 
 *              words.
 * Programmers: Sohan Pramanik   pramanis@purdue.edu
 ******************************************************************************/

#include <stdio.h>
#include <math.h>

void getInput(int *integer); // function for getting input for integer
int minusCheck(int integer); // function for checking is integer is less than 0
void ifZero(int integer); // function for checking if integer is 0
void calcThousand(int integer); // function for printing values above hundred
void calcHundred(int integer); // function for printing values under hundred

int main()
{

  int integer; // user inputted number to convert into words

  // calls the functions
  getInput(&integer);
  integer = minusCheck(integer);
  ifZero(integer);
  calcThousand(integer);
  calcHundred(integer);

  return 0;

}

void getInput(int *integer)
{

  // prints and asks user input
  printf("Enter integer in range [-99999, 99999] -> ");
  scanf("%d", integer);

  printf("\n");
  printf("Text equivalence: ");

}

int minusCheck(int integer)
{
  // checks if the number inputted is less than 0
  if (integer < 0)
  {
    integer = -1 * integer;
    printf("minus ");
  }
  return integer;
}


void calcThousand(int integer)
{

  // first 2 ten-thousand digit
  if ((integer % 10000 / 1000) || (integer % 100000 / 10000))
  {

    // 20-90 thousand
    switch (integer % 100000 / 10000)
    {
      case 9: printf("ninety");
              break;

      case 8: printf("eighty");
              break;

      case 7: printf("seventy");
              break;

      case 6: printf("sixty");
              break;

      case 5: printf("fifty");
              break;

      case 4: printf("forty");
              break;

      case 3: printf("thirty");
              break;

      case 2: printf("twenty");
              break;
    }

    // 10-19 thousand
    switch (integer % 100000 / 1000)
    {
      case 19: printf("nineteen");
               break;

      case 18: printf("eighteen");
               break;

      case 17: printf("seventeen");
               break;

      case 16: printf("sixteen");
               break;

      case 15: printf("fifteen");
               break;

      case 14: printf("fourteen");
               break;

      case 13: printf("thirteen");
               break;

      case 12: printf("twelve");
               break;

      case 11: printf("eleven");
               break;

      case 10: printf("ten");
               break;
    }

    // ten thousand digit if a number exist before it
    if ((integer / 10000) && ((integer / 1000) > 20))
    {
      // prints number associated with the number
      switch (integer / 1000 % 10)
      {
        case 9: printf("-nine");
                break;

        case 8: printf("-eight");
                break;

        case 7: printf("-seven");
                break;

        case 6: printf("-six");
                break;

        case 5: printf("-five");
                break;

        case 4: printf("-four");
                break;

        case 3: printf("-three");
                break;

        case 2: printf("-two");
                break;

        case 1: printf("-one");
                break;
      }

    }

    // ten thousand digit if a number does not exist before it
    else if (((integer / 1000) > 20) || ((integer / 1000) < 10))
    {

      // prints number associated with the number
      switch (integer / 1000 % 10)
      {
        case 9: printf("nine");
                break;

        case 8: printf("eight");
                break;

        case 7: printf("seven");
                break;

        case 6: printf("six");
                break;

        case 5: printf("five");
                break;

        case 4: printf("four");
                break;

        case 3: printf("three");
                break;

        case 2: printf("two");
                break;

        case 1: printf("one");
                break;
      }

    }

    printf(" thousand ");
  }

  return;

} 

void calcHundred(int integer)
{
  // hundreds place
  switch (integer % 1000 / 100)
  {
    case 9: printf("nine hundred ");
            break;

    case 8: printf("eight hundred ");
            break;

    case 7: printf("seven hundred ");
            break;

    case 6: printf("six hundred ");
            break;

    case 5: printf("five hundred ");
            break;

    case 4: printf("four hundred ");
            break;

    case 3: printf("three hundred ");
            break;

    case 2: printf("two hundred ");
            break;

    case 1: printf("one hundred ");
            break;
  }



  // tens place
  switch (integer % 100 / 10)
  {
    case 9: printf("ninety");
            break;

    case 8: printf("eighty");
            break;

    case 7: printf("seventy");
            break;

    case 6: printf("sixty");
            break;

    case 5: printf("fifty");
            break;

    case 4: printf("forty");
            break;

    case 3: printf("thirty");
            break;

    case 2: printf("twenty");
            break;
  }

  // the "teen" numbers
  switch (integer % 100)
  {
    case 19: printf("nineteen ");
             break;

    case 18: printf("eighteen ");
             break;

    case 17: printf("seventeen ");
             break;

    case 16: printf("sixteen ");
             break;

    case 15: printf("fifteen ");
             break;

    case 14: printf("fourteen ");
             break;

    case 13: printf("thirteen ");
             break;

    case 12: printf("twelve ");
             break;

    case 11: printf("eleven ");
             break;

    case 10: printf("ten ");
             break;
  }

  // ones place
  if ((integer % 100 / 10) && ((integer % 100) > 20))
  {

    // prints number associated with the number
    switch (integer % 10)
    {
      case 9: printf("-nine ");
              break;

      case 8: printf("-eight ");
              break;

      case 7: printf("-seven ");
              break;

      case 6: printf("-six ");
              break;

      case 5: printf("-five ");
              break;

      case 4: printf("-four ");
              break;

      case 3: printf("-three ");
              break;

      case 2: printf("-two ");
              break;

      case 1: printf("-one ");
              break;
    }
  }

  // ones place
  else if (((integer % 100) > 20) || ((integer % 100) < 10))

    switch (integer % 10)
    {
      case 9: printf("nine ");
              break;

      case 8: printf("eight ");
              break;

      case 7: printf("seven ");
              break;

      case 6: printf("six ");
              break;

      case 5: printf("five ");
              break;

      case 4: printf("four ");
              break;

      case 3: printf("three ");
              break;

      case 2: printf("two ");
              break;

      case 1: printf("one ");
              break;
    }
}

void ifZero(int integer)
{
  // checks if the integer inputted is equal to 0
  if (integer == 0)
  {
    printf("zero");
  }
}

