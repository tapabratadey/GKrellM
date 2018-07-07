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

#include "../includes/Minilibx.class.hpp" // terrible - change later to main header file
#include "Minilibx.class.hpp" // terrible - change later to main header file
#include <vector>
#include <map>

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
	mlx_destroy_window(_mlx, _win);
	return ;
}



// Getters & Setters

Minilibx const	*Minilibx::getThis(void) const
{ return this;}

void			*Minilibx::getMlx(void) const
{ return _mlx;}

void			*Minilibx::getWin(void) const
{ return _win;}

void			Minilibx::setMlx(void *mlx)
{ _mlx = mlx;}

void			Minilibx::setWin(void *win)
{ _win = win;}



// Public Member Functions

void			Minilibx::screenDraw(void)
{
	return ;
}


void			Minilibx::screenDraw(IMonitorModule & im)
{
	std::map<IMonitorModule *, t_image *>::iterator		module;
	t_image												*newIm;

	module = _modules.find(&im);
	if (module == _modules.end())
	{
		// create new image to display
		newIm = _newImage(MINILIBX_WIN_WIDTH / 5, MINILIBX_WIN_HEIGHT / 5);
		newIm->x = ((_modules.size() / 5) * (MINILIBX_WIN_WIDTH / 5)) + 20;
		newIm->y = ((_modules.size() % 5) * (MINILIBX_WIN_HEIGHT / 5)) + 20;
		_modules.insert(std::pair<IMonitorModule *, t_image *>(&im, newIm));
		module = _modules.find(&im);
	}
	mlx_put_image_to_window(getMlx(), getWin(), module->second->img, 0, 0);
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
}

void			Minilibx::screenRefresh(void)
{
	mlx_do_sync(getMlx());
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

t_image			*Minilibx::_newImage(int width, int height)
{
	t_image		*image = new t_image;

	image->img = mlx_new_image(getMlx(), width, height);
	image->pix = reinterpret_cast<int *>(mlx_get_data_addr(image->img, &image->bpp, &image->w, &image->endian));
	image->w /= 4;
	image->h = height;
	return image;
}
