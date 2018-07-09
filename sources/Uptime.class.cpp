/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Uptime.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <tadey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 15:19:20 by tadey             #+#    #+#             */
/*   Updated: 2018/07/08 20:12:50 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Uptime.class.hpp"

Uptime::Uptime () {
	this->moduleName = "UptimeModule";
	this->isUpdateRequired = false;
	this->initData();
}
Uptime::Uptime (Uptime const & src) : IMonitorModule(src) {
	*this = src;
	return ;
}
Uptime::~Uptime () {}

std::string	Uptime::getUptime() const {	return this->uptime;	}

Uptime & Uptime::operator=(Uptime const & rhs) {
	if (this != &rhs) {
		this->uptime = rhs.getUptime();
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
