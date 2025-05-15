/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:41:59 by paprzyby          #+#    #+#             */
/*   Updated: 2025/05/15 14:45:08 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parsing.hpp"

Parsing::Parsing()	{}

Parsing::Parsing(const std::string file)
{
	this->file = file;
}

Parsing::Parsing(const Parsing &other)
{
	//finish
	*this = other;
}

Parsing &Parsing::operator=(const Parsing &other)
{
	//finish
	(void)other;
	return (*this);
}

Parsing::~Parsing()	{}

void	Parsing::file_extension()
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

std::vector<std::string>	Parsing::split(const std::string line, char c)
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

void	Parsing::read_database()
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
		data[split_data[0]] = std::stof(split_data[1]);
	}
	database.close();
}

void	Parsing::validate_input(std::string line)
{
	split_input = split(line, ' ');
	if (split_input.size() != 3)
	{
		std::cout << "Error: bad input => <date> | <value>" << std::endl;
		return ;
	}
	//check for "|" in the middle
	//check for negative values
	//check for MAX_INT
	split_input_date = split(split_input[0], '-');
	if (split_input_date.size() != 3)
	{
		std::cout << "Error: bad input date => <yyyy-mm-dd> | <value>" << std::endl;
		return ;
	}
	//check for negative values
	//check for MAX_INT
	//check for months (betwwen 01 and 12)
	//check for day (between 01 and 31,30 or 28)
}

std::ifstream	Parsing::open_input_file()
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