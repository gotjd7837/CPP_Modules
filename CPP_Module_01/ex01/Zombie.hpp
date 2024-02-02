/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:42:07 by haekang           #+#    #+#             */
/*   Updated: 2024/02/02 18:04:39 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
    private:
        std::string name;
    public:
        void announce(void);
        void setName(std::string str);
        Zombie(void);
        Zombie(std::string name);
        ~Zombie();
};

Zombie* zombieHorde(int N, std::string name);

#endif