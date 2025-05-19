/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:36:49 by paprzyby          #+#    #+#             */
/*   Updated: 2025/05/19 13:09:41 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()	{}

RPN::RPN(const RPN &other) : nums(other.nums)	{}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		nums = other.nums;
	}
	return (*this);
}

RPN::~RPN()	{}

void	RPN::input_validation(std::string str)
{
	std::istringstream iss(str);
	std::string result;

	while (iss >> result)
	{
		if (result.size() != 1)
		{
			throw std::runtime_error("Error");
		}
		else if (!std::isdigit(result[0]) && result != "+" && result != "-" && result != "*" && result != "/")
		{
			throw std::runtime_error("Error");
		}
	}
}
