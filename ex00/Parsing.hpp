/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:42:08 by paprzyby          #+#    #+#             */
/*   Updated: 2025/05/09 18:53:18 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_HPP
# define PARSING_HPP

# include <iostream>
# include <map>
# include <fstream>

class	Parsing
{
	public:
		Parsing();
		Parsing(const std::string file);
		Parsing(const Parsing &other);
		Parsing &operator=(const Parsing &other);
		~Parsing();

		void	file_extension();
		void	read_input_file();

	protected:
		std::string						file;
		std::map<std::string, float>	input;
		std::map<std::string, float>	data;
};

#endif
