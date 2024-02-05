/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:46:03 by haekang           #+#    #+#             */
/*   Updated: 2024/02/05 13:52:56 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string &ref = str;
    std::string *ptr;
    
    ptr = &str;
    std::cout << "str address : " << &str << std::endl;
    std::cout << "ptr address : " << ptr << std::endl;
    std::cout << "ref address : " << &ref << std::endl;
    std::cout << "str : " << str << std::endl;
    std::cout << "ptr : " << *ptr << std::endl;
    std::cout << "ref : " << ref << std::endl;
    return (0);
}