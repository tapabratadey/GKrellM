/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 02:31:20 by maghayev          #+#    #+#             */
/*   Updated: 2018/07/07 04:29:56 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CPUModule.class.hpp"

CPUModule::CPUModule () {
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
	this->brandName = this->parseInfo<std::string>("machdep.cpu.brand_string");
	this->coreCount = this->parseInfo<std::string>("machdep.cpu.core_count");
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
	map["brandName"] = this->brandName;
	return map;
}
