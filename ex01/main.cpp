#include "Bureaucrat.hpp"

int main() {
	Bureaucrat m("Polina", 156);
	int grade = m.getGrade();
	std::cout << m << std::endl << std::endl;
	try {
	    if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
	} catch (std::exception & e) {
		std::cout << "Caught out of range: " << e.what() << std::endl;
	} 
	m.incrementGrade(10);
	std::cout << m << std::endl << std::endl;
	m.decrementGrade(100);
	std::cout << m << std::endl << std::endl;
}