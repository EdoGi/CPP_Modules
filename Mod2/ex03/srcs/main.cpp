#include "Fixed.hpp"
#include "Point.hpp"

int main() {

	Point const a(0.0f, 0.0f);
	Point const b(10.5f, 0.0f);
	Point const c(5.0f, 5.5f);
	Point const d(7.5f, 2.9f);
	Point const e(7.5f, 3.0f);
	Point const f(7.5f, 3.1f);
	Point const g(4.0f, 1.0f);
	
	if (bsp(a, b, c, d) == false)
		std::cout << "Le point D n'est pas dans le triangle ABC" << std::endl;
		else
        std::cout << "Le point D est dans le triangle ABC" << std::endl;
	
	if (bsp(a, b, c, e) == false)
		std::cout << "Le point E n'est pas dans le triangle ABC" << std::endl;
	else 
		std::cout << "Le point E est dans le triangle ABC" << std::endl;
    
    if (bsp(a, b, c, f) == false)
		std::cout << "Le point F n'est pas dans le triangle ABC" << std::endl;
	else 
		std::cout << "Le point F est dans le triangle ABC" << std::endl;
		
	if (bsp(a, b, c, g) == false)
		std::cout << "Le point G n'est pas dans le triangle ABC" << std::endl;
	else 
		std::cout << "Le point G est dans le triangle ABC" << std::endl;

	return (0);
}
