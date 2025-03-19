#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include <string>
# include <cmath>

class Bureaucrat {
	public:
		// Constructor with name and grade
		Bureaucrat(const std::string &name, int grade);
		// Copy constructor
		Bureaucrat(const Bureaucrat &other);
		// Assignment operator
		Bureaucrat &operator=(const Bureaucrat &other);
		// Destructor
		~Bureaucrat(void);

		// Getters
		const std::string &getName(void) const;
		int getGrade(void) const;

		// Increment/Decrement grade
		void incrementGrade(void);
		void decrementGrade(void);

		// Exception classes
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
	private:
		const std::string name;
		int grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif