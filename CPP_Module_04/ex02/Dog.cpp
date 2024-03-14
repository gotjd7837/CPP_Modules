/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:54:59 by haekang           #+#    #+#             */
/*   Updated: 2024/03/15 00:27:10 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
: Animal()
{
    this->type = "Dog";
    this->brain = new Brain();

    std::cout << "Dog constructor" << std::endl;
}

Dog::Dog(const Dog& copy)
: Animal(copy)
{
    this->brain = new Brain(*copy.brain);
    std::cout << "Dog copy constructor" << std::endl;
}

Dog& Dog::operator = (const Dog& copy)
{
    this->type = copy.type;
    this->brain = new Brain(*copy.brain);
    
    std::cout << "Dog copy operator" << std::endl;
    return (*this);
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog destructor" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Dog sound" << std::endl;
}

void Dog::getIdea(int idx)
{
    std::cout << "idea " << idx << " :" << this->brain->ideas[idx] << std::endl;
}

void Dog::setIdea(int idx, std::string idea)
{
    this->brain->ideas[idx] = idea;
}
