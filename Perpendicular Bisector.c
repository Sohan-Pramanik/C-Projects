/******************************************************************************
* Description: The program calculates the perpendicular bisector from user inputted values in slope-intercept form.
* Programmers: Sohan Pramanik pramanis@purdue.edu
******************************************************************************/
#include <stdio.h>
#include <math.h>

int main()
{

  float firstX; // first x-coordinate
  float firstY; // first y-coordinate
  float secondX; // second x-coordinate
  float secondY; // second y-coordinate
  float yMid; // y midpoint
  float xMid; // x midpoint
  float perpSlope; // perpendicular slope
  float yInt; // y intercept

  // user input for the coordinates
  printf("Enter the first x coordinate -> ");
  scanf("%f", &firstX);

  printf("Enter the first y coordinate -> ");
  scanf("%f", &firstY);

  printf("Enter the second x coordinate -> ");
  scanf("%f", &secondX);

  printf("Enter the second y coordinate -> ");
  scanf("%f", &secondY);

  // displaying endpoints
  printf("Original endpoints: [%.1f, %.1f] and [%.1f, %.1f]\n", firstX, firstY, secondX, secondY);

  // calculations for the y intercept
  xMid = (secondX + firstX) / 2;
  yMid = (secondY + firstY) / 2;
  perpSlope = -1 * (secondX - firstX) / (secondY - firstY);
  yInt = (-1 * perpSlope * xMid) + yMid;

  // displaying the equation
  printf("Equation of the perpendicular bisector: y = %.2fx + %.2f\n", perpSlope, yInt);

  return 0;

}
