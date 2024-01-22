/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:31:22 by haekang           #+#    #+#             */
/*   Updated: 2024/01/22 19:28:15 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int		main(void)
{
    PhoneBook	phoneBook = PhoneBook();
    std::string	command;

    while (1)
    {
        std::cout << "Enter command: ";
        if (!getline(std::cin, command))
            break;
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
