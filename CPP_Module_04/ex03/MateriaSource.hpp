/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:52:18 by haekang           #+#    #+#             */
/*   Updated: 2024/02/23 21:47:42 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria*		materias[4];
        int				materiasCount;
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& copy);
        MateriaSource& operator = (const MateriaSource& copy);
        ~MateriaSource();

        void learnMateria(AMateria* m);
        AMateria* createMateria(const std::string& type);
};

#endif