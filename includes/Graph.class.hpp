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

class Graph
{
	private:
		std::deque<int>		_history;
		unsigned long const	_maxHistorySize;
		int					_min;
		int					_max;
		MlxImage			*_im;
		void				*_mlx;

	public:
		Graph(void);
		Graph(void *mlx);
		Graph(Graph const & g);
		virtual ~Graph(void);
		Graph & operator=(Graph const & g);


		Graph const				*getThis(void) const;
		std::deque<int>	const & getHistory(void) const;
		unsigned long			getMaxHistorySize(void) const;
		int						getMin(void) const;
		int						getMax(void) const;
		MlxImage				*getIm(void) const;
		void					*getMlx(void) const;


		void					addToHistory(int n);
		void					fillDataAll(void);

};

std::ostream &	operator<<(std::ostream & o, Graph const & g);

int		remap_value(int value, int low1, int high1, int low2, int high2);

#endif
