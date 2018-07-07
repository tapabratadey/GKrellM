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

#ifdef __cplusplus
extern "C"
{
#endif
#include "mlx.h"
#ifdef __cplusplus
}
#endif

// Constructors & Destructors

Minilibx::Minilibx(void)
{
	// Initializing the MLX Window
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



// Member functions

// int			_exit_mlx_window(Minilibx *m)
// {
// 	if (m->getWin())
// 		mlx_destroy_window(m->getMlx(), m->getWin());
// 	m->setWin(NULL);
// 	return 0;
// }



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
// int			_exit_mlx_window(t_destroy_collection *c)
// {
// 	t_destroy_collection a;

// 	a.mlx = c->mlx;
// 	a.win = c->win;
// 	if (a.mlx)
// 		mlx_destroy_window(a.mlx, a.win);
// 	return 0;
// }