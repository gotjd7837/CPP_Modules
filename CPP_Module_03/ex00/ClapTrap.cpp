/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:57:16 by haekang           #+#    #+#             */
/*   Updated: 2024/02/18 11:25:19 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
: name("default"), hitPoint(10), energyPoint(10), attackDamage(0)
{
    std::cout << "ClapTrap : Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name)
: name(name), hitPoint(10), energyPoint(10), attackDamage(0)
{
    std::cout << "ClapTrap : Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
    this->name = copy.name;
    this->hitPoint = copy.hitPoint;
    this->energyPoint = copy.energyPoint;
    this->attackDamage = copy.attackDamage;

    std::cout << "ClapTrap : Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator = (const ClapTrap& copy)
{
    this->name = copy.name;
    this->hitPoint = copy.hitPoint;
    this->energyPoint = copy.energyPoint;
    this->attackDamage = copy.attackDamage;

    std::cout << "ClapTrap : operator = called" << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap : Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->hitPoint == 0 || this->energyPoint == 0)
    {
        std::cout << "ClapTrap " << this->name << " is already dead" << std::endl;
        return ;
    }
    else
    {
        std::cout << "ClapTrap "
        << this->name << " attack " << target << ", causing "
        << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoint -= 1;
    }
}

void ClapTrap::takeDamege(unsigned int amount)
{
    if (amount > this->hitPoint)
    {
        this->hitPoint = 0;
        std::cout << "ClapTrap " << this->name << " is dead" << std::endl;   
    }
    else
    {
        this->hitPoint -= amount;
        std::cout << "ClapTrap " << this->name << " take " << amount << " damage" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hitPoint == 0 || this->energyPoint == 0)
    {
        std::cout << "ClapTrap " << this->name << " is already dead" << std::endl;
        return ;
    }
    else
    {
        this->hitPoint += amount;
        std::cout << "ClapTrap " << this->name << " is repaired " << amount << " hit point" << std::endl;
        this->energyPoint -= 1;
    }
}