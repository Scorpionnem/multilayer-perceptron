/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Options.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:39:19 by mbatty            #+#    #+#             */
/*   Updated: 2026/02/16 15:40:21 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Options.hpp"

int	Options::parse(char **args)
{
	args++;
	int	i = -1;
	while (args[++i])
	{
		std::string	arg = args[i];
		if (string_options.find(arg) != string_options.end())
		{
			if (!args[i + 1])
				return (std::cerr << arg << " needs an argument" << std::endl, 0);
			string_options.find(arg)->second = args[i + 1];
			i++;
		}
		else if (int_options.find(arg) != int_options.end())
		{
			if (!args[i + 1])
				return (std::cerr << arg << " needs an argument" << std::endl, 0);
			int_options.find(arg)->second = std::atoi(args[i + 1]);
			i++;
		}
		else if (float_options.find(arg) != float_options.end())
		{
			if (!args[i + 1])
				return (std::cerr << arg << " needs an argument" << std::endl, 0);
			float_options.find(arg)->second = std::atof(args[i + 1]);
			i++;
		}
		else if (bool_options.find(arg) != bool_options.end())
			bool_options.find(arg)->second = true;
		else
			return (std::cerr << "Unknown option" << std::endl, 0);
	}
	return (1);
}

void	Options::setStringOpt(std::string long_id, std::string short_id, std::string &v)
{
	string_options.insert({long_id, v});
	string_options.insert({short_id, v});
}
void	Options::setIntOpt(std::string long_id, std::string short_id, int &v)
{
	int_options.insert({long_id, v});
	int_options.insert({short_id, v});
}
void	Options::setBoolOpt(std::string long_id, std::string short_id, bool &v)
{
	bool_options.insert({long_id, v});
	bool_options.insert({short_id, v});
}
void	Options::setFloatOpt(std::string long_id, std::string short_id, float &v)
{
	float_options.insert({long_id, v});
	float_options.insert({short_id, v});
}
