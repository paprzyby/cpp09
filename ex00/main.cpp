/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:18:14 by paprzyby          #+#    #+#             */
/*   Updated: 2025/05/15 14:49:58 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Too few arguments passed." << std::endl;
		std::cerr << "Usage: ./btc <filename>" << std::endl;
		return (1);
	}
	else if (ac == 2)
	{
		try
		{
			Parsing	parsing(av[1]);
			parsing.file_extension();
			parsing.read_database();
			std::string		line;
			std::ifstream	file;

			file = parsing.open_input_file();
			while (std::getline(file, line))
			{
				parsing.validate_input(line);
				//btc class
				//if everything is valid => main logic here
			}
			file.close();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		return (0);
	}
	else
	{
		std::cerr << "Too many arguments passed." << std::endl;
		std::cerr << "Usage: ./btc <filename>" << std::endl;
		return (1);
	}
}
