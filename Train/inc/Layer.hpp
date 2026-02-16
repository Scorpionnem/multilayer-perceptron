/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Layer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:16:35 by mbatty            #+#    #+#             */
/*   Updated: 2026/02/16 19:16:10 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Neuron.hpp"
#include <memory>
#include <cstdint>

class	Layer
{
	public:
		Layer(uint32_t n)
		{
			for (uint32_t i = 0; i < n; i++)
				_neurons.push_back(Neuron());
		}
		~Layer() {}
	private:
		std::vector<Neuron>	_neurons;
};
