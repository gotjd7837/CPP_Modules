/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:54:59 by haekang           #+#    #+#             */
/*   Updated: 2024/02/20 16:55:17 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
: Animal()
{
    this->type = "Dog";

    std::cout << "Dog constructor" << std::endl;
}

Dog::Dog(const Dog& copy)
: Animal(copy)
{
    std::cout << "Dog copy constructor" << std::endl;
}

Dog& Dog::operator = (const Dog& copy)
{
    this->type = copy.type;
    
    std::cout << "Dog copy operator" << std::endl;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Dog sound" << std::endl;
}