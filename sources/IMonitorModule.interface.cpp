/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.interface.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 17:31:49 by maghayev          #+#    #+#             */
/*   Updated: 2018/07/08 17:32:48 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorModule.interface.hpp"

IMonitorModule::IMonitorModule () {}
IMonitorModule::IMonitorModule (IMonitorModule const &) {}
IMonitorModule::~IMonitorModule () {}

std::string IMonitorModule::getModuleName() {	return this->moduleName;	}
