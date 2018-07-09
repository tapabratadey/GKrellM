/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minilibx.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <bpierce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:59:44 by bpierce           #+#    #+#             */
/*   Updated: 2018/07/08 22:27:39 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minilibx.class.hpp" // terrible - change later to main header file

// Constructors & Destructors

Minilibx::Minilibx(void) : IMonitorDisplay()
{
	// Initializing the MLX Window
	screenInit();
	// Initializing the keyhooks
	mlx_do_key_autorepeatoff(_mlx);
	mlx_loop_hook(_mlx, reinterpret_cast<int (*)()>(forever_loop), this);
	// mlx_hook(_mlx, 17, 0, reinterpret_cast<int (*)()>(exit_window), this);
	mlx_key_hook(_win, reinterpret_cast<int (*)()>(key_press), this);
	// std::cout << "Constructor Called" << std::endl;
	return ;
}

Minilibx::Minilibx(Minilibx const & m)
{
	*this = m;
	return ;
}

Minilibx & Minilibx::operator=(Minilibx const & m)
{
	if (this != &m)
	{
		this->setMlx(m.getMlx());
		if (_win)
			mlx_destroy_window(_mlx, _win);
		this->setWin(m.getWin());
	}
	return *this;
}

Minilibx::~Minilibx(void)
{
	std::map<std::string, Graph *>::iterator	graphDestroyer;
	Graph										*graph;

	if (_win)
		mlx_destroy_window(_mlx, _win);
	for (graphDestroyer = _graphs.begin() ; graphDestroyer != _graphs.end() ; graphDestroyer++) {
		graph = graphDestroyer->second;
		_graphs.erase(graphDestroyer);
		delete graph;
	}
	this->setMlx(NULL);
	this->setWin(NULL);
	return ;
}



// Getters & Setters

Minilibx const	*Minilibx::getThis(void) const
{ return this; }

void			*Minilibx::getMlx(void) const
{ return _mlx; }

void			*Minilibx::getWin(void) const
{ return _win; }

std::map<std::string, Graph *>	Minilibx::getGraphs(void) const
{ return _graphs; }

BaseBase						*Minilibx::getBaseModule(void) const
{
	return baseModule;
}

void			Minilibx::setMlx(void *mlx)
{ _mlx = mlx;}

void			Minilibx::setWin(void *win)
{ _win = win;}



// Public Member Functions

void			Minilibx::screenInit(void)
{
	std::map<std::string, std::map<std::string, std::string> >	myMap;
	std::string													name = "Fantastic Mr. Monitor";

	_mlx = mlx_init();
	if (!_mlx)
		throw Minilibx::MinilibxException("Failed to init MLX");
	_win = mlx_new_window(getMlx(),
		MINILIBX_WIN_WIDTH,
		MINILIBX_WIN_HEIGHT,
		const_cast<char *>(name.c_str()));
	if (!_win)
		throw Minilibx::MinilibxException("Failed to create mlx window");
	this->baseModule = new BaseBase();
	myMap = this->baseModule->getData();
	for (std::map<std::string, std::map<std::string, std::string> >::iterator moduleIterator = myMap.begin() ; moduleIterator != myMap.end() ; moduleIterator++) {
		_graphs[moduleIterator->first] = new Graph(_mlx);
		_graphs[moduleIterator->first]->backgroundFill(0); // a green color
		_graphs[moduleIterator->first]->setX(((_graphs.size() / 3) * (MINILIBX_WIN_WIDTH / 3)) + 20);
		_graphs[moduleIterator->first]->setY(((_graphs.size() % 3) * (MINILIBX_WIN_HEIGHT / 3)) + 25);
	}
}

void			Minilibx::screenDraw(void)
{
	std::map<std::string, std::map<std::string, std::string> >	dataMap = this->baseModule->getData();
	Graph														*graph;
	static int													color_array[4] = {C_RED, C_GREEN, C_BLUE, C_ORANGE};
	int															color_iterator = 0;
	int															startY;
	std::string													printString;

	mlx_clear_window(_mlx, _win);
	for (std::map<std::string, std::map<std::string, std::string> >::iterator dataIterator = dataMap.begin() ; dataIterator != dataMap.end() ; dataIterator++) {
		graph = _graphs[dataIterator->first];
		startY = graph->getY();
		mlx_string_put(_mlx, _win, graph->getX(), startY, color_array[color_iterator % 4], const_cast<char *>(dataIterator->first.c_str()));
		for (std::map<std::string, std::string>::iterator moduleItemIterator = dataIterator->second.begin() ; moduleItemIterator != dataIterator->second.end() ; moduleItemIterator++) {
			startY += 13;
			printString = moduleItemIterator->first + " | " + moduleItemIterator->second;
			mlx_string_put(_mlx, _win, graph->getX(), startY, color_array[color_iterator % 4], const_cast<char *>(printString.c_str()));
			// If a graph needs to be drawn do it here
			if (moduleItemIterator->first == "cpuUsage")
			{
				graph->addToHistory(std::stof(moduleItemIterator->second));
				graph->fillDataAll();
				mlx_put_image_to_window(_mlx, _win, graph->getImg(), graph->getX(), startY + 30);
				startY += 50 + MAX_GRAPH_HISTORY_SIZE;
			}
		}
		color_iterator += 1;
	}
}

void			Minilibx::screenRefresh(void)
{
	mlx_do_sync(_mlx);
	return ;
}

// Private Member Functions


// EXCEPTION

Minilibx::MinilibxException::MinilibxException(void) : _what("Minilibx exception thrown!!!")
{ return ; }

Minilibx::MinilibxException::MinilibxException(std::string what) : _what(what)
{ return ; }

Minilibx::MinilibxException::MinilibxException(MinilibxException const & m)
{ *this = m; return ; }

Minilibx::MinilibxException::~MinilibxException(void) throw()
{ return ; }

Minilibx::MinilibxException & Minilibx::MinilibxException::operator=(MinilibxException const & m)
{ static_cast<void>(m); return *this; }

const char *Minilibx::MinilibxException::what(void) const throw()
{ return _what.c_str(); }



// Operator Overloads
std::ostream &	operator<<(std::ostream & o, Minilibx const & m)
{
	o << m.getThis();
	return o;
}

void			Minilibx::mlxLoop(void)
{
	mlx_loop(this->_mlx);
}


int				forever_loop(Minilibx *m)
{
	m->screenDraw();
	m->screenRefresh();
	return 0;
}

int				exit_window(void)
{
	exit(0);
	return 0;
}

int				key_press(int keycode, Minilibx *m)
{
	static_cast<void>(m);
	if (keycode == 53)
		exit(0);
	return 0;
}
