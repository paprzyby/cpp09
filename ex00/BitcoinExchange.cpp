/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:55:17 by paprzyby          #+#    #+#             */
/*   Updated: 2025/05/16 15:44:37 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()	{}

BitcoinExchange::BitcoinExchange(const std::string file)
{
	this->file = file;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	//finish
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	//finish
	(void)other;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()	{}

void	BitcoinExchange::file_extension()
{
	std::size_t	dot = file.find_last_of('.');

	if (dot != std::string::npos)
	{
		std::string extension = file.substr(dot + 1);
		if (extension == "txt")
		{
			return ;
		}
		throw std::runtime_error("Wrong file extension");
	}
	throw std::runtime_error("Wrong file name");
}

std::vector<std::string>	BitcoinExchange::split(const std::string line, char c)
{
	std::vector<std::string> result;
	std::stringstream ss(line);
	std::string token;

	while (std::getline(ss, token, c))
	{
		result.push_back(token);
	}
	return (result);
}

void	BitcoinExchange::read_database()
{
	std::ifstream database("data.csv");

	if (!database)
	{
		throw std::runtime_error("Error while opening the database file");
	}
	std::string	line;
	std::getline(database, line);
	while (std::getline(database, line))
	{
		split_data = split(line, ',');
		if (split_data.size() != 2)
		{
			throw std::runtime_error("Wrong syntax in database file");
		}
		data[split_data[0]] = std::stod(split_data[1]);
	}
	database.close();
}

void	BitcoinExchange::validate_input(std::string line)
{
	split_input = split(line, ' ');
	if (split_input.size() != 3 || split_input[1] != "|")
	{
		std::cout << "Error: bad input => <date> | <value>" << std::endl;
		return ;
	}
	for (std::size_t i = 0; i < split_input[0].size(); ++i)
	{
		if (split_input[0][i] != '-' && (split_input[0][i] > '9' && split_input[0][i] < '0'))
		{
			std::cout << "Error: bad input date => <yyyy-mm-dd> | <value>" << std::endl;
			return ;
		}
	}
	for (std::size_t i = 0; i < split_input[2].size(); ++i)
	{
		if (split_input[0][i] != '-' && (split_input[0][i] > '9' && split_input[0][i] < '0'))
		{
			std::cout << "Error: bad input date => <yyyy-mm-dd> | <value>" << std::endl;
			return ;
		}
	}
	double num = std::stod(split_input[2]);
	if (num < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return ;
	}
	if (num > static_cast<double>(INT_MAX))
	{
		std::cout << "Error: too large a number" << std::endl;
		return ;
	}
	split_input_date = split(split_input[0], '-');
	if (split_input_date.size() != 3)
	{
		std::cout << "Error: bad input date => <yyyy-mm-dd> | <value>" << std::endl;
		return ;
	}
	int year = std::stoi(split_input_date[0]);
	int month = std::stoi(split_input_date[1]);
	int day = std::stoi(split_input_date[2]);
	if (month < 1 || month > 12 || day < 1 || day > 31)
	{
		std::cerr << "Error: bad input => " << split_input[0] << std::endl;
		return ;
	}
	if ((day > 30) && (month == 04 || month == 06 || month == 9 || month == 11))
	{
		std::cerr << "Error: bad input => " << split_input[0] << std::endl;
		return ;
	}
	if (month == 2)
	{
		bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (day > 29 || (day == 29 && day != leap))
		{
			std::cerr << "Error: bad input => " << split_input[0] << std::endl;
			return ;
		}
	}

	std::cout << split_input[0] << std::endl; //testing
}

std::ifstream	BitcoinExchange::open_input_file()
{
	std::ifstream	opened_file(file.c_str());

	if (!opened_file.is_open())
	{
		throw std::runtime_error("Error while opening the file");
	}
	return (opened_file);
}

//std::map<std::string, double> prices;
//prices["2009-01-02"] = 123.45;