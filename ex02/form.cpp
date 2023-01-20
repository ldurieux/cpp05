#include "form.h"
#include "bureaucrat.h"

Form::Form() :
	_name(""),
	_signed(false),
	_signGrade(1),
	_execGrade(1)
{

}

Form::Form(const std::string& name, int signGrade, int execGrade) :
	_name(name),
	_signed(false),
	_signGrade(signGrade),
	_execGrade(execGrade)
{
	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
}

Form::~Form()
{
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (_signed)
	{
		std::cout << "Form already signed" << std::endl;
		return;
	}
	if (bureaucrat.grade() >= _signGrade)
		throw GradeTooLowException();
	_signed = true;
}

const std::string& Form::name() const
{
	return _name;
}

bool Form::isSigned() const
{
	return _signed;
}

int Form::signGrade() const
{
	return _signGrade;
}

int Form::execGrade() const
{
	return _execGrade;
}

std::ostream& operator<<(std::ostream& out, const Form& a)
{
	std::cout << a.name() << ", signed: " << a.isSigned()
			  << ", sign: " << a.signGrade() << ", exec: " << a.execGrade() << std::endl;
	return out;
}
