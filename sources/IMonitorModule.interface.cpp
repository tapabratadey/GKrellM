/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.interface.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 17:31:49 by maghayev          #+#    #+#             */
/*   Updated: 2018/07/08 18:33:27 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorModule.interface.hpp"

IMonitorModule::IMonitorModule () {}
IMonitorModule::~IMonitorModule () {}

std::string IMonitorModule::getModuleName() {	return this->moduleName;	}
