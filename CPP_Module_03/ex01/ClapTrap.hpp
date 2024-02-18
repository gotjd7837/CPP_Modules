/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:57:18 by haekang           #+#    #+#             */
/*   Updated: 2024/02/18 11:25:37 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
    protected :
        std::string name;
        unsigned int hitPoint;
        unsigned int energyPoint;
        unsigned int attackDamage;
    public :
        ClapTrap();
        ClapTrap(const std::string name);
        ClapTrap(const ClapTrap& copy);
        ClapTrap& operator = (const ClapTrap& copy);
        virtual ~ClapTrap();
        virtual void attack(const std::string& target);
        void takeDamege(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif