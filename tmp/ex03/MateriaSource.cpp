/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:53:12 by haekang           #+#    #+#             */
/*   Updated: 2024/02/23 23:54:23 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
: materiasCount(0)
{
    for (int i = 0; i < 4; i++)
        this->materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& copy)
: materiasCount(copy.materiasCount)
{
    for (int i = 0; i < 4; i++)
    {
        if (copy.materias[i])
            this->materias[i] = copy.materias[i]->clone();
        else
            this->materias[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator = (const MateriaSource& copy)
{
    if (this == &copy)
        return (*this);
    this->materiasCount = copy.materiasCount;
    for (int i = 0; i < 4; i++)
    {
        if (this->materias[i])
            delete this->materias[i];
        if (copy.materias[i])
            this->materias[i] = copy.materias[i]->clone();
        else
            this->materias[i] = NULL;
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->materias[i])
            delete this->materias[i];
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (this->materiasCount < 4)
    {
        this->materias[this->materiasCount] = m;
        this->materiasCount++;
    }
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->materias[i] && this->materias[i]->getType() == type)
            return (this->materias[i]->clone());
    }
    return (NULL);
}