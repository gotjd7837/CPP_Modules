/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:40:04 by haekang           #+#    #+#             */
/*   Updated: 2024/03/12 12:49:34 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
: value(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed& Fixed::operator = (const Fixed& fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        this->value = fixed.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->value = (value << this->bits);
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(value * (1 << this->bits));
}

int Fixed::getRawBits(void) const
{
    return this->value;
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

float Fixed::toFloat(void) const
{
    return (float)this->value / (1 << this->bits);
}

int Fixed::toInt(void) const
{
    return this->value >> this->bits;
}

std::ostream& operator << (std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}