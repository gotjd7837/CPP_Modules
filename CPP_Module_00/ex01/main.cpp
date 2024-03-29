/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:31:22 by haekang           #+#    #+#             */
/*   Updated: 2024/02/15 13:10:02 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int		main(void)
{
    PhoneBook	phoneBook;
    std::string	command;

    while (1)
    {
        if (!std::cin.eof())
            std::cout << "Enter command: ";
        if (!std::getline(std::cin, command))
            break ;
        if (command == "EXIT")
            break ;
        else if (command == "ADD")
            phoneBook.add();
        else if (command == "SEARCH")
            phoneBook.search();
        else
            std::cout << "Invalid command" << std::endl;
    }
    return (0);
}
