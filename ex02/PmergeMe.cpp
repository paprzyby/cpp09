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

PmergeMe::PmergeMe() : startDeque(std::chrono::high_resolution_clock::now()), endDeque(std::chrono::high_resolution_clock::now()), durationDeque(0) {}

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

void	PmergeMe::printBefore(char **av)
{
	std::cout << "Before: ";
	for (int i = 1; av[i]; i++)
	{
		std::cout << av[i] << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::parsingData(char **av)
{
	long long	num;

	for (int i = 1; av[i]; i++)
	{
		try
		{
			num = std::stoll(av[i]);
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
		dequeContainer.push_back(static_cast<int>(num));
		listContainer.push_back(static_cast<int>(num));
	}
}

void	PmergeMe::startMeasureTime()
{
	startDeque = std::chrono::high_resolution_clock::now();
	endDeque = std::chrono::high_resolution_clock::now();
	durationDeque = endDeque - startDeque;
}

void	PmergeMe::FordJohnsonAlgorithm()
{
	startMeasureTime();
	std::deque<std::pair<int, int> > pairs;
	bool	hasOddElement = false;
	for (int i = 0; i < static_cast<int>(dequeContainer.size()); i = i + 2)
	{
		if (i + 1 < static_cast<int>(dequeContainer.size()))
		{
			if (dequeContainer[i] < dequeContainer[i + 1])
				pairs.push_back(std::make_pair(dequeContainer[i], dequeContainer[i + 1]));
			else
				pairs.push_back(std::make_pair(dequeContainer[i + 1], dequeContainer[i]));
		}
		else
		{
			hasOddElement = true;
		}
	}
	std::cout << "After: ";
	std::cout << "<sorted numbers>";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << dequeContainer.size() << " elements with std::deque: "
			<< durationDeque.count() << " us" << std::endl;
	std::cout << "Time to process a range of " << listContainer.size() << " elements with std::list: "
			<< "<count>" << " us" << std::endl;
}
