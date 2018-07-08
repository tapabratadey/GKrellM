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

#include "Minilibx.class.hpp" // terrible - change later to main header file

#ifdef __cplusplus
extern "C"
{
#endif

#include "mlx.h"

#ifdef __cplusplus
}
#endif

// Constructors & Destructors

Minilibx::Minilibx(void) : IMonitorDisplay()
{
	// Initializing the MLX Window
	screenInit();
	// Initializing the keyhooks
	mlx_do_key_autorepeatoff(_mlx);
	// mlx_loop_hook(_mlx, reinterpret_cast<int (*)()>(forever_loop), this);
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
		this->setWin(m.getWin());
	}
	return *this;
}

Minilibx::~Minilibx(void)
{
	std::map<IMonitorModule *, MlxImage *>::iterator	module;

	for (module = _modules.begin() ; module != _modules.end() ; module++) {
		delete module->second;
	}
	if (_win)
		mlx_destroy_window(_mlx, _win);
	this->setMlx(NULL);
	this->setWin(NULL);
	return ;
}



// Getters & Setters

Minilibx const	*Minilibx::getThis(void) const
{ return this;}

void			*Minilibx::getMlx(void) const
{ return _mlx;}

void			*Minilibx::getWin(void) const
{ return _win;}

std::map<IMonitorModule *, MlxImage *>	Minilibx::getModules(void) const
{ return _modules;}

void			Minilibx::setMlx(void *mlx)
{ _mlx = mlx;}

void			Minilibx::setWin(void *win)
{ _win = win;}



// Public Member Functions

void			Minilibx::screenDraw(void)
{
	for (std::map<IMonitorModule *, MlxImage *>::iterator module = _modules.begin() ; module != _modules.end() ; module++) {
		this->_drawToScreen(*module->second);
	}
}


void			Minilibx::screenDraw(IMonitorModule & im)
{
	std::map<IMonitorModule *, MlxImage *>::iterator	module;
	MlxImage											*newIm;

	module = _modules.find(&im);
	if (module == _modules.end())
	{
		// create new image to display
		newIm = new MlxImage(_mlx, MINILIBX_WIN_WIDTH / 5, MINILIBX_WIN_HEIGHT / 5);
		newIm->backgroundFill(45824); // a green color
		newIm->setX(((_modules.size() / 5) * (MINILIBX_WIN_WIDTH / 5)) + 20);
		newIm->setY(((_modules.size() % 5) * (MINILIBX_WIN_HEIGHT / 5)) + 20);
		std::cout << newIm->getX() << "  " << newIm->getY() << std::endl;
		_modules.insert(std::pair<IMonitorModule *, MlxImage *>(&im, newIm));
		module = _modules.find(&im);
	}
	this->_drawToScreen(*module->second);
}

void			Minilibx::_drawToScreen(MlxImage const & im) const
{
	mlx_put_image_to_window(_mlx, _win, im.getImg(), im.getX(), im.getY());
}


void			Minilibx::screenInit(void)
{
	std::string	name = "Fantastic Mr. Monitor";

	_mlx = mlx_init();
	if (!_mlx)
		throw Minilibx::MinilibxException("Failed to init MLX");
	_win = mlx_new_window(getMlx(),
		MINILIBX_WIN_WIDTH,
		MINILIBX_WIN_HEIGHT,
		const_cast<char *>(name.c_str()));
	if (!_win)
		throw Minilibx::MinilibxException("Failed to create mlx window");
	this->screenRefresh();
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



// Other

// int				forever_loop(Minilibx *m)
// {
// 	m->screenDraw();
// 	// m->screenRefresh();
// 	return 0;
// }

int				exit_window(void)
{
	// m->~Minilibx();
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
