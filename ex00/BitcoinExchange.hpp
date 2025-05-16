/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:12:48 by paprzyby          #+#    #+#             */
/*   Updated: 2025/05/16 16:38:52 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <vector>
# include <sstream>
# include <climits>

class	BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const std::string file);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void						file_extension();
		void						read_database();
		std::vector<std::string>	split(const std::string line, char c);
		std::ifstream				open_input_file();
		bool						validate_input(std::string line);
		void						calculate_exchange();

	private:
		std::string						file;
		std::map<std::string, double>	data;
		std::vector<std::string>		split_data;
		std::vector<std::string>		input;
		std::vector<std::string>		input_date;
};

#endif
