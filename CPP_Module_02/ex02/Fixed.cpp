/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:40:04 by haekang           #+#    #+#             */
/*   Updated: 2024/02/15 20:26:08 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
: value(0) {}

Fixed::Fixed(const int value)
{
    this->value = (value << this->bits);
}

Fixed::Fixed(const float value)
{
    this->value = roundf(value * (1 << this->bits));
}

Fixed::Fixed(const Fixed& copy)
{
    *this = copy;
}

Fixed::~Fixed()
{
    
}

Fixed& Fixed::operator = (const Fixed& fixed)
{
    if (this != &fixed)
        this->value = fixed.getRawBits();
    return *this;
}

bool Fixed::operator > (const Fixed& fixed) const
{
    return (this->getRawBits() > fixed.getRawBits());
}

bool Fixed::operator < (const Fixed& fixed) const
{
    return (this->getRawBits() > fixed.getRawBits());
}

bool Fixed::operator >= (const Fixed& fixed) const
{
    return (this->getRawBits() >= fixed.getRawBits());
}

bool Fixed::operator <= (const Fixed& fixed) const
{
    return (this->getRawBits() <= fixed.getRawBits());
}

bool Fixed::operator == (const Fixed& fixed) const
{
    return (this->getRawBits() == fixed.getRawBits());
}

bool Fixed::operator != (const Fixed& fixed) const
{
    return (this->getRawBits() != fixed.getRawBits());
}

Fixed Fixed::operator + (const Fixed& fixed) const
{
    Fixed res(this->toFloat() + fixed.toFloat());
    return (res);
}

Fixed Fixed::operator - (const Fixed& fixed) const
{
    Fixed res(this->toFloat() - fixed.toFloat());
    return (res);
}

Fixed Fixed::operator * (const Fixed& fixed) const
{
    Fixed res(this->toFloat() * fixed.toFloat());
    return (res);
}

Fixed Fixed::operator / (const Fixed& fixed) const
{
    Fixed res(this->toFloat() / fixed.toFloat());
    return (res);
}

Fixed& Fixed::operator ++ (void)
{
    this->value++;
    return (*this);
}

const Fixed Fixed::operator ++ (int)
{
    const Fixed res(*this);

    this->value++;
    return (res);
}

Fixed& Fixed::operator -- (void)
{
    this->value--;
    return (*this);
}

const Fixed Fixed::operator -- (int)
{
    const Fixed res(*this);

    this->value--;
    return (res);
}

Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
    if (fixed1.getRawBits() > fixed2.getRawBits())
        return (fixed2);
    else
        return (fixed1);
}

const Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
    if (fixed1.getRawBits() > fixed2.getRawBits())
        return (fixed2);
    else
        return (fixed1);
}
        
// Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2)
// {
//     if (fixed1.getRawBits() <= fixed2.getRawBits())
//         return (fixed2);
//     else
//         return (fixed1);
// }
        
const Fixed& Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
    if (fixed1.getRawBits() <= fixed2.getRawBits())
        return (fixed2);
    else
        return (fixed1);
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

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}