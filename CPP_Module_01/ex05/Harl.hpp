/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 20:31:14 by haekang           #+#    #+#             */
/*   Updated: 2024/02/05 20:33:22 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl
{
    private :
        void debug();
        void info();
        void warning();
        void error();
    public :
        void complain(std::string level);
        Harl();
        ~Harl();
};

#endif