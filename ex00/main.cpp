#include "bureaucrat.h"

int main()
{
	try
	{
		Bureaucrat test("test", 0);
		std::cout << test << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	Bureaucrat a("A", 1);
	Bureaucrat b("B", 150);

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	try
	{
		a.increment();
		b.decrement();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	return 0;
}
