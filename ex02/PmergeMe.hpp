/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:51:34 by paprzyby          #+#    #+#             */
/*   Updated: 2025/08/24 17:16:35 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <deque>
# include <list>
# include <algorithm>
# include <limits>
# include <climits>
# include <chrono>

class	PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void	parsingData(char **av);
		void	printBefore(char **av);
		void	FordJohnsonAlgorithm();
		void	startMeasureTime();
		void	binaryInsert(std::deque<int>& chain, int value);
		void	createPairs();
		void	sortPairs();
		void	JacobsthalInsert();

	private:
		std::deque<int>	dequeContainer;
		std::chrono::high_resolution_clock::time_point	startDeque;
		std::chrono::high_resolution_clock::time_point	endDeque;
		std::chrono::duration<double, std::micro>		durationDeque;
		std::deque<std::pair<int, int>> pairs;
		std::deque<int> mainChain;
		std::deque<int> pending;
		bool	hasOddElement;
		int		oddElement;
		

		std::list<int>		listContainer;
};

#endif
