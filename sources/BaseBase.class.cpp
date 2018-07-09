/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseBase.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 16:34:45 by maghayev          #+#    #+#             */
/*   Updated: 2018/07/08 17:38:36 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BaseBase.class.hpp"
#include "CPUModule.class.hpp"
#include "DateTimeModule.class.hpp"
#include "GenericModule.class.hpp"
#include "OSModule.class.hpp"
#include "RAMModule.class.hpp"
#include "Network.class.hpp"


BaseBase::BaseBase() {
	initData();
}

void BaseBase::initData() {
	this->modules.push_back(new CPUModule());
	this->modules.push_back(new DateTimeModule());
	this->modules.push_back(new GenericModule());
	this->modules.push_back(new OSModule());
	this->modules.push_back(new RAMModule());
	this->modules.push_back(new Network());
}

void BaseBase::updater(IMonitorModule * module) {
	module->updateData();
	return;
}
void BaseBase::dataGetter(IMonitorModule * module) {
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
