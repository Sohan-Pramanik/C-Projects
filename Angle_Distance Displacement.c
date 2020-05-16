/******************************************************************************
 * Description: A hiker goes on a walk  and for each of four leg on their 
 * traverse records a turn and a distance traveled. This program calculates the 
 * distance and angle displaced using the user inputted angles and distances.
 * Programmers: Sohan Pramanik  pramanis@purdue.edu
 ******************************************************************************/
#include <stdio.h>
#include <math.h>
#define PI 3.141592654
#define DEG 180

// function declarations
void getAngle(double *ang1, double *ang2, double *ang3, double *ang4); // user input for the angles
void getDistance(double *dist1, double *dist2, double *dist3, double *dist4); // user input for the distance travelled
void getPosition(double *ang1, double *ang2, double *ang3, double *ang4, double *dist1, double *dist2, double *dist3, double *dist4, double *x, double *y); // calculations to find the position of the hiker
void getDisplacement(double *x, double *y, double *disDisp, double *angDisp); // calculations for the total displacement of the hiker

int main()
{

  double ang1; // user input for first angle (degrees)
  double ang2; // user input for second angle (degrees)
  double ang3; // user input for third angle (degrees)
  double ang4; // user input for fourth angle (degrees)
  double dist1; // user input for first distance travelled (meters)
  double dist2; // user input for second distance travelled (meters)
  double dist3; // user input for third distance travelled (meters)
  double dist4; // user input for fourth distance travelled (meters)
  double x; // the position being updated on x-axis
  double y; // the position being updated on y-axis
  double disDisp; // the distance displacement of the hiker
  double angDisp; // the angle displacement of the hiker

  // calls the functions
  getAngle(&ang1, &ang2, &ang3, &ang4);
  getDistance(&dist1, &dist2, &dist3, &dist4);
  getPosition(&ang1, &ang2, &ang3, &ang4, &dist1, &dist2, &dist3, &dist4, &x, &y);
  getDisplacement(&x, &y, &disDisp, &angDisp);

  // displays the angle and distance displacement of the hiker
  printf("\n");
  printf("Distance displacement: %.0lf (m)\n", disDisp);
  printf("Angle displacement: %.0lf (degrees)\n", angDisp);

  return 0;

}

/******************************************************************************
 * Function:    getAngle
 * Description: Gets data input of angles of each position of the hiker.
 * Parameters:  ang1, double, user input for first angle (degrees)
 *              ang2, double, user input for second angle (degrees)
 *              ang3, double, user input for third angle (degrees)
 *              ang4, double, user input for fourth angle (degrees)
 * Return:      NA
 ******************************************************************************/

void getAngle(double *ang1, double *ang2, double *ang3, double *ang4)
{

  // asks user for input on the angles of each position of the hiker
  printf("Enter angle [degrees] for leg #1 -> ");
  scanf("%lf", ang1);

  printf("Enter angle [degrees] for leg #2 -> ");
  scanf("%lf", ang2);

  printf("Enter angle [degrees] for leg #3 -> ");
  scanf("%lf", ang3);

  printf("Enter angle [degrees] for leg #4 -> ");
  scanf("%lf", ang4);

  return;

}

/******************************************************************************
 * Function:    getDistance
 * Description: Gets data input of distance of each position of the hiker.
 * Parameters:  dist1, double, user input for first angle (degrees)
 *              dist2, double, user input for second angle (degrees)
 *              dist3, double, user input for third angle (degrees)
 *              dist4, double, user input for fourth angle (degrees)
 * Return:      NA
 ******************************************************************************/

void getDistance(double *dist1, double *dist2, double *dist3, double *dist4)
{

  // asks user for input on the distance travelled of each position of the hiker
  printf("Enter distance traveled [m] for leg #1 -> ");
  scanf("%lf", dist1);

  printf("Enter distance traveled [m] for leg #2 -> ");
  scanf("%lf", dist2);

  printf("Enter distance traveled [m] for leg #3 -> ");
  scanf("%lf", dist3);

  printf("Enter distance traveled [m] for leg #4 -> ");
  scanf("%lf", dist4);

  return;

}

/******************************************************************************
 * Function:    getPosition
 * Description: Calculations to find each updated position of the hiker.
 * Parameters:  ang1, double, user input for first angle (degrees)
 *              ang2, double, user input for second angle (degrees)
 *              ang3, double, user input for third angle (degrees)
 *              ang4, double, user input for fourth angle (degrees)
 *              dist1, double, user input for first angle (degrees)
 *              dist2, double, user input for second angle (degrees)
 *              dist3, double, user input for third angle (degrees)
 *              dist4, double, user input for fourth angle (degrees)
 *              x, double, the position being updated on x-axis
 *              y, double, the position being updated on y-axis
 * Return:      NA
 ******************************************************************************/

void getPosition(double *ang1, double *ang2, double *ang3, double *ang4, double *dist1, double *dist2, double *dist3, double *dist4, double *x, double *y)
{

  // converts the angles of degrees to radians
  *ang1 = *ang1 * PI / DEG;
  *ang2 = *ang2 * PI / DEG;
  *ang3 = *ang3 * PI / DEG;
  *ang4 = *ang4 * PI / DEG;

  // calculations for each updated position of the hiker
  *x = *dist1 * cos(*ang1);
  *y = *dist1 * sin(*ang1);

  *x = *x + *dist2 * cos(*ang2);
  *y = *y + *dist2 * sin(*ang2);

  *x = *x + *dist3 * cos(*ang3);
  *y = *y + *dist3 * sin(*ang3);

  *x = *x + *dist4 * cos(*ang4);
  *y = *y + *dist4 * sin(*ang4);

  return;

}

/******************************************************************************
 * Function:    getDisplacement
 * Description: Calculations for the distance and angle displaced by hiker.
 * Parameters:  x, double, the position being updated on x-axis
 *              y, double, the position being updated on y-axis
 *              disDisp, double, the distance displacement of the hiker
 *              angDisp, double, the angle displacement of the hiker
 * Return:      NA
 ******************************************************************************/

void getDisplacement(double *x, double *y, double *disDisp, double *angDisp)
{

  // calculation for the distance displaced by hiker
  *disDisp = sqrt(pow(*x, 2) + pow(*y, 2));

  // calculation for angle displaced by hiker
  *angDisp = atan(*y / *x);

  // converts the angle of radians to degrees
  *angDisp = *angDisp * DEG / PI;

  return;

}
