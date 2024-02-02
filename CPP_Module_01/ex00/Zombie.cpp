/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:42:53 by haekang           #+#    #+#             */
/*   Updated: 2024/02/02 17:22:35 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

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
