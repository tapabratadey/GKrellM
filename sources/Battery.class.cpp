/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Battery.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 16:38:23 by tadey             #+#    #+#             */
/*   Updated: 2018/07/08 16:38:25 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Battery.class.hpp"

Battery::Battery () : _name("Battery") {
	this->isUpdateRequired = false;
	this->initData();
}
Battery::Battery (Battery const & src) {
	*this = src;
	return ;
}
Battery::~Battery () {}

bool	Battery::getUpdateRequired() const {	return this->isUpdateRequired;	}

Battery & Battery::operator=(Battery const & rhs) {
	if (this != &rhs) {
		this->isUpdateRequired = rhs.getUpdateRequired();
	}
	return *this;
}

void Battery::dataRunner() {
		this->battery = this->parseBatteryInfo();
	return ;
}

void Battery::initData() {
	this->dataRunner();
}
void Battery::updateData() {
	this->dataRunner();
}
std::map<std::string, std::string> Battery::getData() {
	std::map<std::string, std::string> map;
	map["battery"] = this->battery;
	return map;
}

std::string Battery::parseBatteryInfo(){
	system("pmset -g batt > batteryinfo");
	std::string line;
	std::string temp;
	std::ifstream myfile ("batteryinfo");
	while (getline (myfile, line))
		temp = line;
	size_t f = temp.find("Now drawing from ");
		temp.replace(f, std::string("Now drawing from ").length(), "");
	myfile.close();
	return (temp);
}

std::string Battery::getName() const
{return this->_name;}