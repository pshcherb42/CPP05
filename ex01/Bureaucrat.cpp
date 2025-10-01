#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default name"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {};

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		// manualy call the destructor of the left side object to clean it up
		this->~Bureaucrat();
		// use placement new syntax to copy construct a new Bureaucrat object
		// from other into this.
		new (this) Bureaucrat(other);
	}
	return *this;
}


int Bureaucrat::getGrade() const { return(_grade); }

const std::string Bureaucrat::getName() const { return(_name); }


Bureaucrat::~Bureaucrat() {};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
	return (os << obj.getName() << ", bureaucrat grade " << obj.getGrade());
};

void Bureaucrat::incrementGrade(int increment) {
	_grade -= increment;
	std::cout << "Incrementing grade..." << std::endl;
	try {
		if (_grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (_grade < 1)
			throw Bureaucrat::GradeTooHighException();
	} catch (std::exception & e) {
		std::cout << "Caught out of range: " << e.what() << std::endl;
	}
}

void Bureaucrat::decrementGrade(int decrement) {
	_grade += decrement;
	std::cout << "Decrementing grade ..." << std::endl;
	try {
	    if (_grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (_grade < 1)
			throw Bureaucrat::GradeTooHighException();
	} catch (std::exception & e) {
		std::cout << "Caught out of range: " << e.what() << std::endl;
	} 
}