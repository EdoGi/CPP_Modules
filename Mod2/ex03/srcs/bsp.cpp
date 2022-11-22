#include "Point.hpp"

Fixed area(Point const A, Point const B, Point const C)
{
   return (A.getX() * (B.getY() - C.getY()) + B.getX() * (C.getY() - A.getY()) + C.getX() * (A.getY() - C.getY())/2);
}

bool bsp(Point const A, Point const B, Point const C, Point const P)
{  
   /* Calculate area of triangle ABC */
   Fixed M = area(A, B, C);
  
   /* Calculate area of triangle PBC */ 
   Fixed A1 = area (P, B, C);
  
   /* Calculate area of triangle PAC */ 
   Fixed A2 = area (A, P, C);
  
   /* Calculate area of triangle PAB */  
   Fixed A3 = area (A, B, P);
   
   /* Check if sum of A1, A2 and A3 is same as A */
   return (M == A1 + A2 + A3);
}
