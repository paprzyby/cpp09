/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:55:17 by paprzyby          #+#    #+#             */
/*   Updated: 2025/05/16 16:35:34 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()	{}

BitcoinExchange::BitcoinExchange(const std::string file)
{
	this->file = file;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : file(other.file), data(other.data),
	split_data(other.split_data), input(other.input), input_date(other.input_date)	{}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		file = other.file;
		data = other.data;
		split_data = other.split_data;
		input = other.input;
		input_date = other.input_date;
	}
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

std::ifstream	BitcoinExchange::open_input_file()
{
	std::ifstream	opened_file(file.c_str());

	if (!opened_file.is_open())
	{
		throw std::runtime_error("Error while opening the file");
	}
	return (opened_file);
}

bool	BitcoinExchange::validate_input(std::string line)
{
	input = split(line, ' ');
	if (input.size() != 3 || input[1] != "|")
	{
		std::cout << "Error: bad input => <date> | <value>" << std::endl;
		return (1);
	}
	for (std::size_t i = 0; i < input[0].size(); ++i)
	{
		if (input[0][i] != '-' && (input[0][i] > '9' && input[0][i] < '0'))
		{
			std::cout << "Error: bad input date => <yyyy-mm-dd> | <value>" << std::endl;
			return (1);
		}
	}
	for (std::size_t i = 0; i < input[2].size(); ++i)
	{
		if (input[0][i] != '-' && (input[0][i] > '9' && input[0][i] < '0'))
		{
			std::cout << "Error: bad input date => <yyyy-mm-dd> | <value>" << std::endl;
			return (1);
		}
	}
	double num = std::stod(input[2]);
	if (num < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (1);
	}
	if (num > static_cast<double>(INT_MAX))
	{
		std::cout << "Error: too large a number" << std::endl;
		return (1);
	}
	input_date = split(input[0], '-');
	if (input_date.size() != 3)
	{
		std::cout << "Error: bad input date => <yyyy-mm-dd> | <value>" << std::endl;
		return (1);
	}
	int year = std::stoi(input_date[0]);
	int month = std::stoi(input_date[1]);
	int day = std::stoi(input_date[2]);
	if (month < 1 || month > 12 || day < 1 || day > 31)
	{
		std::cerr << "Error: bad input => " << input[0] << std::endl;
		return (1);
	}
	if ((day > 30) && (month == 04 || month == 06 || month == 9 || month == 11))
	{
		std::cerr << "Error: bad input => " << input[0] << std::endl;
		return (1);
	}
	if (month == 2)
	{
		bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (day > 29 || (day == 29 && day != leap))
		{
			std::cerr << "Error: bad input => " << input[0] << std::endl;
			return (1);
		}
	}
	return (0);
}

void	BitcoinExchange::calculate_exchange()
{
	std::string input_date = input[0];
	double input_value = std::stod(input[2]);
	auto it = data.lower_bound(input_date);

	if (it == data.end() || it->first != input_date)
	{
		if (it == data.begin())
		{
			std::cerr << "Error: no exchange rate available for date " << input_date << std::endl;
			return;
		}
		--it;
	}
	double exchange_rate = it->second;
	double exchanged_value = input_value * exchange_rate;
	std::cout << input_date << " => " << input_value << " = " << exchanged_value << std::endl;
}
