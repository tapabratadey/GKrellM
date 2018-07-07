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

DateTimeModule::DateTimeModule () {
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
  	this->ptm = gmtime ( &rawtime );
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
	map["year"] = this->toString(this->ptm->tm_year + 1900);
	map["month"] = this->toString(this->ptm->tm_mon);
	map["day"] = this->toString(this->ptm->tm_mday);
	map["hour"] = this->toString(this->ptm->tm_hour);
	map["minute"] = this->toString(this->ptm->tm_min);
	map["second"] = this->toString(this->ptm->tm_sec);
	map["timestr"] = this->timestr;
	return map;
}
