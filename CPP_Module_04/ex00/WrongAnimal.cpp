/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:32:58 by haekang           #+#    #+#             */
/*   Updated: 2024/02/20 17:34:06 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
: type("WrongAnimal") 
{
    std::cout << "WrongAnimal constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
: type(copy.type)
{
    std::cout << "WrongAnimal copy constructor" << std::endl;
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal& copy)
{
    this->type = copy.type;
    
    std::cout << "WrongAnimal copy operator" << std::endl;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}