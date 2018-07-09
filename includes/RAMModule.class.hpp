/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMModule.class.hpp                                 :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 01:55:53 by maghayev          #+#    #+#             */
/*   Updated: 2018/07/07 04:40:12 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAMMODULE_CLASS_HPP
# define RAMMODULE_CLASS_HPP

#include <sys/types.h>
#include <sys/sysctl.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include "IMonitorModule.interface.hpp"

class RAMModule : public IMonitorModule {

private:
	/* Data to store for RAM */
	const std::string _name;
	std::string ramUsage;

public:
	RAMModule ();
	RAMModule (RAMModule const &);
	virtual ~RAMModule ();

	bool	getUpdateRequired() const;

	RAMModule & operator=(RAMModule const &);

	void initData();
	void updateData();
	std::map<std::string, std::string> getData();
	void dataRunner();
	std::string getName() const;
	
	std::string parseRAMInfoUsage();
};

#endif