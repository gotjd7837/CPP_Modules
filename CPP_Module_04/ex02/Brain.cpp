/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:35:24 by haekang           #+#    #+#             */
/*   Updated: 2024/02/20 21:41:20 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "idea";
    std::cout << "Brain constructor" << std::endl;
}

Brain::Brain(const Brain& copy)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = copy.ideas[i];
    std::cout << "Brain copy constructor" << std::endl;
}

Brain& Brain::operator = (const Brain& copy)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = copy.ideas[i];
    std::cout << "Brain copy operator" << std::endl;
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor" << std::endl;
}
