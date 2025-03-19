#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

typedef AForm* (*FormCreationFunc)(const std::string &target);

static AForm *createShrubbery(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm *createRobotomy(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *createPresidential(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

Intern::Intern(void) { }

Intern::Intern(const Intern &other) { (void)other; }

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern(void) { }

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
	struct FormPair {
		std::string name;
		FormCreationFunc func;
	};

	FormPair forms[3] = {
		{ "shrubbery creation", createShrubbery },
		{ "robotomy request", createRobotomy },
		{ "presidential pardon", createPresidential }
	};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i].name == formName)
		{
			AForm *form = forms[i].func(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form);
		}
	}
	std::cout << "Intern: Unknown form type" << std::endl;
	return (NULL);
}
