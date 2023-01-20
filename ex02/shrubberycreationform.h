#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include <iostream>
#include <fstream>
#include <string>
#include "bureaucrat.h"
#include "form.h"

class ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm(const std::string& target);
	~ShrubberyCreationForm();

	void execute(const Bureaucrat& bureaucrat) const;

private:
	std::string _target;
};

#endif // SHRUBBERYCREATIONFORM_H
