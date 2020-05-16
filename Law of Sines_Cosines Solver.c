/******************************************************************************
 * Description: This program is given either the values of two sides and an 
 * angle or two angles and a side of a triangle calculate the values of all 
 * angles, sides, and area of the triangle.
 * Programmers: Sohan Pramanik  pramanis@purdue.edu
 ******************************************************************************/
#include <stdio.h>
#include <math.h>

#define PI 3.14159265359
#define DEG 180

void getInput(double *angleA, double *angleB, double *angleC, double *sideA, double *sideB, double *sideC);
void getAAS(double *angleA, double *angleB, double *angleC, double *sideA, double *sideB, double *sideC);
void getSSA(double *angleA, double *angleB, double *angleC, double *sideA, double *sideB, double *sideC);
void getArea(double *angleC, double *sideA, double *sideB, double *area);
void getOutput(double angleA, double angleB, double angleC, double sideA, double sideB, double sideC, double area);

int main ()
{

  double angleA; // first angle entered of the triangle
  double angleB; // second angle entered of the tiangle
  double angleC; // third angle entered of the triangle
  double sideA; // first side entered of the triangle
  double sideB; // second side entered of the triangle
  double sideC; // third side entered of the triangle
  double area; // area of the triangle of the triangle

  // function calls
  getInput(&angleA, &angleB, &angleC, &sideA, &sideB, &sideC);
  getAAS(&angleA, &angleB, &angleC, &sideA, &sideB, &sideC);
  getSSA(&angleA, &angleB, &angleC, &sideA, &sideB, &sideC);
  getArea(&angleC, &sideA, &sideB, &area);
  getOutput(angleA, angleB, angleC, sideA, sideB, sideC, area);

  return 0;

}
/******************************************************************************
 * Function:    getInput
 * Description: Gets data input of angles and sides of triangle.
 * Parameters:  angleA, double, user input for first angle (degrees)
 *              angleB, double, user input for second angle (degrees)
 *              angleC, double, user input for third angle (degrees)
 *              sideA, double, user input for first side (cm)
 *              sideB, double, user input for second side (cm)
 *              sideC, double, user input for third side (cm)
 * Return:      NA
 ******************************************************************************/
void getInput(double *angleA, double *angleB, double *angleC, double *sideA, double *sideB, double *sideC)
{

  // asks the user for input for the values of angles and side lengths of triangle

  printf("Enter angle measurements [degrees] -> ");
  scanf("%lf %lf %lf", angleA, angleB, angleC);

  printf("Enter side lengths [cm] -> ");
  scanf("%lf %lf %lf", sideA, sideB, sideC);

  printf("\n");

  return;

}
/******************************************************************************
 * Function:    getOutput
 * Description: Gets data output of all angles, sides, and area of triangle.
 * Parameters:  angleA, double, calculated first angle (degrees)
 *              angleB, double, calculated for second angle (degrees)
 *              angleC, double, calculated for third angle (degrees)
 *              sideA, double, calculated for first side (cm)
 *              sideB, double, calculated for second side (cm)
 *              sideC, double, calculated for third side (cm)
 *              area, double, calculated area of triangle (cm^2)
 * Return:      NA
 ******************************************************************************/
void getOutput(double angleA, double angleB, double angleC, double sideA, double sideB, double sideC, double area)
{

  // displays all the angles, side lengths, and area of triangle
  printf("Angle measurements [degrees]: %.2lf %.2lf %.2lf\n", angleA, angleB, angleC);
  printf("Side lengths [centimeters]: %.2lf %.2lf %.2lf\n", sideA, sideB, sideC);
  printf("Area of triangle [centimeters squared]: %.2lf\n", area);

  return;
}
/******************************************************************************
 * Function:    getArea
 * Description: Calculates the area of the triangle.
 * Parameters:  angleC, double, calculated for third angle (degrees)
 *              sideA, double, calculated for first side (cm)
 *              sideB, double, calculated for second side (cm)
 *              area, double, calculated area of triangle (cm^2)
 * Return:      NA
 ******************************************************************************/
