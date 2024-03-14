/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:57:12 by haekang           #+#    #+#             */
/*   Updated: 2024/03/14 16:25:19 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void    test_attack(ClapTrap& attacker, std::string target)
{
    attacker.attack(target);
}

int main()
{
    std::cout << "------------test1-------------" << std::endl;
    {
        ScavTrap scav("scav");

        test_attack(scav, "target");
        scav.guardGate();   
    }
    std::cout << "------------test2-------------" << std::endl;
    {
        ScavTrap scav("scav");
        for (int i = 0; i < 50; i++)
            test_attack(scav, "target");
        scav.guardGate();
    }
    return (0);
}