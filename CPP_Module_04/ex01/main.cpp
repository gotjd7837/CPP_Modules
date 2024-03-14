/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:59:01 by haekang           #+#    #+#             */
/*   Updated: 2024/03/15 00:20:09 by haekang          ###   ########.fr       */
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
        system("leaks Ex01 | grep bytes");
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
        system("leaks Ex01 | grep bytes");
    }
    std::cout << "-----------test3 (deep copy)-----------" << std::endl;
    {
        Cat* cat = new Cat();
        Cat* copy_cat = new Cat(*cat);
        
        cat->getIdea(3);
        copy_cat->getIdea(3);

        cat->setIdea(3, "pizza");

        cat->getIdea(3);
        copy_cat->getIdea(3);

        delete cat;
        delete copy_cat;
        system("leaks Ex01 | grep bytes");
    }
    return 0;
}