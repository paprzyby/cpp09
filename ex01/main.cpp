/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:35:37 by paprzyby          #+#    #+#             */
/*   Updated: 2025/05/16 17:38:44 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Too few arguments passed." << std::endl;
		std::cerr << "Usage: ./RPN <argument>" << std::endl;
		return (1);
	}
	else if (ac == 2)
	{
		//
	}
	else
	{
		std::cerr << "Too many arguments passed." << std::endl;
		std::cerr << "Usage: ./RPN <argument>" << std::endl;
		return (1);
	}
}
