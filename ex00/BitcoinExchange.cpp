/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:55:17 by paprzyby          #+#    #+#             */
/*   Updated: 2025/05/09 18:44:35 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()	{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	//finish
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	//finish
	(void)other;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()	{}
