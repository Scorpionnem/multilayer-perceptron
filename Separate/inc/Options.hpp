/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Options.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:38:20 by mbatty            #+#    #+#             */
/*   Updated: 2026/02/16 15:40:07 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>
#include <iostream>

class	Options
{
	public:
		Options() {}
		~Options() {}

		int	parse(char **args);

		void	setStringOpt(std::string long_id, std::string short_id, std::string &v);
		void	setIntOpt(std::string long_id, std::string short_id, int &v);
		void	setBoolOpt(std::string long_id, std::string short_id, bool &v);
		void	setFloatOpt(std::string long_id, std::string short_id, float &v);
	private:
		std::map<std::string, std::string&>	string_options;
		std::map<std::string, int&>			int_options;
		std::map<std::string, bool&>		bool_options;
		std::map<std::string, float&>		float_options;
};
