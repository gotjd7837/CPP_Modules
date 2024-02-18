/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:08:13 by haekang           #+#    #+#             */
/*   Updated: 2024/02/18 11:26:14 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

    public:
        ScavTrap();
        ScavTrap(const std::string name);
        ScavTrap(const ScavTrap& copy);
        ScavTrap& operator = (const ScavTrap& copy);
        ~ScavTrap();
        void    attack(const std::string& target);
        void    guardGate();
};

#endif