/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:48:23 by haekang           #+#    #+#             */
/*   Updated: 2024/02/20 16:52:20 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
: Animal()
{
    this->type = "Cat";

    std::cout << "Cat constructor" << std::endl;
}

Cat::Cat(const Cat& copy)
: Animal(copy)
{
    std::cout << "Cat copy constructor" << std::endl;
}

Cat& Cat::operator = (const Cat& copy)
{
    this->type = copy.type;
    
    std::cout << "Cat copy operator" << std::endl;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Cat sound" << std::endl;
}
