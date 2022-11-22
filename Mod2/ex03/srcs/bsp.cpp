#include "Point.hpp"

Fixed area(Point const A, Point const B, Point const C)
{
	Fixed tmp(A.getX() * (B.getY() - C.getY()) + B.getX() * (C.getY() - A.getY()) + C.getX() * (A.getY() - C.getY())/2);
	Fixed sign(-1);

	if (tmp < 0)
		tmp = tmp * sign;
	return (tmp);
}

bool bsp(Point const A, Point const B, Point const C, Point const P)
{
	/* Calculate area of triangle ABC */
	Fixed M = area(A, B, C);
	std::cout << "M is : " <<  M << std::endl;

	/* Calculate area of triangle PBC */ 
	Fixed A1 = area(P, B, C);
	std::cout << "A1 is : " <<  A1 << std::endl;

	/* Calculate area of triangle PAC */ 
	Fixed A2 = area(A, P, C);
	std::cout << "A2 is : " << A2 << std::endl;
	
	/* Calculate area of triangle PAB */  
	Fixed A3 = area(A, B, P);
	std::cout << "A3 is : " <<  A3 << std::endl;

	/* Check if sum of A1, A2 and A3 is same as A */
	Fixed tmp(A1.toInt() + A2.toInt() + A3.toInt());
	std::cout << "sum is : " << tmp << std::endl;
	return (M.toInt() == A1.toInt() + A2.toInt() + A3.toInt());
}
