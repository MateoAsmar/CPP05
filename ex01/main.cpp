#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	try {
		Bureaucrat bob("Bob", 50);
		Form contract("Contract", 45, 30);
		
		std::cout << contract << std::endl;
		
		try {
			contract.beSigned(bob);
		}
		catch (std::exception &e) {
			std::cout << "Bob couldn't sign the form: " << e.what() << std::endl;
		}
		
		Bureaucrat alice("Alice", 20);
		contract.beSigned(alice);
		std::cout << contract << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return (0);
}
