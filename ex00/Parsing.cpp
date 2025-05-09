/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:41:59 by paprzyby          #+#    #+#             */
/*   Updated: 2025/05/09 18:54:32 by paprzyby         ###   ########.fr       */
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

void	Parsing::read_input_file()
{
	std::ifstream	opened_file(file.c_str());
	std::string		line;

	if (!opened_file.is_open())
	{
		throw std::runtime_error("Error while opening the file");
	}
	while (std::getline(opened_file, line))
	{
		//split "line" with "|"
	}
}