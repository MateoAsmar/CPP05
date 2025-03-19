#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main(void)
{
    try {
        Bureaucrat bob("Bob", 50);
        std::cout << bob << std::endl;
        
        ShrubberyCreationForm scf("Home");
        RobotomyRequestForm rrf("Bender");
        PresidentialPardonForm ppf("Fry");
        
        bob.signForm(scf);
        bob.executeForm(scf);
        
        bob.signForm(rrf);
        bob.executeForm(rrf);
        
        bob.signForm(ppf);
        bob.executeForm(ppf);
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
