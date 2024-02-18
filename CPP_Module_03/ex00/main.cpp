/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:57:12 by haekang           #+#    #+#             */
/*   Updated: 2024/02/17 20:05:49 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap clapTrap1("clapTrap1");
    ClapTrap clapTrap2("clapTrap2");

    clapTrap1.attack("clapTrap2");
    clapTrap2.takeDamege(5);
    clapTrap2.beRepaired(5);
    
    clapTrap2.attack("clapTrap1");
    clapTrap1.takeDamege(10);
    clapTrap1.beRepaired(5);
    return (0);
}