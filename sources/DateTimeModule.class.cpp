/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateTimeModule.class.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 04:30:11 by maghayev          #+#    #+#             */
/*   Updated: 2018/07/07 04:53:42 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DateTimeModule.class.hpp"

DateTimeModule::DateTimeModule () : _name("DATE/TIME MODULE") {
	this->isUpdateRequired = false;
	this->initData();
}
DateTimeModule::DateTimeModule (DateTimeModule const & src) {
	*this = src;
	return ;
}
DateTimeModule::~DateTimeModule () {}

bool	DateTimeModule::getUpdateRequired() const {	return this->isUpdateRequired;	}

DateTimeModule & DateTimeModule::operator=(DateTimeModule const & rhs) {
	if (this != &rhs) {
		this->isUpdateRequired = rhs.getUpdateRequired();
	}
	return *this;
}

void DateTimeModule::dataRunner() {
	time_t rawtime;
	time ( &rawtime );
	this->timestr = ctime(&rawtime);
	return ;
}

void DateTimeModule::initData() {
	this->dataRunner();
}
void DateTimeModule::updateData() {
	this->dataRunner();
}
std::map<std::string, std::string> DateTimeModule::getData() {
	std::map<std::string, std::string> map;
	map["timestr"] = this->timestr;
	return map;
}

std::string DateTimeModule::getName() const
{return this->_name;}