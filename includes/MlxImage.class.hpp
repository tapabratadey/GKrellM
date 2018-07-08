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

#ifndef MLXIMAGE_CLASS_HPP
# define MLXIMAGE_CLASS_HPP

#include <iostream>
#ifdef __cplusplus
extern "C"
{
#endif

#include "mlx.h"

#ifdef __cplusplus
}
#endif

class MlxImage
{
	protected:
		void				*_mlx;

		void				*_img;
		int					*_pix;
		int					_bpp;
		int					_endian;
		int					_width;
		int					_height;
		int					_x;
		int					_y;

	public:
		MlxImage(void);
		MlxImage(void *mlx, int width, int height);
		MlxImage(MlxImage const & g);
		virtual ~MlxImage(void);
		MlxImage & operator=(MlxImage const & g);


		MlxImage const			*getThis(void) const;
		void					*getMlx(void) const;
		void					*getImg(void) const;
		int						*getPix(void) const;
		int						getBpp(void) const;
		int						getEndian(void) const;
		int						getWidth(void) const;
		int						getHeight(void) const;
		int						getX(void) const;
		int						getY(void) const;

		void					setX(int x);
		void					setY(int y);

		void					backgroundFill(int color);
		void					pixelFill(int x, int y, int color);
		void					drawToScreen(void *win) const;

};

std::ostream &	operator<<(std::ostream & o, MlxImage const & g);

#endif
