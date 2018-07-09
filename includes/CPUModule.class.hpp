/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 01:55:53 by maghayev          #+#    #+#             */
/*   Updated: 2018/07/08 18:59:52 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUMODULE_CLASS_HPP
# define CPUMODULE_CLASS_HPP

#include <sys/types.h>
#include <sys/sysctl.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include "IMonitorModule.interface.hpp"

class CPUModule : public IMonitorModule {

private:
	const std::string _name;
	std::string cpuname;
	std::string brandName;
	std::string coreCount;
	std::string clockspeed;
	std::string cpuUsage;
public:
	CPUModule ();
	CPUModule (CPUModule const &);
	virtual ~CPUModule ();

	bool	getUpdateRequired() const;

	CPUModule & operator=(CPUModule const &);

	void initData();
	void updateData();
	std::map<std::string, std::string> getData();
	void dataRunner();
	std::string getName() const;

	std::string parseInfo(std::string str);
	std::string parseInfo2(std::string str);
	std::string parseCPUInfoUsage();
};

#endif
