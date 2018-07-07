/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GenericModule.class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 02:31:20 by maghayev          #+#    #+#             */
/*   Updated: 2018/07/07 02:59:34 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GenericModule.class.hpp"

GenericModule::GenericModule () {
	this->isUpdateRequired = false;
	this->initData();
}
GenericModule::GenericModule (GenericModule const & src) {
	*this = src;
	return ;
}
GenericModule::~GenericModule () {}

bool	GenericModule::getUpdateRequired() const {	return this->isUpdateRequired;	}
std::string GenericModule::getName() const {	return this->name;	}
std::string GenericModule::getHostname() const {	return this->hostname;	}

GenericModule & GenericModule::operator=(GenericModule const & rhs) {
	if (this != &rhs) {
		this->isUpdateRequired = rhs.getUpdateRequired();
		this->name = rhs.getName();
		this->hostname = rhs.getHostname();
	}
	return *this;
}

void GenericModule::readName() {
	char * hostname = new char[STR_LEN];
	gethostname(hostname, STR_LEN);
	this->hostname = std::string(hostname);
	delete[] hostname;
	return ;
}
void GenericModule::readHostname() {
	char * name = new char[STR_LEN];
	getlogin_r(name, STR_LEN);
	this->name = std::string(name);
	delete[] name;
	return ;
}

void GenericModule::dataRunner() {
	this->readName();
	this->readHostname();
}

void GenericModule::initData() {
	this->dataRunner();
}
void GenericModule::updateData() {
	this->dataRunner();
}
std::map<std::string, std::string> GenericModule::getData() {
	std::map<std::string, std::string> map;
	map["hostname"] = this->hostname;
	map["name"] = this->name;
	return map;
}
