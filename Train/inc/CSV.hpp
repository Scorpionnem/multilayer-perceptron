/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CSV.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:48:05 by mbatty            #+#    #+#             */
/*   Updated: 2026/02/17 18:22:49 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdint>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>

class	CSV
{
	public:
		CSV() {}
		~CSV() {}

		// @param skip Skip columns up to it
		void	parse(const std::string &path, std::unordered_set<uint32_t> skip_column);
		void	normalize_data();

		void	print();

		const std::vector<double>	&line(uint32_t l)
		{
			return (_data[l]);
		}
	private:
		double	_get_column_max(uint32_t col)
		{
			double	max = 0;

			for (auto &line : _data)
			{
				if (line[col] > max)
					max = line[col];
			}
			return (max);
		}

		std::vector<std::vector<double>>	_data;
		uint32_t						_columns = 0;
};
