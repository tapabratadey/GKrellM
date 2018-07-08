/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMModule.class.cpp                                 :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 02:31:20 by maghayev          #+#    #+#             */
/*   Updated: 2018/07/07 04:29:56 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RAMModule.class.hpp"

RAMModule::RAMModule () : _name("RAM USAGE") {
	this->isUpdateRequired = false;
	this->initData();
}
RAMModule::RAMModule (RAMModule const & src) {
	*this = src;
	return ;
}
RAMModule::~RAMModule () {}

bool	RAMModule::getUpdateRequired() const {	return this->isUpdateRequired;	}

RAMModule & RAMModule::operator=(RAMModule const & rhs) {
	if (this != &rhs) {
		this->isUpdateRequired = rhs.getUpdateRequired();
	}
	return *this;
}

void RAMModule::dataRunner() {
		this->ramUsage = this->parseRAMInfoUsage();
	return ;
}

void RAMModule::initData() {
	this->dataRunner();
}
void RAMModule::updateData() {
	this->dataRunner();
}
std::map<std::string, std::string> RAMModule::getData() {
	std::map<std::string, std::string> map;
	map["ramUsage"] = this->ramUsage;
	return map;
}

std::string RAMModule::parseRAMInfoUsage(){
	system("top -l 1 | grep -E \"^PhysMem\" > raminfo");
	std::string line;
	std::string temp;
	std::ifstream myfile ("raminfo");
	while (getline (myfile, line))
		temp = line;
	size_t f = temp.find("PhysMem: ");
		temp.replace(f, std::string("PhysMem: ").length(), "");
	myfile.close();
	return (temp);
}