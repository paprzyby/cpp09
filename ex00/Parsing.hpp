/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:42:08 by paprzyby          #+#    #+#             */
/*   Updated: 2025/05/15 14:43:07 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_HPP
# define PARSING_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <vector>
# include <sstream>

class	Parsing
{
	public:
		Parsing();
		Parsing(const std::string file);
		Parsing(const Parsing &other);
		Parsing &operator=(const Parsing &other);
		~Parsing();

		void						file_extension();
		void						read_database();
		std::vector<std::string>	split(const std::string line, char c);
		std::ifstream				open_input_file();
		void						validate_input(std::string line);

	protected:
		std::string						file;
		std::map<std::string, float>	input;
		std::map<std::string, float>	data;
		std::vector<std::string>		split_data;
		std::vector<std::string>		split_input;
		std::vector<std::string>		split_input_date;
};

#endif
