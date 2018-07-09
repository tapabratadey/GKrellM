/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GenericModule.class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 02:31:20 by maghayev          #+#    #+#             */
/*   Updated: 2018/07/08 20:17:15 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GenericModule.class.hpp"

GenericModule::GenericModule () {
	this->moduleName = "GenericModule";
	this->isUpdateRequired = false;
	this->initData();
}
GenericModule::GenericModule (GenericModule const & src) : IMonitorModule(src) {
	*this = src;
	return ;
}
GenericModule::~GenericModule () {}

std::string GenericModule::getUserName() const {	return this->name;	}
std::string GenericModule::getHostname() const {	return this->hostname;	}

GenericModule & GenericModule::operator=(GenericModule const & rhs) {
	if (this != &rhs) {
		this->name = rhs.getUserName();
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
	this->model = this->parseModelInfo();
	this->memory = this->parseMemoryInfo();
	this->serial = this->parseSerialInfo();
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
	map["model"] = this->model;
	map["memory"] = this->memory;
	map["serial"] = this->serial;
	return map;
}

std::string& ltrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
    str.erase(0, str.find_first_not_of(chars));
    return str;
}

std::string GenericModule::parseModelInfo(){
	system(" system_profiler SPHardwareDataType | grep -E \"  Model Name:\" > modelInfo");
	std::string line;
	std::string temp;
	std::ifstream myfile ("modelInfo");
	while (getline (myfile, line))
		temp = line;
	ltrim(temp, "\tModel Name:");
 	myfile.close();
	return (temp);
}

std::string GenericModule::parseMemoryInfo(){
	system("system_profiler SPHardwareDataType | grep -E \" Memory\" > memoryInfo");
	std::string line;
	std::string temp;
	std::ifstream myfile ("memoryInfo");
	while (getline (myfile, line))
		temp = line;
	ltrim(temp, "\tMemory: ");
	myfile.close();
	return (temp);
}

std::string GenericModule::parseSerialInfo(){
	system("system_profiler SPHardwareDataType | grep -E \"  Serial\" > serialNuminfo");
	std::string line;
	std::string temp;
	std::ifstream myfile ("serialNuminfo");
	while (getline (myfile, line))
		temp = line;
	ltrim(temp, "\tSerial Number (system): ");
	myfile.close();
	return (temp);
}

