/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 03:57:27 by haekang           #+#    #+#             */
/*   Updated: 2024/02/23 19:35:00 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

class ICharacter;

class AMateria
{
    protected:
        std::string		type;
    public:
        AMateria(const std::string& type);
        AMateria(const AMateria& copy);
        AMateria& operator = (const AMateria& copy);
        virtual ~AMateria();
        
        const std::string& getType() const;
        
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif
