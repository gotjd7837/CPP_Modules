/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:42:41 by haekang           #+#    #+#             */
/*   Updated: 2024/02/02 16:50:03 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    randomChump("random zombie");
    std::cout << "ramdom zombie가 생기고 죽음" << "\n" << std::endl;

    Zombie *zombie2 = newZombie("Dynamic zombie");
    zombie2->announce();
    delete zombie2;
    std::cout << "소멸자 호출하기 위해 delete사용" << "\n" <<std::endl;

    Zombie zombie("static zombie");
    zombie.announce();    
    std::cout << "static zombie 소멸" << std::endl;
    return (0);
}