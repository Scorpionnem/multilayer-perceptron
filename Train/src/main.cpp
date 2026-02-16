/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:16:44 by mbatty            #+#    #+#             */
/*   Updated: 2026/02/16 19:34:01 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Layer.hpp"
#include <cmath>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

double	sigmoid(double z)
{
	return (1.0 / (1.0 + std::exp(-z)));
}

// Multi Layer Perceptron
class	Perceptron
{
	public:
		Perceptron(const std::string &path)
		{
			_read_csv(path);
		}
		~Perceptron() {}
	private:
		void	_read_csv(const std::string &path)
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
				for (char &c : line)
					if (c == ',')
						c = ' ';

				std::stringstream	ss(line);

				int		id;
				char	sign;

				ss >> id;
				ss >> sign;
				for (uint32_t i = 0; i < 30; i++)
				{
					double	v;

					ss >> v;
					std::cout << v << std::endl;
				}
			}

		}
};

int	main(void)
{
	Perceptron	p("data.csv");
	return (0);
}
