/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 01:55:53 by maghayev          #+#    #+#             */
/*   Updated: 2018/07/08 20:14:47 by maghayev         ###   ########.fr       */
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
	std::string getCpuName() const;
	std::string getBrandName() const;
	std::string getCoreCount() const;
	std::string getClockSpeed() const;
	std::string getCpuUsage() const;

	CPUModule & operator=(CPUModule const &);

	void initData();
	void updateData();
	std::map<std::string, std::string> getData();
	void dataRunner();

	std::string parseInfo(std::string str);
	std::string parseInfo2(std::string str);
	std::string parseCPUInfoUsage();
};

#endif
