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

PmergeMe::PmergeMe() : startDeque(std::chrono::high_resolution_clock::now()), endDeque(std::chrono::high_resolution_clock::now()), durationDeque(0), hasOddElement(false), oddElement(0) {}

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

void PmergeMe::binaryInsert(std::deque<int>& chain, int value)
{
    std::deque<int>::iterator pos = std::lower_bound(chain.begin(), chain.end(), value);
    chain.insert(pos, value);
}

void	PmergeMe::createPairs()
{
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
			oddElement = dequeContainer[i];
		}
	}
}

void	PmergeMe::sortPairs()
{
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		mainChain.push_back(pairs[i].second);
		pending.push_back(pairs[i].first);
	}
	std::sort(mainChain.begin(), mainChain.end());
}

void	PmergeMe::JacobsthalInsert()
{
	std::deque<size_t> jacob;
	size_t j1 = 1;
	size_t j2 = 0;
	while (true)
	{
		size_t j = j1 + 2 * j2;
		if (j >= pending.size())
			break;
		jacob.push_back(j);
		j2 = j1;
		j1 = j;
	}
	std::deque<bool> used(pending.size(), false);
	for (size_t i = 0; i < jacob.size(); ++i)
	{
		size_t idx = jacob[i];
		binaryInsert(mainChain, pending[idx]);
		used[idx] = true;
	}
	for (size_t i = 0; i < pending.size(); ++i)
	{
		if (!used[i])
			binaryInsert(mainChain, pending[i]);
	}
	if (hasOddElement)
   		binaryInsert(mainChain, oddElement);
}

void	PmergeMe::FordJohnsonAlgorithm()
{
	//start measuring time:
	startMeasureTime();
	//creating pairs:
	createPairs();
	//sorting pairs by second element:
	sortPairs();
	//inserting pending elements using Jacobsthal sequence:
	JacobsthalInsert();
	//printing results:
	std::cout << "After: ";
	for (size_t i = 0; i < mainChain.size(); ++i)
	{
		std::cout << mainChain[i] << " ";
	}
	std::cout << std::endl;
	// std::cout << "Time to process a range of " << dequeContainer.size() << " elements with std::deque: "
	// 		<< durationDeque.count() << " us" << std::endl;
	// std::cout << "Time to process a range of " << listContainer.size() << " elements with std::list: "
	// 		<< "<count>" << " us" << std::endl;
}
