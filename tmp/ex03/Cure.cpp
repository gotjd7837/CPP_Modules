/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:49:03 by haekang           #+#    #+#             */
/*   Updated: 2024/02/23 20:27:59 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure()
: AMateria("cure")
{
    
}

Cure::Cure(const Cure& copy)
: AMateria(copy)
{
    
}

Cure& Cure::operator = (const Cure& copy)
{
    if (this == &copy)
        return (*this);
    this->type = copy.type;
    return (*this);
}

Cure::~Cure()
{
    
}

AMateria* Cure::clone() const
{
    return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}