/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.class.cpp                                 :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 02:31:20 by maghayev          #+#    #+#             */
/*   Updated: 2018/07/07 04:29:56 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CPUModule.class.hpp"

CPUModule::CPUModule () : _name("CPU USAGE")
{
	this->isUpdateRequired = false;
	this->initData();
}
CPUModule::CPUModule (CPUModule const & src) {
	*this = src;
	return ;
}
CPUModule::~CPUModule () {}

bool	CPUModule::getUpdateRequired() const {	return this->isUpdateRequired;	}

CPUModule & CPUModule::operator=(CPUModule const & rhs) {
	if (this != &rhs) {
		this->isUpdateRequired = rhs.getUpdateRequired();
	}
	return *this;
}

void CPUModule::dataRunner() {
	this->brandName = this->parseInfo("machdep.cpu.brand_string");
	this->coreCount = this->parseInfo2("machdep.cpu.core_count");
	this->cpuUsage = this->parseCPUInfoUsage();
	return ;
}

void CPUModule::initData() {
	this->dataRunner();
}
void CPUModule::updateData() {
	this->dataRunner();
}
std::map<std::string, std::string> CPUModule::getData() {
	std::map<std::string, std::string> map;
	map["coreCount"] = this->coreCount;
	map["brandName"] = this->brandName;
	map["cpuUsage"] = this->cpuUsage;
	return map;
}

//parse brandname/cpuname/clockspeed
std::string CPUModule::parseInfo(std::string str) {
	size_t copied_len;
	char	data[1024];
	sysctlbyname(str.c_str(), data, &copied_len, NULL, 0);
	data[copied_len] = 0;
	return std::string(data);
}

//parse core_count
std::string CPUModule::parseInfo2(std::string str) {
	size_t copied_len;
	int	data;
	std::stringstream ss;
	sysctlbyname(str.c_str(), &data, &copied_len, NULL, 0);
	ss << data;
	return (ss.str());
}

//cpu usage
std::string CPUModule::parseCPUInfoUsage(){
	system("top -l 1 | grep -E \"^CPU\" > info");
	std::string line;
	std::string temp;
	std::ifstream myfile ("info");
	while (getline (myfile, line))
		temp = line;
	size_t f = temp.find("CPU usage: ");
		temp.replace(f, std::string("CPU usage: ").length(), "");
	myfile.close();
	return (temp);
}