void getArea(double *angleC, double *sideA, double *sideB, double *area)
{

  // calculates the area of the triangle
  *area = *sideA * *sideB * sin(*angleC * PI / DEG) / 2;

  return;

}
/******************************************************************************
 * Function:    getAAS
 * Description: Calculates for all missing angles, and sides of triangles that have
 *              two angles and one side.
 * Parameters:  angleA, double, calculated first angle (degrees)
 *              angleB, double, calculated for second angle (degrees)
 *              angleC, double, calculated for third angle (degrees)
 *              sideA, double, calculated for first side (cm)
 *              sideB, double, calculated for second side (cm)
 *              sideC, double, calculated for third side (cm)
 * Return:      NA
 ******************************************************************************/
void getAAS(double *angleA, double *angleB, double *angleC, double *sideA, double *sideB, double *sideC)
{
  // checks if first and third side lengths are missing and calculates it
  if ((*sideA == 0) & (*sideC == 0))
  {
    // checks if first angle is missing and calculates it
    if (*angleA == 0)
    {
      *angleA = DEG - *angleB - *angleC;
    }

    // checks if second angle is missing and calculates it
    else if (*angleB == 0)
    {
      *angleB = DEG - *angleA - *angleC;
    }

    // checks if third angle is missing and calculates it
    else if (*angleC == 0)
    {
      *angleC = DEG - *angleA - *angleB;
    }

    *sideA = sin(*angleA * PI / DEG) * *sideB / sin(*angleB * PI / DEG);
    *sideC = sin(*angleC * PI / DEG) * *sideB / sin(*angleB * PI / DEG);

  }

  // checks if second and third side lengths are missing
  if ((*sideB == 0) & (*sideC == 0))
  {
    // checks if first angle is missing and calculates it
    if (*angleA == 0)
    {
      *angleA = DEG - *angleB - *angleC;
    }

    // checks if second angle is missing and calculates it
    else if (*angleB == 0)
    {
      *angleB = DEG - *angleA - *angleC;
    }

    // checks if third angle is missing and calculates it
    else if (*angleC == 0)
    {
      *angleC = DEG - *angleA - *angleB;
    }
    
    *sideB = sin(*angleB * PI / DEG) * *sideA / sin(*angleA * PI / DEG);
    *sideC = sin(*angleC * PI / DEG) * *sideB / sin(*angleB * PI / DEG);

  }

  // checks if first and second side lengths are missing and calculates it
  if ((*sideA == 0) & (*sideB == 0))
  {
    // checks if first angle is missing and calculates it
    if (*angleA == 0)
    {
      *angleA = DEG - *angleB - *angleC;
    }

    // checks if second angle is missing and calculates it
    else if (*angleB == 0)
    {
      *angleB = DEG - *angleA - *angleC;
    }

    // checks if third angle is missing and calculates it
    else if (*angleC == 0)
    {
      *angleC = DEG - *angleA - *angleB;
    }
    
    *sideA = sin(*angleA * PI / DEG) * *sideC / sin(*angleC * PI / DEG);
    *sideB = sin(*angleB * PI / DEG) * *sideC / sin(*angleC * PI / DEG);

  }

  return;
}
/******************************************************************************
 * Function:    getSSA
 * Description: Calculates for all missing angles, and sides of triangles that have
 *              two sides and one angle.
 * Parameters:  angleA, double, calculated first angle (degrees)
 *              angleB, double, calculated for second angle (degrees)
 *              angleC, double, calculated for third angle (degrees)
 *              sideA, double, calculated for first side (cm)
 *              sideB, double, calculated for second side (cm)
 *              sideC, double, calculated for third side (cm)
 * Return:      NA
 ******************************************************************************/
