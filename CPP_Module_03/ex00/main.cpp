/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:57:12 by haekang           #+#    #+#             */
/*   Updated: 2024/03/13 17:45:02 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    std::cout << "------------test1-------------" << std::endl;
    {
        ClapTrap clapTrap1("clapTrap1");
        ClapTrap clapTrap2("clapTrap2");

        clapTrap1.attack("clapTrap2");
        clapTrap2.takeDamege(5);
        clapTrap2.beRepaired(5);
    
        clapTrap2.attack("clapTrap1");
        clapTrap1.takeDamege(10);
        clapTrap1.beRepaired(5);
    }
    std::cout << "------------test2-------------" << std::endl;
    {
        ClapTrap clapTrap1("clapTrap1");
        for (int i = 0; i < 10; i++)
            clapTrap1.attack("target");
        clapTrap1.attack("target");
    }
    return (0);
}