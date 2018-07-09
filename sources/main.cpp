/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 02:53:03 by maghayev          #+#    #+#             */
/*   Updated: 2018/07/07 15:05:45 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sys/sysctl.h>
#include <sys/utsname.h>

#include "GenericModule.class.hpp"
#include "OSModule.class.hpp"
#include "DateTimeModule.class.hpp"
#include "CPUModule.class.hpp"
#include "RAMModule.class.hpp"
#include "Network.class.hpp"
#include "Uptime.class.hpp"
#include "Battery.class.hpp"

int main() {
	std::cout << std::endl;
	GenericModule gen_mod;

	std::map<std::string, std::string> map = gen_mod.getData();
	std::cout << "Hostname: " << map["hostname"] << '\n';
	std::cout << "Name: " << map["name"] << '\n';

	OSModule os_mod;

	std::map<std::string, std::string> mapos = os_mod.getData();
	std::cout << "Architecture: " << mapos["arhitecture"] << '\n';
	std::cout << "Version: " << mapos["version"] << '\n';
	std::cout << "Release: " << mapos["release"] << '\n';
	std::cout << "System name: " << mapos["sysname"] << '\n';

	DateTimeModule time_mod;

	std::map<std::string, std::string> mapotime = time_mod.getData();
	std::cout << "Date/Time: " << mapotime["timestr"];

	//CPU MODULE
	CPUModule cpu_mod;

	std::map<std::string, std::string> mapcpu = cpu_mod.getData();
	std::cout << "Brand Name: " << mapcpu["brandName"] << '\n';
	std::cout << "Core Count: " << mapcpu["coreCount"] << '\n';
	std::cout << "CPU usage: " << mapcpu["cpuUsage"] << '\n';
	
	//RAMMODULE 
	RAMModule ram_mod;
	
	std::map<std::string, std::string> mapram = ram_mod.getData();
	std::cout << "RAM usage: " << mapram["ramUsage"] << '\n';	

	//Network module
	Network net_mod;

	std::map<std::string, std::string> mapnet = net_mod.getData();
	std::cout << "Network throughput: " << mapnet["network"] << '\n';	


	//Uptime module
	Uptime uptime_mod;

	std::map<std::string, std::string> mapuptime = uptime_mod.getData();
	std::cout << "Uptime: " << mapuptime["uptime"] << '\n';

	//Battery module
	Battery battery_mod;

	std::map<std::string, std::string> mapbattery = battery_mod.getData();
	std::cout << "Battery: " << mapbattery["battery"] << '\n';
	std::cout << std::endl;
	return 0;
}
