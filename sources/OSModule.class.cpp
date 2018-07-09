/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSModule.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 02:31:20 by maghayev          #+#    #+#             */
/*   Updated: 2018/07/07 04:29:56 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OSModule.class.hpp"

OSModule::OSModule () {
	this->isUpdateRequired = false;
	this->initData();
}
OSModule::OSModule (OSModule const & src) {
	*this = src;
	return ;
}
OSModule::~OSModule () {}

bool	OSModule::getUpdateRequired() const {	return this->isUpdateRequired;	}

OSModule & OSModule::operator=(OSModule const & rhs) {
	if (this != &rhs) {
		this->isUpdateRequired = rhs.getUpdateRequired();
	}
	return *this;
}

void OSModule::dataRunner() {
	uname(&this->uts);
	return ;
}

void OSModule::initData() {
	this->dataRunner();
}
void OSModule::updateData() {
	this->dataRunner();
}
std::map<std::string, std::string> OSModule::getData() {
	std::map<std::string, std::string> map;
	map["arhitecture"] = this->uts.machine;
	map["version"] = this->uts.version;
	map["release"] = this->uts.release;
	map["sysname"] = this->uts.sysname;
	return map;
}

std::string OSModule::getName() const
{return this->_name;}