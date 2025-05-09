/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:18:14 by paprzyby          #+#    #+#             */
/*   Updated: 2025/05/09 18:31:54 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void	file_extension(std::string file)
{
	std::size_t	dot = file.find_last_of('.');

	if (dot != std::string::npos)
	{
		std::string extension = file.substr(dot + 1);
		if (extension == "txt")
			return ;
		throw std::runtime_error("Wrong file extension");
	}
	throw std::runtime_error("Wrong file name");
}

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	else if (ac == 2)
	{
		try
		{
			std::string	file = av[1];
			file_extension(file);
			BitcoinExchange	btc;
			std::ifstream opened_file(file.c_str());
			btc.read_input_file(opened_file);
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
		std::cerr << "Usage: ./convert <argument>" << std::endl;
		return (1);
	}
}

//std::map<std::string, double> prices;
//prices["2009-01-02"] = 123.45;