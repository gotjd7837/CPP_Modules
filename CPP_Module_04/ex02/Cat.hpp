/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:44:12 by haekang           #+#    #+#             */
/*   Updated: 2024/02/20 21:32:22 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
    private :
        Brain* brain;
    public :
        Cat();
        Cat(const Cat& copy);
        Cat& operator = (const Cat& copy);
        ~Cat();
        void makeSound() const;
};

#endif