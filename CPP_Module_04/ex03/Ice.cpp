/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:46:31 by haekang           #+#    #+#             */
/*   Updated: 2024/02/23 20:28:04 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice()
: AMateria("ice")
{
    
}

Ice::Ice(const Ice& copy)
: AMateria(copy)
{
    
}

Ice& Ice::operator = (const Ice& copy)
{
    if (this == &copy)
        return (*this);
    this->type = copy.type;
    return (*this);
}

Ice::~Ice()
{
    
}

AMateria* Ice::clone() const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}