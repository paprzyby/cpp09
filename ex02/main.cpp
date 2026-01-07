/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:35:37 by paprzyby          #+#    #+#             */
/*   Updated: 2025/08/24 17:16:48 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Too few arguments passed." << std::endl;
		std::cerr << "Usage: ./PmergeMe <arguments>" << std::endl;
		return (1);
	}
	else
	{
		try
		{
			PmergeMe	sorter;

			sorter.parsingData(av);
			sorter.printBefore(av);
			sorter.FordJohnsonAlgorithm();
			return (0);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
			return (1);
		}
	}
}
