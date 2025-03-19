#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>

int main(void)
{
	try {
		Bureaucrat bob("Bob", 50);
		Intern someIntern;
		AForm *form;

		form = someIntern.makeForm("robotomy request", "Bender");
		if (form)
		{
			bob.signForm(*form);
			bob.executeForm(*form);
			delete form;
		}
		form = someIntern.makeForm("shrubbery creation", "Garden");
		if (form)
		{
			bob.signForm(*form);
			bob.executeForm(*form);
			delete form;
		}
		form = someIntern.makeForm("presidential pardon", "Alice");
		if (form)
		{
			bob.signForm(*form);
			bob.executeForm(*form);
			delete form;
		}
		form = someIntern.makeForm("unknown form", "Target");
		if (form)
		{
			bob.signForm(*form);
			bob.executeForm(*form);
			delete form;
		}
	}
	catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return (0);
}
