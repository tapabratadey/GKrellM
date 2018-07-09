/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graph.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 16:12:50 by bpierce           #+#    #+#             */
/*   Updated: 2018/07/07 16:13:08 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_CLASS_HPP
# define GRAPH_CLASS_HPP

# include <iostream>
# include <deque>

# include "MlxImage.class.hpp"
# ifdef __cplusplus
extern "C"
{
# endif
# include "mlx.h"
# ifdef __cplusplus
}
# endif

# define MAX_GRAPH_HISTORY_SIZE 100

class Graph : public MlxImage
{
	private:
		std::deque<float>		_history;
		unsigned long const	_maxHistorySize;
		float					_min;
		float					_max;

	public:
		Graph(void);
		Graph(void *mlx);
		Graph(Graph const & g);
		virtual ~Graph(void);
		Graph & operator=(Graph const & g);


		std::deque<float>	const & getHistory(void) const;
		unsigned long			getMaxHistorySize(void) const;
		float					getMin(void) const;
		float					getMax(void) const;

		void					addToHistory(float n);
		void					fillDataAll(void);

};

std::ostream &	operator<<(std::ostream & o, Graph const & g);

float		remap_value(float value, float low1, float high1, float low2, float high2);

#endif
