/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 01:55:53 by maghayev          #+#    #+#             */
/*   Updated: 2018/07/07 14:28:26 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUMODULE_CLASS_HPP
# define CPUMODULE_CLASS_HPP

#include <sys/types.h>
#include <sys/sysctl.h>
#include <iostream>
#include "IMonitorModule.interface.hpp"

class CPUModule : public IMonitorModule {

private:
	std::string cpuname;
	std::string brandName;
	std::string coreCount;
	std::string clockspeed;
	std::string usage;

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
	std::string parseInfo(std::string str) {
		size_t copied_len;
		char	data[1024];
		sysctlbyname(str.c_str(), data, &copied_len, NULL, 0);
		data[copied_len] = 0;
		return std::string(data);
	}
};

#endif
