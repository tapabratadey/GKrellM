/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Uptime.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 15:19:20 by tadey             #+#    #+#             */
/*   Updated: 2018/07/08 15:19:22 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Uptime.class.hpp"

Uptime::Uptime () : _name("UPTIME") {
	this->isUpdateRequired = false;
	this->initData();
}
Uptime::Uptime (Uptime const & src) {
	*this = src;
	return ;
}
Uptime::~Uptime () {}

bool	Uptime::getUpdateRequired() const {	return this->isUpdateRequired;	}

Uptime & Uptime::operator=(Uptime const & rhs) {
	if (this != &rhs) {
		this->isUpdateRequired = rhs.getUpdateRequired();
	}
	return *this;
}

void Uptime::dataRunner() {
		this->uptime = this->parseUptimeInfo();
	return ;
}

void Uptime::initData() {
	this->dataRunner();
}
void Uptime::updateData() {
	this->dataRunner();
}
std::map<std::string, std::string> Uptime::getData() {
	std::map<std::string, std::string> map;
	map["uptime"] = this->uptime;
	return map;
}

std::string Uptime::parseUptimeInfo(){
	system("uptime > uptimeinfo");
	std::string line;
	std::string temp;
	std::ifstream myfile ("uptimeinfo");
	while (getline (myfile, line))
		temp = line;
	myfile.close();
	return (temp);
}