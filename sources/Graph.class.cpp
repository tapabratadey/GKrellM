/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:59:44 by bpierce           #+#    #+#             */
/*   Updated: 2018/07/06 12:59:51 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Graph.class.hpp"

Graph::Graph(void) : _maxHistorySize(MAX_GRAPH_HISTORY_SIZE), _min(0), _max(0)
{
	_im = NULL;
	_mlx = NULL;
	return ;
}

Graph::Graph(void *mlx) : _maxHistorySize(MAX_GRAPH_HISTORY_SIZE), _min(0), _max(0), _mlx(mlx)
{
	_im = new MlxImage(_mlx, MAX_GRAPH_HISTORY_SIZE, MAX_GRAPH_HISTORY_SIZE);
	return ;
}


Graph::Graph(Graph const & g) : _maxHistorySize(g.getMaxHistorySize())
{
	*this = g;
	return ;
}

Graph & Graph::operator=(Graph const & g)
{
	if (this != &g)
	{
		this->_history = g.getHistory();
		this->_min = g.getMin();
		this->_max = g.getMax();
		delete _im;
		this->_im = g.getIm();
		this->_mlx = g.getMlx();
	}
	return *this;
}

Graph::~Graph(void)
{
	delete _im;
	return ;
}


Graph const				*Graph::getThis(void) const
{ return this; }

std::deque<int>	const & Graph::getHistory(void) const
{ return _history; }

unsigned long			Graph::getMaxHistorySize(void) const
{ return _maxHistorySize; }

int						Graph::getMin(void) const
{ return _min; }

int						Graph::getMax(void) const
{ return _max; }

MlxImage				*Graph::getIm(void) const
{ return _im; }

void					*Graph::getMlx(void) const
{ return _mlx; }



void					Graph::addToHistory(int n)
{
	if (_history.size() == _maxHistorySize)
		_history.pop_front();
	_history.push_back(n);
	if (!_min && !_max)
	{
		_min = n;
		_max = n;
	}
	_min = n < _min ? n : _min;
	_max = n > _max ? n : _max;
}

void					Graph::fillDataAll(void)
{

	std::deque<int>::iterator	i;
	int							val;
	// union	FloatOrUInt
 //    {
 //        	float	asFloat;
 //        	int		asInt;
 //    } 		fu;

	i = _history.begin();
	if (i == _history.end())
		return ;
	for (int x = _im->getWidth() ; x > 0 ; x--) {
		// fu.asInt = *i;
		val = remap_value(*i, _min, _max, 1, 100);
		std::cout << val << std::endl;
		for (int y = _im->getHeight() ; y > 0 ; y--) {
			_im->pixelFill(x, y, y < val ? 2132127 : 45824);
		}
		if (++i == _history.end())
			break ;
	}
}

std::ostream &	operator<<(std::ostream & o, Graph const & g)
{
	o << g.getThis();
	return o;
}

int		remap_value(int value, int low1, int high1, int low2, int high2)
{
	// int		i;
	// union	FloatOrUInt
 //    {
 //        	float	asFloat;
 //        	int		asInt;
 //    } 		fu;

    // fu.asFloat = (low2 + (value - low1) * (high2 - low2) / (high1 - low1)) + 0.5;
	return (low2 + (value - low1) * (high2 - low2) / (high1 - low1));
}
