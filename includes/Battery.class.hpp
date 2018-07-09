/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Battery.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 16:38:42 by tadey             #+#    #+#             */
/*   Updated: 2018/07/08 16:38:43 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BATTERY_CLASS_HPP
# define BATTERY_CLASS_HPP

#include <sys/types.h>
#include <sys/sysctl.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include "IMonitorModule.interface.hpp"

class Battery : public IMonitorModule {

private:
	/* Data to store for RAM */
	const std::string _name;
	std::string battery;

public:
	Battery ();
	Battery (Battery const &);
	virtual ~Battery ();

	bool	getUpdateRequired() const;

	Battery & operator=(Battery const &);

	void initData();
	void updateData();
	std::map<std::string, std::string> getData();
	void dataRunner();
	
	std::string parseBatteryInfo();
	std::string getName() const;
};

#endif