#include "bureaucrat.h"

Bureaucrat::Bureaucrat(const std::string& name, int grade) :
	_name(name),
	_grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

void Bureaucrat::increment()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrement()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

const std::string& Bureaucrat::name() const
{
	return _name;
}

int Bureaucrat::grade() const
{
	return _grade;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& a)
{
	out << a.name() << ", bureaucrat grade " << a.grade();
	return out;
}
