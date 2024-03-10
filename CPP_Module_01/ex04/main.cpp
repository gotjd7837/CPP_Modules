/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:23:34 by haekang           #+#    #+#             */
/*   Updated: 2024/03/10 18:38:58 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int ac, char *av[])
{
    if (ac != 4)
    {
        std::cout << "Error: Invalid arguments" << std::endl;
        return (1);
    }
    std::string infileName = av[1];
    std::string outfileName = infileName + ".replace";
    std::string s1 = av[2];
    std::string s2 = av[3];
    std::string line;
    std::string content;
    std::ifstream infileStream(infileName);
    if (!infileStream.is_open())
    {
        std::cout << "Error: File open failed" << std::endl;
        return (1);
    }
    while (std::getline(infileStream, line))
    {
        content += line + "\n";
    }
    infileStream.close();
    size_t pos = 0;
    while ((pos = content.find(s1, pos)) != std::string::npos)
    {
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();
    }
    std::ofstream outfileStream(outfileName.c_str());
    if (!outfileStream.is_open())
    {
        std::cout << "Error: File open failed" << std::endl;
        return (1);
    }
    outfileStream << content;
    outfileStream.close();
    return (0);
}
