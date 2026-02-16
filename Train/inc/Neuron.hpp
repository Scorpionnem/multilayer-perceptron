/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Neuron.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:16:40 by mbatty            #+#    #+#             */
/*   Updated: 2026/02/16 19:16:04 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <iostream>

class	Layer;

class	Neuron
{
	public:
		Neuron() {}
		~Neuron() {}

		void	connect(Layer *l)
		{
			_next_layer = l;
		}
	private:
		Layer	*_next_layer;
};
