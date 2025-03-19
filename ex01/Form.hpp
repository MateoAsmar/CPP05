#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form {
	public:
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		// Constructor
		Form(const std::string &name, int gradeToSign, int gradeToExecute);
		// Copy constructor
		Form(const Form &other);
		// Assignment operator
		Form &operator=(const Form &other);
		// Destructor
		~Form(void);

		// Getters
		const std::string &getName(void) const;
		bool getIsSigned(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;

		// Member function: sign the form
		void beSigned(const Bureaucrat &b);

	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExecute;
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif