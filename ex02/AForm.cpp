#include "AForm.hpp"

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
: name(other.name), isSigned(other.isSigned),
  gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        isSigned = other.isSigned;
    return (*this);
}

AForm::~AForm(void)
{
}

const std::string &AForm::getName(void) const
{
    return name;
}

bool AForm::getIsSigned(void) const
{
    return isSigned;
}

int AForm::getGradeToSign(void) const
{
    return gradeToSign;
}

int AForm::getGradeToExecute(void) const
{
    return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (!isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > gradeToExecute)
        throw GradeTooLowException();
    _executeAction();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Form grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Form grade too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed";
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << form.getName() << " (Sign grade: " << form.getGradeToSign()
       << ", Exec grade: " << form.getGradeToExecute() << ")"
       << ", signed: " << (form.getIsSigned() ? "yes" : "no");
    return os;
}
