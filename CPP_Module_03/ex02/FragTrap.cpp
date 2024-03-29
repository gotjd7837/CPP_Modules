/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:48:55 by haekang           #+#    #+#             */
/*   Updated: 2024/03/13 18:47:12 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
: ClapTrap()
{
    std::cout << "FragTrap : Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name)
: ClapTrap(name)
{
    std::cout << "FragTrap : Name constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy)
: ClapTrap(copy)
{
    std::cout << "FragTrap : Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator = (const FragTrap& copy)
{
    this->name = copy.name;
    this->hitPoint = copy.hitPoint;
    this->energyPoint = copy.energyPoint;
    this->attackDamage = copy.attackDamage;
    
    std::cout << "FragTrap : operator = called" << std::endl;
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap : Destructor called" << std::endl;
}

void FragTrap::highFivesGuys()
{
    if (this->hitPoint == 0)
    {
        std::cout << "FragTrap " << this->name << " is already dead" << std::endl;
        return ;
    }
    else if (this->energyPoint == 0)
    {
        std::cout << "FragTrap " << this->name << " has no energy" << std::endl;
        return ;
    }
    else
    {
        std::cout << "FragTrap " << this->name
        << " high five !" << std::endl;
        this->energyPoint -= 1;
    }
}