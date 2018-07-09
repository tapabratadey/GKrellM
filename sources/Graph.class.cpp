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

Graph::Graph(void) :
MlxImage(), _maxHistorySize(MAX_GRAPH_HISTORY_SIZE), _min(0), _max(0)
{
	return ;
}

Graph::Graph(void *mlx) :
MlxImage(mlx, MAX_GRAPH_HISTORY_SIZE, MAX_GRAPH_HISTORY_SIZE),
_maxHistorySize(MAX_GRAPH_HISTORY_SIZE), _min(0), _max(0)
{
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
	}
	return *this;
}

Graph::~Graph(void)
{
	return ;
}


std::deque<float>	const & Graph::getHistory(void) const
{ return _history; }

unsigned long			Graph::getMaxHistorySize(void) const
{ return _maxHistorySize; }

float						Graph::getMin(void) const
{ return _min; }

float						Graph::getMax(void) const
{ return _max; }



void					Graph::addToHistory(float n)
{
	if (_history.size() == _maxHistorySize)
		_history.pop_back();
	_history.push_front(n);
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

	std::deque<float>::iterator	i;
	float						val;

	i = _history.begin();
	if (i == _history.end())
		return ;
	for (int x = _width - 1 ; x >= 0 ; x--) {
		val = remap_value(*i, _min, _max, 1, 100);
		for (int y = _height - 1 ; y >= 0 ; y--) {
			this->pixelFill(x, y, y >= val ?  0 : 14864159);
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

float		remap_value(float value, float low1, float high1, float low2, float high2)
{
	return (low2 + (value - low1) * (high2 - low2) / (high1 - low1));
}
