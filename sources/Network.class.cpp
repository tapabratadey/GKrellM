/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Network.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <tadey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 18:20:20 by tadey             #+#    #+#             */
/*   Updated: 2018/07/08 17:49:21 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Network.class.hpp"

Network::Network () : _name("NETWORK USAGE") {
	this->moduleName = "NetworkModule";
	this->isUpdateRequired = false;
	this->initData();
}
Network::Network (Network const & src) {
	*this = src;
	return ;
}
Network::~Network () {}

bool	Network::getUpdateRequired() const {	return this->isUpdateRequired;	}

Network & Network::operator=(Network const & rhs) {
	if (this != &rhs) {
		this->isUpdateRequired = rhs.getUpdateRequired();
	}
	return *this;
}

void Network::dataRunner() {
		this->net_stat = this->parseNetworkUsage();
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
	map["network"] = this->net_stat;
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

std::string Network::getName() const
{return this->_name;}
