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

#ifndef NCURSES_HPP
# define NCURSES_HPP

# include <iostream>
# include <stdexcept>
# include <vector>
# include <algorithm>
# include <ncurses.h>


# include "IMonitorModule.interface.hpp"
# include "IMonitorDisplay.interface.hpp"
# define NCURSES_WIN_HEIGHT 70
# define NCURSES_WIN_WIDTH 275

enum
{
	C1 = 1,
	C2,
	C3,
	C4,
	C5,
	C6,
	C7,
	C8,
	DF,
	DF_BAR,
	ORANGE_STUFF,
	ORANGE_BAR
};

class Ncurses : public IMonitorDisplay
{

	public:
		// Constructors & Destructors
		Ncurses(void);
		Ncurses(Ncurses const & m);
		virtual ~Ncurses(void);
		Ncurses & operator=(Ncurses const & m);

		// Getters & Setters
		Ncurses const					*getThis(void) const;
		std::map<std::string, WINDOW *>	getWindows(void) const;
		BaseBase						*getBaseModule(void) const;

		// Member Function
		void			screenInit(void);
		void			screenDraw(void);
		void			screenDraw(IMonitorModule & im);
		void			screenRefresh(void);
		void			displayData(IMonitorModule & im);
		void 			starter();

	protected:
		class NcursesException : public std::exception
		{
			public:
				NcursesException(void);
				NcursesException(std::string what);
				NcursesException(NcursesException const & m);
				~NcursesException(void) throw();
				NcursesException & operator=(NcursesException const & m);
				virtual const char *what(void) const throw();
			private:
				std::string	const	_what;
		};

	private:
		std::map<std::string, WINDOW *>	_windows;

};

std::ostream &	operator<<(std::ostream & o, Ncurses const & n);

# endif
