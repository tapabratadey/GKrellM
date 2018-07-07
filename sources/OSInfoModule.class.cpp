/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfoModule.class.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 22:01:23 by tadey             #+#    #+#             */
/*   Updated: 2018/07/06 22:01:25 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "OSInfoModule.class.hpp"
#include <unistd.h>
#include <iostream>
#include <sys/sysctl.h>

//default constructor
OSInfoModule::OSInfoModule() 
{
    size_t bufflen = BUFF_LEN;
    sysctlbyname("machdep.cpu.brand_string", &buffer, &bufflen, NULL, 0);
}

//destructor
OSInfoModule::~OSInfoModule() { }

//Copy constructor
OSInfoModule::OSInfoModule(OSInfoModule const &copy)
{ *this = copy; }

//assignating operator
OSInfoModule &OSInfoModule::operator=(OSInfoModule const &)
{ return (*this); }

//getters
char *OSInfoModule::getInfo()
{ return buffer; }