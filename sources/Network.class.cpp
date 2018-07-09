/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Network.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <tadey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 18:20:20 by tadey             #+#    #+#             */
/*   Updated: 2018/07/08 20:16:24 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Network.class.hpp"

Network::Network () {
	this->moduleName = "NetworkModule";
	this->isUpdateRequired = false;
	this->initData();
}
Network::Network (Network const & src) : IMonitorModule(src) {
	*this = src;
	return ;
}
Network::~Network () {}

std::string Network::getNetStat() const {	return this->netStat;	}

Network & Network::operator=(Network const & rhs) {
	if (this != &rhs)
		this->netStat = rhs.getNetStat();
	return *this;
}

void Network::dataRunner() {
		this->netStat = this->parseNetworkUsage();
	return ;
}

void Network::initData() {
	this->dataRunner();
}
void Network::updateData() {
	this->dataRunner();
}
std::map<std::string, std::string> Network::getData() {
	std::map<std::string, std::string> map;
	map["network"] = this->netStat;
	return map;
}

std::string Network::parseNetworkUsage(){
    system("top -l 1 | grep -E \"^Networks\" > netinfo");
    std::string line;
    std::string temp;
    std::ifstream myfile ("netinfo");
    while (getline (myfile, line))
        temp = line;
    size_t f = temp.find("Networks: ");
        temp.replace(f, std::string("Networks: ").length(), "");
    myfile.close();
    return (temp);
}
