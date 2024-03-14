/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:47:41 by haekang           #+#    #+#             */
/*   Updated: 2024/03/15 00:26:58 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_HPP
# define Dog_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
    private :
        Brain* brain;
    public :
        Dog();
        Dog(const Dog& copy);
        Dog& operator = (const Dog& copy);
        ~Dog();
        void makeSound() const;

        void getIdea(int idx);
        void setIdea(int idx, std::string idea);
};

#endif