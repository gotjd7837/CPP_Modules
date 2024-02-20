/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:18:29 by haekang           #+#    #+#             */
/*   Updated: 2024/02/20 20:31:35 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
    private :
        std::string ideas[100];

    public :
        Brain();
        Brain(const Brain& copy);
        Brain& operator = (const Brain& copy);
        ~Brain();
};

#endif