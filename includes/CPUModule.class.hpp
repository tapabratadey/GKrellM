/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<< HEAD
/*   CPUModule.class.hpp                                 :+:      :+:    :+:   */
=======
/*   CPUModule.class.hpp                                :+:      :+:    :+:   */
>>>>>>> dorf
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 01:55:53 by maghayev          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/07/07 04:40:12 by maghayev         ###   ########.fr       */
=======
/*   Updated: 2018/07/07 14:28:26 by bpierce          ###   ########.fr       */
>>>>>>> dorf
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUMODULE_CLASS_HPP
# define CPUMODULE_CLASS_HPP

#include <sys/types.h>
#include <sys/sysctl.h>
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
<<<<<<< HEAD
		int copied_len;
		char * data = new char[256];
		sysctlbyname(str, &data, &copied_len, NULL, 0);
=======
		size_t copied_len;
		char * data = new char[256];
		sysctlbyname(str.c_str(), &data, &copied_len, NULL, 0);
>>>>>>> dorf
		return std::string(data);
	}
};

#endif