void getSSA(double *angleA, double *angleB, double *angleC, double *sideA, double *sideB, double *sideC)
{
  // checks if second and third angles are missing and calculates it
  if ((*angleB == 0) & (*angleC == 0))
  {
    // checks if first side is missing and calculates it   
    if (*sideA == 0)
    {
      *sideA = sqrt(pow(*sideB, 2) + pow(*sideC, 2) - (2 * *sideB * *sideC * cos(*angleA * PI / DEG)));
      *angleB = asin(((sin(*angleA * PI / DEG) * *sideB) / *sideA)) * DEG / PI;
      *angleC = DEG - *angleA - *angleB;
    }

    // checks if second side is missing and calculates it
    if (*sideB == 0)
    {
      *angleC = asin(((sin(*angleA * PI / DEG) * *sideC) / *sideA)) * DEG / PI;
      *angleB = DEG - *angleA - *angleC;
      *sideB = sqrt(pow(*sideA, 2) + pow(*sideC, 2) - (2 * *sideA * *sideC * cos(*angleB * PI / DEG)));
    }

    // checks if third side is missing and calculates it
    if (*sideC == 0)
    {
      *angleB = asin(((sin(*angleA * PI / DEG) * *sideB) / *sideA)) * DEG / PI;
      *angleC = DEG - *angleA - *angleB;
      *sideC = sqrt(pow(*sideA, 2) + pow(*sideB, 2) - (2 * *sideA * *sideB * cos(*angleC * PI / DEG)));
    }

  }

  // checks if first and second angles are missing and calculates it
  if ((*angleA == 0) & (*angleB == 0))
  {
    // checks if first side is missing and calculates it
    if (*sideA == 0)
    {
      *angleB = asin(((sin(*angleC * PI / DEG) * *sideB) / *sideC)) * DEG / PI;
      *angleA = DEG - *angleB - *angleC;
      *sideA = sqrt(pow(*sideB, 2) + pow(*sideC, 2) - (2 * *sideB * *sideC * cos(*angleA * PI / DEG)));
    }

    // checks if second side is missing and calculates it
    if (*sideB == 0)
    {
      *angleA = asin(((sin(*angleC * PI / DEG) * *sideA) / *sideC)) * DEG / PI;
      *angleB = DEG - *angleA - *angleC;
      *sideB = sqrt(pow(*sideA, 2) + pow(*sideC, 2) - (2 * *sideA * *sideC * cos(*angleB * PI / DEG)));
    }

    // checks if third side is missing and calculates it
    if (*sideC == 0)
    {
      *sideC = sqrt(pow(*sideA, 2) + pow(*sideB, 2) - (2 * *sideA * *sideB * cos(*angleC * PI / DEG)));
      *angleA = asin(((sin(*angleC * PI / DEG) * *sideA) / *sideC)) * DEG / PI;
      *angleB = DEG - *angleA - *angleC;
    }

  }

  // checks if first and third angles are missing and calculates it
  if ((*angleA == 0) & (*angleC == 0))
  {
    // checks if first side is missing and calculates it
    if (*sideA == 0)
    {
      *angleC = asin(((sin(*angleB * PI / DEG) * *sideC) / *sideB)) * DEG / PI;
      *angleA = DEG - *angleB - *angleC;
      *sideA = sqrt(pow(*sideB, 2) + pow(*sideC, 2) - (2 * *sideB * *sideC * cos(*angleA * PI / DEG)));
    }

    // checks if second side is missing and calculates it
    if (*sideB == 0)
    {
      *sideB = sqrt(pow(*sideA, 2) + pow(*sideC, 2) - (2 * *sideA * *sideC * cos(*angleB * PI / DEG)));
      *angleC = asin(((sin(*angleB * PI / DEG) * *sideA) / *sideB)) * DEG / PI;
      *angleA = DEG - *angleB - *angleC;
    }

    // checks if third side is missing and calculates it
    if (*sideC == 0)
    {
      *angleA = asin(((sin(*angleB * PI / DEG) * *sideA) / *sideB)) * DEG / PI;
      *angleC = DEG - *angleA - *angleB;
      *sideC = sqrt(pow(*sideA, 2) + pow(*sideB, 2) - (2 * *sideA * *sideB * cos(*angleC * PI / DEG)));
    }

  }

  return;
}
