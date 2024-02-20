/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:35:21 by haekang           #+#    #+#             */
/*   Updated: 2024/02/20 17:35:22 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
: WrongAnimal()
{
    this->type = "WrongCat";

    std::cout << "WrongCat constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy)
: WrongAnimal(copy)
{
    std::cout << "WrongCat copy constructor" << std::endl;
}

WrongCat& WrongCat::operator = (const WrongCat& copy)
{
    this->type = copy.type;
    
    std::cout << "WrongCat copy operator" << std::endl;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat sound" << std::endl;
}
