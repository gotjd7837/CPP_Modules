/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:18:29 by haekang           #+#    #+#             */
/*   Updated: 2024/03/15 00:23:48 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
    public :
        std::string ideas[100];
        
        Brain();
        Brain(const Brain& copy);
        Brain& operator = (const Brain& copy);
        ~Brain();
};

#endif