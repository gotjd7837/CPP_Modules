/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:44:12 by haekang           #+#    #+#             */
/*   Updated: 2024/02/20 16:59:40 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
    public :
        Cat();
        Cat(const Cat& copy);
        Cat& operator = (const Cat& copy);
        ~Cat();
        void makeSound() const;
};

#endif