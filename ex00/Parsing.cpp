/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:41:59 by paprzyby          #+#    #+#             */
/*   Updated: 2025/05/15 14:10:26 by paprzyby         ###   ########.fr       */
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

void Parsing::print_data() const //for testing
{
    for (const auto &entry : data)
    {
        std::cout << entry.first << " => " << entry.second << std::endl;
    }
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

//void	Parsing::validate_input(std::string line)
//{
//	split_input = split(line, ' ');
//	if (split_input.size() != 3)
//	{

//	}
//	//check for 3 nodes in vector container
//	//check for "|" in the middle
//}

//void	Parsing::read_input_file()
//{
//	std::ifstream	opened_file(file.c_str());
//	std::string		line;

//	if (!opened_file.is_open())
//	{
//		throw std::runtime_error("Error while opening the file");
//	}
//	while (std::getline(opened_file, line))
//	{
//		//validate_input(line);
//	}
//}
