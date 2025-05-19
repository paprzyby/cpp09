/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:35:37 by paprzyby          #+#    #+#             */
/*   Updated: 2025/05/19 13:08:31 by paprzyby         ###   ########.fr       */
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
		try
		{
			RPN rpn;
			rpn.input_validation(av[1]);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
			return (1);
		}
	}
	else
	{
		std::cerr << "Too many arguments passed." << std::endl;
		std::cerr << "Usage: ./RPN <argument>" << std::endl;
		return (1);
	}
}
