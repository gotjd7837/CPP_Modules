/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:09:57 by haekang           #+#    #+#             */
/*   Updated: 2024/02/20 16:41:26 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
: type("Animal") 
{
    std::cout << "Animal constructor" << std::endl;
}

Animal::Animal(const Animal& copy)
: type(copy.type)
{
    std::cout << "Animal copy constructor" << std::endl;
}

Animal& Animal::operator = (const Animal& copy)
{
    this->type = copy.type;
    
    std::cout << "Animal copy operator" << std::endl;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal destructor" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const
{
    return (this->type);
}