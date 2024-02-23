/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:36:30 by haekang           #+#    #+#             */
/*   Updated: 2024/02/24 00:59:53 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(const std::string& type)
: type(type)
{
    
}

AMateria::AMateria(const AMateria& copy)
: type(copy.type)
{
    
}

AMateria& AMateria::operator = (const AMateria& copy)
{
    this->type = copy.type;
    return (*this);
}

AMateria::~AMateria()
{
    
}

const std::string& AMateria::getType() const
{
    return (this->type);
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}