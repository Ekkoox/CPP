/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:41:52 by enschnei          #+#    #+#             */
/*   Updated: 2025/09/11 14:41:52 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void replace_txt(std::ifstream &infile, std::ofstream &outfile,
                 const std::string &s1, const std::string &s2)
{
    std::string line;
    while (std::getline(infile, line))
    {
        size_t position = 0;
        while ((position = line.find(s1, position)) != std::string::npos)
        {
            line.erase(position, s1.length());
            line.insert(position, s2);
            position += s2.length();
        }
        outfile << line;
        if (!infile.eof())
            outfile << '\n';
    }
    if (infile.bad())
        std::cerr << "Error: reading failed" << std::endl;
    if (outfile.bad())
        std::cerr << "Error: writing failed" << std::endl;
}

int main(int ac, char **av)
{
    if (ac != 4)
        return (std::cout << "Error number of arguments" << std::endl, 1);

    std::string s1 = av[2];
    std::string s2 = av[3];

    if (s1.empty())
    {
        std::cerr << "Error: search string cannot be empty" << std::endl;
        return 1;
    }
    if (s1 == s2)
    {
        std::cerr << "Error: search and replace strings are identical" << std::endl;
        return 1;
    }

    std::ifstream infile(av[1], std::ios::binary);
    if (!infile.is_open())
    {
        std::cerr << "Error opening input file" << std::endl;
        return 1;
    }

    std::string outFilename = std::string(av[1]) + ".replace";
    std::ofstream outfile(outFilename.c_str(), std::ios::binary);
    if (!outfile.is_open())
    {
        std::cerr << "Error opening output file" << std::endl;
        return 1;
    }

    replace_txt(infile, outfile, s1, s2);

    std::cout << "GOOD !" << std::endl;
    return 0;
}

