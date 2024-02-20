/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:47:41 by haekang           #+#    #+#             */
/*   Updated: 2024/02/20 16:57:13 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_HPP
# define Dog_HPP

# include "Animal.hpp"

class Dog : public Animal
{
    public :
        Dog();
        Dog(const Dog& copy);
        Dog& operator = (const Dog& copy);
        ~Dog();
        void makeSound() const;
};

#endif