/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:08:16 by haekang           #+#    #+#             */
/*   Updated: 2024/02/19 21:17:17 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
: ClapTrap()
{
    std::cout << "ScavTrap : Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name)
: ClapTrap(name)
{
    std::cout << "ScavTrap : Name constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy)
: ClapTrap(copy)
{
    std::cout << "ScavTrap : Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator = (const ScavTrap& copy)
{
    this->name = copy.name;
    this->hitPoint = copy.hitPoint;
    this->energyPoint = copy.energyPoint;
    this->attackDamage = copy.attackDamage;
    
    std::cout << "ScavTrap : operator = called" << std::endl;
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap : Destructor called" << std::endl;
}

void    ScavTrap::attack(const std::string& target)
{
    if (this->hitPoint == 0 || this->energyPoint == 0)
    {
        std::cout << "ScavTrap " << this->name << " is already dead" << std::endl;
        return ;
    }
    else
    {
        std::cout << "ScavTrap "
        << this->name << " attack " << target << ", causing "
        << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoint -= 1;
    }
}

void    ScavTrap::guardGate()
{
    if (this->hitPoint == 0 || this->energyPoint == 0)
    {
        std::cout << "ScavTrap " << this->name << " is already dead" << std::endl;
        return ;
    }
    else
    {
        std::cout << "ScavTrap " << this->name
        << " have enterred in Gate keeper mode" << std::endl;
        this->energyPoint -= 1;
    }
}