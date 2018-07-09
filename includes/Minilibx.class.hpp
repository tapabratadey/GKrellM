/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minilibx.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <bpierce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 21:10:16 by bpierce           #+#    #+#             */
/*   Updated: 2018/07/08 22:41:02 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBX_HPP
# define MINILIBX_HPP

# include <iostream>
# include <stdexcept>
# include <map>
# include "IMonitorModule.interface.hpp"
# include "IMonitorDisplay.interface.hpp"
# include "Graph.class.hpp"
# include "MlxImage.class.hpp"

#ifdef __cplusplus
extern "C"
{
#endif

#include "mlx.h"

#ifdef __cplusplus
}
#endif

# define MINILIBX_WIN_WIDTH 2000
# define MINILIBX_WIN_HEIGHT 800
enum
{
	C_RED = 14830891,
	C_GREEN = 3118633,
	C_BLUE = 6977013,
	C_ORANGE = 14846501
};

class Minilibx : public IMonitorDisplay
{

	public:
		// Constructors & Destructors
		Minilibx(void);
		Minilibx(Minilibx const & m);
		virtual ~Minilibx(void);
		Minilibx & operator=(Minilibx const & m);

		// Getters & Setters
		Minilibx const						*getThis(void) const;
		void								*getMlx(void) const;
		void								*getWin(void) const;
		std::map<std::string, Graph *>		getGraphs(void) const;
		BaseBase							*getBaseModule(void) const;

		void								setMlx(void	*mlx);
		void								setWin(void *win);

		// Member Function
		void			screenInit(void);
		void			screenDraw(void);
		void			screenRefresh(void);
		void			mlxLoop(void);

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

		std::map<std::string, Graph *>	_graphs;

};

std::ostream &	operator<<(std::ostream & o, Minilibx const & m);

int				forever_loop(Minilibx *m);
int				exit_window(void);
int				key_press(int keycode, Minilibx *m);

# endif
