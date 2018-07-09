/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.interface.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 17:31:49 by maghayev          #+#    #+#             */
/*   Updated: 2018/07/08 22:22:54 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorModule.interface.hpp"

IMonitorModule::IMonitorModule () {}
IMonitorModule::IMonitorModule (IMonitorModule const & src) {
	*this = src;
	return;
}
IMonitorModule::~IMonitorModule () {}

bool	IMonitorModule::getIsUpdateRequired() const {	return this->isUpdateRequired;	}
std::string IMonitorModule::getModuleName() const {	return this->moduleName;	}

IMonitorModule & IMonitorModule::operator=(IMonitorModule const & rhs) {
	if (this != &rhs) {
		this->moduleName = rhs.getModuleName();
		this->isUpdateRequired = rhs.getIsUpdateRequired();
	}
	return *this;
}
