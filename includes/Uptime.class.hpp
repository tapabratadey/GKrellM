/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Uptime.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 15:22:51 by tadey             #+#    #+#             */
/*   Updated: 2018/07/08 15:22:52 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef UPTIME_CLASS_HPP
# define UPTIME_CLASS_HPP

#include <sys/types.h>
#include <sys/sysctl.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include "IMonitorModule.interface.hpp"

class Uptime : public IMonitorModule {

private:
	/* Data to store for RAM */
	const std::string _name;
	std::string uptime;

public:
	Uptime ();
	Uptime (Uptime const &);
	virtual ~Uptime ();

	bool	getUpdateRequired() const;

	Uptime & operator=(Uptime const &);

	void initData();
	void updateData();
	std::map<std::string, std::string> getData();
	void dataRunner();
	
	std::string parseUptimeInfo();
};

#endif