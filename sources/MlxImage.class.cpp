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

#include "MlxImage.class.hpp"

MlxImage::MlxImage(void)
{
	throw std::string("Please instantiate MlxImage with an argument");
	return ;
}

MlxImage::MlxImage(void *mlx, int width, int height) : _mlx(mlx), _width(width), _height(height), _x(0), _y(0)
{
	_img = mlx_new_image(_mlx, _width, _height);
	_pix = reinterpret_cast<int *>(mlx_get_data_addr(_img, &_bpp, &_width, &_endian));
	_width /= 4;
	return ;
}


MlxImage::MlxImage(MlxImage const & g)
{
	*this = g;
	return ;
}

MlxImage & MlxImage::operator=(MlxImage const & g)
{
	if (this != &g)
	{
		this->_mlx = g.getMlx();
		this->_img = g.getImg();
		this->_pix = g.getPix();
		this->_bpp = g.getBpp();
		this->_endian = g.getEndian();
		this->_width = g.getWidth();
		this->_height = g.getHeight();
		this->_x = g.getX();
		this->_y = g.getY();
	}
	return *this;
}

MlxImage::~MlxImage(void)
{
	mlx_destroy_image(_mlx, _img);
	return ;
}


MlxImage const	*MlxImage::getThis(void) const
{ return this; }

void			*MlxImage::getMlx(void) const
{ return _mlx; }

void			*MlxImage::getImg(void) const
{ return _img; }

int				*MlxImage::getPix(void) const
{ return _pix; }

int				MlxImage::getBpp(void) const
{ return _bpp; }

int				MlxImage::getEndian(void) const
{ return _endian; }

int				MlxImage::getWidth(void) const
{ return _width; }

int				MlxImage::getHeight(void) const
{ return _height; }

int				MlxImage::getX(void) const
{ return _x; }

int				MlxImage::getY(void) const
{ return _y; }

void			MlxImage::setX(int x)
{ _x = x; }

void			MlxImage::setY(int y)
{ _y = y; }



void			MlxImage::backgroundFill(int color)
{
	int		x;
	int		y;

	y = -1;
	while (++y < _height)
	{
		x = -1;
		while (++x < _width)
			_pix[(y * _width) + x] = color;
	}
}

void			MlxImage::pixelFill(int x, int y, int color)
{
	_pix[(y * _width) + x] = color;
}

void			MlxImage::drawToScreen(void *win) const
{
	mlx_put_image_to_window(_mlx, win, _img, _x, _y);
}


std::ostream &	operator<<(std::ostream & o, MlxImage const & g)
{
	o << "Width: " << g.getWidth() << ", Height: " << g.getHeight() << std::endl;
	o << "X: " << g.getX() << ", Y: " << g.getY() << std::endl;
	return o;
}
