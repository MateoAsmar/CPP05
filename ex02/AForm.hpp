#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class AForm {
public:
    AForm(const std::string &name, int gradeToSign, int gradeToExecute);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm(void);

    const std::string &getName(void) const;
    bool getIsSigned(void) const;
    int getGradeToSign(void) const;
    int getGradeToExecute(void) const;

    void beSigned(const Bureaucrat &b);
    void execute(Bureaucrat const &executor) const;

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class FormNotSignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

protected:
    virtual void _executeAction() const = 0;

private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
