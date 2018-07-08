/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 01:55:53 by maghayev          #+#    #+#             */
/*   Updated: 2018/07/07 14:59:13 by bpierce          ###   ########.fr       */
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

	template <typename T>
	//parse brandname/cpuname/clockspeed
	std::string parseInfo(std::string str) {
		size_t copied_len;
		char	data[1024];
		sysctlbyname(str.c_str(), data, &copied_len, NULL, 0);
		data[copied_len] = 0;
		return std::string(data);
	}

	//parse core_count
	std::string parseInfo2(std::string str) {
		size_t copied_len;
		int	data;
		std::stringstream ss;
		sysctlbyname(str.c_str(), &data, &copied_len, NULL, 0);
		ss << data;
		return (ss.str());
	}

	//cpu usage
	std::string parseCPUInfoUsage(){
		system("top -l 1 | grep -E \"^CPU\" > info");
		std::string line;
		std::string temp;
		std::ifstream myfile ("info");
		while (getline (myfile, line))
			temp = line;
		size_t f = temp.find("CPU usage: ");
			temp.replace(f, std::string("CPU usage: ").length(), "");
		myfile.close();
		return (temp);
	}
};

#endif
