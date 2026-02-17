/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:16:44 by mbatty            #+#    #+#             */
/*   Updated: 2026/02/17 18:23:00 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Layer.hpp"
#include <cmath>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_set>

#include "CSV.hpp"

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
			_csv.parse(path, {0, 1});
			_csv.normalize_data();
			_csv.print();
		}
		~Perceptron() {}
	private:
		CSV	_csv;
};

int	main(void)
{
	Perceptron	p("data.csv");
	return (0);
}
