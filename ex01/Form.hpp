#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"
#include <string>
#include <ostream>


class Form {
	private:
		const std::string _name;
		bool _sign;
		const int _gradeSign;
		const int _gradeExec;
	public:
		Form();
		Form(const std::string& name, bool sign, const int gradeSign, const int gradeExec);
		Form(const Form& other);
		Form& operator=(const Form& other);

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw() {
					return ("Grade too high!");
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw() {
					return ("Grade too low exception!");
				}
		};

		const std::string getName() const;
		bool getSign();
		const int getGradeSign() const;
		const int getGradeExec() const;

		void beSigned(const Bureaucrat& m);

		~Form();
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif