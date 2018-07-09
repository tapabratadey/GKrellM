/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurses.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <bpierce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:59:44 by bpierce           #+#    #+#             */
/*   Updated: 2018/07/08 22:10:26 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ncurses.class.hpp"

// Constructors & Destructors

Ncurses::Ncurses(void) : IMonitorDisplay()
{
	// Initializing the Ncurses Window
	screenInit();
	return ;
}

Ncurses::Ncurses(Ncurses const & m)
{
	*this = m;
	return ;
}

Ncurses & Ncurses::operator=(Ncurses const & m)
{
	if (this != &m)
	{
		delete this->baseModule;
		this->baseModule = m.getBaseModule();
	}
	return *this;
}

Ncurses::~Ncurses(void)
{
	std::cout << "destructor" << std::endl;
	std::map<std::string, WINDOW *>::iterator	windowDestroyer;
	WINDOW										*window;
	for (windowDestroyer = _windows.begin() ; windowDestroyer != _windows.end() ; windowDestroyer++) {
		window = windowDestroyer->second;
		_windows.erase(windowDestroyer);
		delwin(window);
	}
	delete this->baseModule;
	endwin();
	return ;
}



// Getters & Setters

Ncurses const					*Ncurses::getThis(void) const
{ return this;}

std::map<std::string, WINDOW *>	Ncurses::getWindows(void) const
{ return _windows;}

BaseBase						*Ncurses::getBaseModule(void) const
{
	return baseModule;
}


// Public Member Functions

void			Ncurses::screenInit(void)
{
	std::map<std::string, std::map<std::string, std::string> >	myMap;
	int															colorEnum = 0;

	initscr();	
	halfdelay(1);
	noecho();
	// cbreak();
	curs_set(0);
	start_color();
	init_color(COLOR_BLUE, 215, 800, 1000);
	init_color(COLOR_WHITE, 200, 200, 200);
	init_color(COLOR_YELLOW, 855, 530, 36);
	init_pair(C1, COLOR_GREEN, COLOR_BLACK);
	init_pair(C2, COLOR_BLUE, COLOR_BLACK);
	init_pair(C3, COLOR_RED, COLOR_BLACK);
	init_pair(C4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(C5, COLOR_BLACK, COLOR_GREEN);
	init_pair(C6, COLOR_BLACK, COLOR_BLUE);
	init_pair(C7, COLOR_BLACK, COLOR_RED);
	init_pair(C8, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(DF, COLOR_WHITE, COLOR_BLACK);
	init_pair(DF_BAR, COLOR_WHITE, COLOR_WHITE);
	init_pair(ORANGE_STUFF, COLOR_YELLOW, COLOR_BLACK);
	init_pair(ORANGE_BAR, COLOR_YELLOW, COLOR_YELLOW);
	this->baseModule = new BaseBase();

	int counter = 0;
	// Initializing the windows for each module item
	myMap = this->baseModule->getData();
	for (std::map<std::string, std::map<std::string, std::string> >::iterator moduleIterator = myMap.begin() ; moduleIterator != myMap.end() ; moduleIterator++) {
		_windows[moduleIterator->first] = newwin(10, 110, ((counter++ * 10)) + 1, 0 );
		#if 0
		_windows[moduleIterator->first] = newwin(6, 70,
				((_windows.size() % 5) * (NCURSES_WIN_HEIGHT / 5)) + 5,
				((_windows.size() / 5) * (NCURSES_WIN_WIDTH / 5)) + 20);
		#endif
		wattron(_windows[moduleIterator->first], COLOR_PAIR((colorEnum++ % 4) + 1));
		box(_windows[moduleIterator->first], 0, 0);
	}
}

void			Ncurses::screenDraw(void)
{
	std::map<std::string, std::map<std::string, std::string> >	dataMap = this->baseModule->getData();
	WINDOW														*window;
	int															colorEnum = 0;
	int															x;

	for (std::map<std::string, std::map<std::string, std::string> >::iterator dataIterator = dataMap.begin() ; dataIterator != dataMap.end() ; dataIterator++) {
		window	= _windows[dataIterator->first];
		x		= 1;

		wattron(window, COLOR_PAIR((colorEnum % 4) + 5));
		mvwaddstr(window, x, 1, dataIterator->first.c_str());
		wattron(window, COLOR_PAIR((colorEnum % 4) + 1));
		for (std::map<std::string, std::string>::iterator moduleItemIterator = dataIterator->second.begin() ; moduleItemIterator != dataIterator->second.end() ; moduleItemIterator++) {
			mvwprintw(window, ++x, 1, "%s | %s", moduleItemIterator->first.c_str(), moduleItemIterator->second.c_str());
		}
		wattroff(window, COLOR_PAIR((colorEnum++ % 4) + 1));
	}
}

void			Ncurses::screenRefresh(void)
{
	std::map<std::string, WINDOW *>	windows = this->getWindows();

	// int get = getch();
	// if (get == 27)
	// 	delete this;
	for (std::map<std::string, WINDOW *>::iterator winIter = windows.begin() ; winIter != windows.end() ; winIter++) {
		wrefresh(winIter->second);
	}
	return ;
}

// Private Member Functions


// EXCEPTION

Ncurses::NcursesException::NcursesException(void) : _what("Ncurses exception thrown!!!")
{ return ; }

Ncurses::NcursesException::NcursesException(std::string what) : _what(what)
{ return ; }

Ncurses::NcursesException::NcursesException(NcursesException const & m)
{ *this = m; return ; }

Ncurses::NcursesException::~NcursesException(void) throw()
{ return ; }

Ncurses::NcursesException & Ncurses::NcursesException::operator=(NcursesException const & m)
{ static_cast<void>(m); return *this; }

const char *Ncurses::NcursesException::what(void) const throw()
{ return _what.c_str(); }

void Ncurses::starter() {
	while (1) {
		this->screenDraw();
		this->screenRefresh();
	}
}

// Operator Overloads
std::ostream &	operator<<(std::ostream & o, Ncurses const & m)
{
	o << m.getThis();
	return o;
}
