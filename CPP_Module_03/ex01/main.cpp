/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:57:12 by haekang           #+#    #+#             */
/*   Updated: 2024/02/19 20:47:39 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void    attack(ClapTrap* attacker, std::string target)
{
    attacker->attack(target);
}

int main()
{
    ClapTrap clap("clap");
    ScavTrap scav("scav");

    attack(&scav, "clap");
    attack(&clap, "scav");
    return (0);
}