/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:59:01 by haekang           #+#    #+#             */
/*   Updated: 2024/02/20 17:40:19 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
// const Animal* meta = new Animal();
// const Animal* j = new Dog();
// const Animal* i = new Cat();
// std::cout << j->getType() << " " << std::endl;
// std::cout << i->getType() << " " << std::endl;
// i->makeSound(); //will output the cat sound!
// j->makeSound();
// meta->makeSound();
// delete meta;
// delete j;
// delete i;


const WrongAnimal* Wrong = new WrongAnimal();
const WrongAnimal* z = new WrongCat();
std::cout << z->getType() << " " << std::endl;
z->makeSound();
Wrong->makeSound();
delete Wrong;
delete z;


return 0;
}