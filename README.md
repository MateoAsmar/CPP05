# CPP05
(Repetition and Exceptions)
## Grade: 100/100
![cpp05](https://github.com/user-attachments/assets/9e2a03f2-4507-4a28-a53c-caa6ba7da7da)

## Overview

This project simulates a bureaucratic system using advanced C++ concepts such as exception handling, operator overloading, and class design. The project is split into several exercises, each building on the previous ones:

- **Exercise 00: "Mommy, when I grow up, I want to be a bureaucrat!"**  
  In this exercise, I implemented a `Bureaucrat` class with a constant name and a grade (from 1 to 150). Any attempt to create or modify a Bureaucrat with an invalid grade throws an exception (`GradeTooHighException` or `GradeTooLowException`). The class includes functions to increment and decrement the grade and overloads the insertion operator for easy output.

- **Exercise 01: "Form up, maggots!"**  
  Here, I developed a `Form` class that has a constant name, a signature status, and required grades for signing and execution. The `Form` class throws exceptions if any grade is out of bounds, and it provides a `beSigned()` method for a Bureaucrat to sign the form. An overload of the insertion operator prints all form information.

- **Exercise 02: "No, you need form 28B, not 28C..."**  
  This part extends the form concept by making the base class abstract (renamed `AForm`) and implementing concrete forms:  
  - **ShrubberyCreationForm:** Creates a file with ASCII art trees.  
  - **RobotomyRequestForm:** Simulates a robotomy procedure with a 50% success chance.  
  - **PresidentialPardonForm:** Announces that a target has been pardoned.  
  Each form checks that the form is signed and that the executor’s grade is sufficient before execution.

- **Exercise 03: "At least this beats coffee-making"**  
  Finally, I implemented an `Intern` class. The intern has a `makeForm()` method that creates forms dynamically based on string input. This solution avoids a long if/else chain by mapping form names to constructors elegantly.

## Files Structure

- **Makefile**  
  Automates the build process.

- **Bureaucrat.hpp / Bureaucrat.cpp**  
  Implements the `Bureaucrat` class, managing constant names and grades with exception handling. Also overloads the insertion operator.

- **Form.hpp / Form.cpp** (or `AForm.hpp`/`AForm.cpp` in later exercises)  
  Defines the abstract base class for forms and manages attributes such as form name, signature status, and required grades.

- **ShrubberyCreationForm.hpp / ShrubberyCreationForm.cpp**  
  Concrete form that creates a file with ASCII trees.

- **RobotomyRequestForm.hpp / RobotomyRequestForm.cpp**  
  Concrete form that simulates a robotomy procedure.

- **PresidentialPardonForm.hpp / PresidentialPardonForm.cpp**  
  Concrete form that simulates a presidential pardon.

- **Intern.hpp / Intern.cpp**  
  Implements the `Intern` class capable of creating forms based on string input.

- **main.cpp**  
  Contains extensive tests to demonstrate the functionality, proper exception handling, and correct chaining of constructors/destructors.

## Features

### Bureaucrat
- **Grade Management:**  
  Grades range from 1 (highest) to 150 (lowest). Increment and decrement operations are validated and throw exceptions when out-of-range.
- **Exception Handling:**  
  Uses custom exceptions (`GradeTooHighException` and `GradeTooLowException`) to signal errors.
- **Operator Overloading:**  
  Overloads the insertion operator (`<<`) for straightforward output of bureaucrat details.

### Form (AForm)
- **Attributes:**  
  Immutable name, signature status, and required grades.
- **Signing Process:**  
  The `beSigned()` method allows a Bureaucrat to sign a form if their grade is sufficient, otherwise it throws a `GradeTooLowException`.
- **Operator Overloading:**  
  Overloads the insertion operator to print form information.

### Concrete Forms
- **ShrubberyCreationForm:**  
  Generates a file containing ASCII art trees.
- **RobotomyRequestForm:**  
  Performs a simulated robotomy with a 50% success rate.
- **PresidentialPardonForm:**  
  Announces that a target has been pardoned by a high-level authority.

### Intern
- **Dynamic Form Creation:**  
  The `Intern` class creates form objects based on string input, using a mapping technique to avoid bulky conditional statements.
- **Feedback:**  
  Provides clear output regarding the creation of forms or error messages if the form type is unknown.

## Compilation

To compile the project, run:
```bash
cd ex00
make
./executable_filename
```

## What I Learned
**Exception Handling:** How to design and use custom exceptions to enforce business logic.

**Operator Overloading:** Overloading operators for intuitive output and improved usability.

**Abstract Classes & Polymorphism:** Designing an abstract base class (AForm) to enforce a common interface and using virtual functions to achieve polymorphic behavior.

**Resource Management:** Proper management of resources, ensuring that constructors and destructors are chained correctly to avoid memory leaks

**Elegant Code Design:** Implementing a mapping mechanism in the Intern class to simplify object creation without long if/else chains.

## Conclusion
The CPP05 project challenged me to design a robust and flexible bureaucratic simulation using advanced C++ techniques. By implementing a variety of interrelated classes with careful resource management and exception handling, I gained deeper insights into effective C++ programming practices and design patterns.

















