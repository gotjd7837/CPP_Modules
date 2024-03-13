/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:57:12 by haekang           #+#    #+#             */
/*   Updated: 2024/03/13 18:51:49 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    std::cout << "------------test1-------------" << std::endl;
    {
        FragTrap a;
        FragTrap b("b");
        FragTrap c(b);
        FragTrap d;
        d = c;
        a.highFivesGuys();
        b.highFivesGuys();
        c.highFivesGuys();
        d.highFivesGuys();
    }
    std::cout << "------------test2-------------" << std::endl;
    {
        FragTrap a;
        FragTrap b("b");
        FragTrap c(b);
        FragTrap d;
        d = c;
        a.attack("b");
        b.takeDamege(10);
        c.beRepaired(10);
        d.attack("b");
    }
    return (0);
}
