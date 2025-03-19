#include "Bureaucrat.hpp"

int main(void)
{
	try {
		Bureaucrat bob("Bob", 75);
		std::cout << bob;
		bob.incrementGrade();
		std::cout << bob;
		bob.decrementGrade();
		std::cout << bob;
		// Bureaucrat tooHigh("Alice", 0);
		//m Bureaucrat tooLow("Eve", 151);
	}
	catch (std::exception & e){
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return (0);
}
