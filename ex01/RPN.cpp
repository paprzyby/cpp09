/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:36:49 by paprzyby          #+#    #+#             */
/*   Updated: 2025/05/20 13:49:05 by paprzyby         ###   ########.fr       */
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
		if (result.size() != 1 && std::isdigit(result[0]))
		{
			throw std::runtime_error("Error: Only numbers less than 10 are allowed");
		}
		else if (result.size() != 1)
		{
			throw std::runtime_error("Error: Wrong syntax");
		}
		else if (!std::isdigit(result[0]) && result != "+" && result != "-" && result != "*" && result != "/")
		{
			throw std::runtime_error("Error: Wrong characters");
		}
	}
}

int	RPN::calculation(std::string str)
{
	std::istringstream iss(str);
	std::string token;

	while (iss >> token)
	{
		if (std::isdigit(token[0]))
		{
			nums.push(token[0] - '0');
		}
		else
		{
			if (nums.size() < 2)
			{
				throw std::runtime_error("Error: Invalid RPN expression");
			}
			int b = nums.top();
			nums.pop();
			int a = nums.top();
			nums.pop();
			int result;
			if (token == "+")
				result = a + b;
			else if (token == "-")
				result = a - b;
			else if (token == "*")
				result = a * b;
			else if (token == "/")
			{
				if (b == 0)
					throw std::runtime_error("Error: Division by zero is not possible");
				result = a / b;
			}
			nums.push(result);
		}
	}
	if (nums.size() != 1)
	{
		throw std::runtime_error("Error: Invalid RPN expression");
	}
	return (nums.top());
}
