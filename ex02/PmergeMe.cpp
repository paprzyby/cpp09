/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:52:08 by paprzyby          #+#    #+#             */
/*   Updated: 2025/08/24 17:28:40 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()	{}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		//
	}
	return (*this);
}

PmergeMe::~PmergeMe()	{}

void	PmergeMe::parsingData(char **av)
{
	long long	num;

	for (int i = 1; av[i]; i++)
	{
		try
		{
			num = std::stoll(av[i]);
			//need to check for decimal characters
		}
		catch(const std::exception& e)
		{
			throw std::runtime_error("Error: Only numbers are allowed");
		}
		if (num < 0)
		{
			throw std::runtime_error("Error: Only positive numbers are allowed");
		}
		else if (num > INT_MAX || num < INT_MIN)
		{
			throw std::runtime_error("Error: Only numbers that fit in an integer are allowed");
		}
	}
}

void	PmergeMe::printBefore(char **av)
{
	std::cout << "Before: ";
	for (int i = 1; av[i]; i++)
	{
		std::cout << av[i] << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::FordJohnsonAlgorithm(char **av)
{
	//to be implemented
	(void)av;
}
