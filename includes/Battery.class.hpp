/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Battery.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <tadey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 16:38:42 by tadey             #+#    #+#             */
/*   Updated: 2018/07/08 20:14:39 by maghayev         ###   ########.fr       */
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
	std::string battery;

public:
	Battery ();
	Battery (Battery const &);
	virtual ~Battery ();

	bool	getUpdateRequired() const;
	std::string getBattery() const;
	Battery & operator=(Battery const &);

	void initData();
	void updateData();
	std::map<std::string, std::string> getData();
	void dataRunner();

	std::string parseBatteryInfo();
};

#endif
