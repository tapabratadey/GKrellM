/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 02:37:54 by tadey             #+#    #+#             */
/*   Updated: 2018/07/07 02:37:56 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Date.class.hpp"
#include <unistd.h>
#include <iostream>
#include <ctime>

//default constructor
Date::Date() 
{
    //current date/time based on current system
    time_t timeNow = time(0);
    //convert time to str
    dateInfo = ctime(&timeNow);
}

//destructor
Date::~Date() { }

//Copy constructor
Date::Date(Date const &copy)
{ *this = copy; }

//assignating operator
Date &Date::operator=(Date const &)
{ return (*this); }

//getters
char *Date::getDate()
{ return dateInfo; }
