/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CSV.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:22:08 by mbatty            #+#    #+#             */
/*   Updated: 2026/02/17 18:22:57 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CSV.hpp"

void	CSV::parse(const std::string &path, std::unordered_set<uint32_t> skip_column)
{
	std::ifstream	file(path);
	if (!file.is_open())
	{
		std::cerr << "Failed to open " << path << std::endl;
		return ;
	}

	std::string	line;
	while (std::getline(file, line))
	{
		std::vector<double>	&vec = _data.emplace_back();

		std::stringstream	ss(line);

		std::string	data;
		uint32_t	column = 0;
		while (std::getline(ss, data, ','))
		{
			if (skip_column.find(column++) != skip_column.end())
				continue ;
			double	v = std::atof(data.c_str());

			vec.push_back(v);
		}
		_columns = column;
	}
	_columns -= skip_column.size();
}

void	CSV::normalize_data()
{
	for (uint32_t i = 0; i < _columns; i++)
	{
		double	m = _get_column_max(i);

		for (auto &vec : _data)
			vec[i] /= m;
	}
}

void	CSV::print()
{
	int	l = 1;
	for (auto &vec : _data)
	{
		std::cout << l++ << ": ";
		for (auto f : vec)
			std::cout << f << " ";
		std::cout << std::endl;
	}
}
