/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseBase.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 16:34:45 by maghayev          #+#    #+#             */
/*   Updated: 2018/07/08 20:18:44 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BaseBase.class.hpp"

BaseBase::BaseBase() {
	initData();
}

BaseBase::BaseBase (BaseBase const & src) {
	*this = src;
	return ;
}
BaseBase::~BaseBase () {}

std::map<std::string, std::map<std::string, std::string> > BaseBase::getDataVar() const {	return this->data;	}
std::vector<IMonitorModule*> BaseBase::getModulesVar() const {	return this->modules;	}

BaseBase & BaseBase::operator=(BaseBase const & rhs) {
	if (this != &rhs) {
		this->data = rhs.getDataVar();
		if (!this->modules.empty())
			for (std::vector<IMonitorModule*>::iterator v = this->modules.begin(); v != this->modules.end(); v++)
				delete *v;
		this->modules = rhs.getModulesVar();
	}
	return *this;
}

void BaseBase::initData() {
	this->modules.push_back(new CPUModule());
	this->modules.push_back(new DateTimeModule());
	this->modules.push_back(new GenericModule());
	this->modules.push_back(new OSModule());
	this->modules.push_back(new RAMModule());
	this->modules.push_back(new Network());
	this->modules.push_back(new Uptime());
	this->modules.push_back(new Battery());
}

void BaseBase::updater(IMonitorModule * module) {
	module->updateData();
	return;
}
void BaseBase::dataGetter(IMonitorModule * module) {
	this->updater(module);
	this->data[module->getModuleName()] = module->getData();
}

void BaseBase::updateData() {
	std::vector<IMonitorModule*>::iterator iter_start;
	std::vector<IMonitorModule*>::iterator iter_end;
	std::for_each(this->modules.begin(), this->modules.end(),  std::bind1st(std::mem_fun(&BaseBase::updater), this));
	return ;
}
std::map<std::string, std::map<std::string, std::string> > BaseBase::getData() {
	std::vector<IMonitorModule*>::iterator iter_start;
	std::vector<IMonitorModule*>::iterator iter_end;
	std::for_each(this->modules.begin(), this->modules.end(),  std::bind1st(std::mem_fun(&BaseBase::dataGetter), this));
	return this->data;
}
