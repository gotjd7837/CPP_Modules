/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:09:21 by haekang           #+#    #+#             */
/*   Updated: 2024/02/20 20:31:09 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
    protected :
        std::string type;
    public :
        WrongAnimal();
        WrongAnimal(const WrongAnimal& copy);
        WrongAnimal& operator = (const WrongAnimal& copy);
        ~WrongAnimal();
        void makeSound() const;
        std::string getType() const;
};

#endif