/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hostname.Class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 19:24:55 by tadey             #+#    #+#             */
/*   Updated: 2018/07/06 19:24:56 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Hostname.class.hpp"
#include <unistd.h>
#include <iostream>

//default constructor
Hostname::Hostname() 
{
    gethostname(hostname, LOGIN_LENGTH);
    getlogin_r(username, USERNAME_LENGTH);
}

//destructor
Hostname::~Hostname() { }

//Copy constructor
Hostname::Hostname(Hostname const &copy)
{ *this = copy; }

//assignating operator
Hostname &Hostname::operator=(Hostname const &)
{ return (*this); }

//getters
char *Hostname::getUserName()
{ return username; }

char *Hostname::getHostName()
{ return hostname; }
