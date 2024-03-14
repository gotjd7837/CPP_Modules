/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:59:01 by haekang           #+#    #+#             */
/*   Updated: 2024/03/15 01:22:14 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    std::cout << "-----------test1-----------" << std::endl;
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        delete j;
        delete i;
    }
    std::cout << "-----------test2-----------" << std::endl;
    {
        Animal* animals[4];

        for (int i = 0; i < 4; i++)
        {
            if (i % 2 == 0)
                animals[i] = new Dog();
            else
                animals[i] = new Cat();
        }
        for (int i = 0; i < 4; i++)
        {
            std::cout << "type : " << animals[i]->getType() << std::endl;
            std::cout << "sound : ";
            animals[i]->makeSound();
        }
        for (int i = 0; i < 4; i++)
        {
            delete animals[i];
        }
    }
    std::cout << "-----------test3 (deep copy)-----------" << std::endl;
    {
        Dog* dog = new Dog();
        Dog* copy_dog = new Dog(*dog);

        dog->getIdea(3);
        copy_dog->getIdea(3);

        dog->setIdea(3, "pizza");

        dog->getIdea(3);
        copy_dog->getIdea(3);
        
        delete dog;
        delete copy_dog;
    }
    return (0);
}