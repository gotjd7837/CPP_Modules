/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:57:12 by haekang           #+#    #+#             */
/*   Updated: 2024/02/20 15:13:17 by haekang          ###   ########.fr       */
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

    attack(&clap, "scav");
    attack(&scav, "clap");
    return (0);
}