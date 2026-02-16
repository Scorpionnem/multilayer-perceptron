/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:13:14 by mbatty            #+#    #+#             */
/*   Updated: 2026/02/16 15:40:37 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <fstream>
#include <ctime>

#include "Options.hpp"

void	print_help()
{
	std::cout << "usage: ./Separate [-h, -i, -t, -c, -p, -s]" << std::endl << std::endl;
	std::cout << "options:" << std::endl;
	std::cout << "-h --help\t\tshow help message and exit" << std::endl;
	std::cout << "-i --input\t\tpath to input file" << std::endl;
	std::cout << "-t --out_train\t\tpath to train out file" << std::endl;
	std::cout << "-c --out_check\t\tpath to check out file" << std::endl;
	std::cout << "-p --probability\tprobability of line going in check out file" << std::endl;
	std::cout << "-s --seed\t\tseed for random" << std::endl;
}

int	main(int ac, char **av)
{
	(void)ac;

	Options	opts;

	std::string	input_file = "data.csv";
	std::string	train_output_file = "train_out.csv";
	std::string	check_output_file = "check_out.csv";
	float		check_probability = 0.2; // 20% go to check
	int			seed = 674269;
	bool		help = false;

	opts.setStringOpt("--input", "-i", input_file);
	opts.setStringOpt("--out_train", "-t", train_output_file);
	opts.setStringOpt("--out_check", "-c", check_output_file);
	opts.setFloatOpt("--probability", "-p", check_probability);
	opts.setIntOpt("--seed", "-s", seed);

	if (!opts.parse(av) || help)
		return (print_help(), !help);

	std::cout << "------Separate------" << '\n';
	std::cout << "Seed:\t" << seed << "\n\n";
	std::cout << "Treating:\t" << input_file << "\n\n";
	std::cout << "Train output:\t" << train_output_file << '\n';
	std::cout << "Check output:\t" << check_output_file << "\n\n";
	std::cout << "Check probability:\t" << check_probability << '\n';
	std::cout << "--------------------" << '\n';

	srand(seed);

	std::ifstream	input(input_file);
	std::ofstream	train_output(train_output_file);
	std::ofstream	check_output(check_output_file);
	if (!input.is_open() || !train_output.is_open() || !check_output.is_open())
		return (std::cerr << "Could not open a file" << std::endl, 1);

	int	train_lines = 0;
	int	check_lines = 0;
	int	total_lines = 0;

	std::cout << "\nTreating lines...\n\n";

	std::string	line;
	while (std::getline(input, line))
	{
		float	f = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
		if (f <= check_probability)
		{
			check_output << line << std::endl;
			check_lines++;
		}
		else
		{
			train_output << line << std::endl;
			train_lines++;
		}
		total_lines++;
	}

	std::cout << "--------------------" << '\n';
	std::cout << "Input lines:\t" << total_lines << "\n\n";
	std::cout << "Train lines:\t" << train_lines << '\n';
	std::cout << "Check lines:\t" << check_lines << "\n\n";
	std::cout << "Accuracy:\t" << static_cast<float>(check_lines) / static_cast<float>(total_lines) << "/" << check_probability << "\n";
	std::cout << "--------------------" << '\n';
}
