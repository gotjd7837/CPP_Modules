/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:03:08 by haekang           #+#    #+#             */
/*   Updated: 2024/02/20 16:26:29 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
    protected :
        std::string type;
    public :
        Animal();
        Animal(const Animal& copy);
        Animal& operator = (const Animal& copy);
        virtual ~Animal();
        virtual void makeSound() const;
        std::string getType() const;
};

#endif