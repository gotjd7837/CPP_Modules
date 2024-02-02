/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:21:11 by haekang           #+#    #+#             */
/*   Updated: 2024/02/02 20:42:59 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
    
}

Zombie::Zombie(std::string name)
{
    std::cout << "create Zombie!!!!! -> " << name << std::endl;
    this->name = name;
}

Zombie::~Zombie(void)
{
    std::cout << this->name << " : is dead." << std::endl;
}

void Zombie::announce(void) 
{
    std::cout << this->name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}
