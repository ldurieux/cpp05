#ifndef FORM_H
#define FORM_H

#include <string>

class Bureaucrat;

class Form
{
public:
	Form(const std::string& name, int signGrade, int execGrade);

	void beSigned(const Bureaucrat& bureaucrat);

	const std::string& name() const;
	bool isSigned() const;
	int signGrade() const;
	int execGrade() const;

	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw()
		{
			return "Grade too high";
		}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw()
		{
			return "Grade too low";
		}
	};

private:
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _execGrade;
};

std::ostream& operator<<(std::ostream& out, const Form& a);

#endif // FORM_H
