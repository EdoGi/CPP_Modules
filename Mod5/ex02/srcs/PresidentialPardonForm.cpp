#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5), _target("Unnamed")
{
	std::cout << "PresidentialPardonForm Default Constructor called.";
	std::cout << BWHT << " Target : " + this->_target << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src )
{
	std::cout << "Copy Constructor called : PresidentialPardonForm" << std::endl;
	*this = src;	
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm Parametric Constructor called.";
	std::cout << BWHT << " Target : " + target << RESET << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destructor called : PresidentialPardonForm" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &				PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	std::cout << "Assignment operator called : PresidentialPardonForm" << std::endl;
	if ( this != &rhs )
		this->_target = rhs.getTarget();
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	PresidentialPardonForm::execute(void) const
{
	std::cout << BLUE << this->_target + " has been forgiven by Zaphod Beeblebrox the Great" << RESET << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

/* ************************************************************************** */