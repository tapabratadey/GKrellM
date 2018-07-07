/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iminilibx.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 21:10:16 by bpierce           #+#    #+#             */
/*   Updated: 2018/07/06 21:10:19 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBX_HPP
# define MINILIBX_HPP

# include <iostream>
# include <stdexcept>
// # include "../includes/minilibx/mlx.h" // ALL OF THIS IS terrible - change to include just the main header file later
// # include "mlx.h" // ALL OF THIS IS terrible - change to include just the main header file later

# define MINILIBX_WIN_WIDTH 1600
# define MINILIBX_WIN_HEIGHT 1600

typedef struct			s_image
{
	void				*img;
	int					*pix;
	int					bpp;
	int					endian;
	int					w;
	int					h;
	int					x;
	int					y;
}						t_image;

class Minilibx : public I
{

	public:
		// Constructors & Destructors
		Minilibx(void);
		Minilibx(Minilibx const & m);
		virtual ~Minilibx(void);
		Minilibx & operator=(Minilibx const & m);

		// Getters & Setters
		Minilibx const	*getThis(void) const;
		void			*getMlx(void) const;
		void			*getWin(void) const;

		void			setMlx(void	*mlx);
		void			setWin(void *win);

		// Member Function
		void			screenInit(void);
		void			screenDraw(void);
		void			screenRefresh(void);
		void			displayData(IMonitorModule & im);

	protected:
		class MinilibxException : public std::exception
		{
			public:
				MinilibxException(void);
				MinilibxException(std::string what);
				MinilibxException(MinilibxException const & m);
				~MinilibxException(void) throw();
				MinilibxException & operator=(MinilibxException const & m);
				virtual const char *what(void) const throw();
			private:
				std::string	const	_what;
		};

	private:
		void						*_mlx;
		void						*_win;

		std::map<IMonitorModule *, t_image *>	_modules;
		t_image						*_newImage(int width, int height);

};

std::ostream &	operator<<(std::ostream & o, Minilibx const & m);

# endif
