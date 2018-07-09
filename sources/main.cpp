/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 02:53:03 by maghayev          #+#    #+#             */
/*   Updated: 2018/07/08 19:03:12 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sys/sysctl.h>
#include <sys/utsname.h>

#include "BaseBase.class.hpp"

int main() {
	BaseBase base;

	std::map<std::string, std::map<std::string, std::string> > map = base.getData();

	std::cout << "Hostname " << map["GenericModule"]["hostname"] << '\n';
	std::cout << "Name " << map["GenericModule"]["name"] << '\n';

	std::cout << "Architecture " << map["OSModule"]["arhitecture"] << '\n';
	std::cout << "Version " << map["OSModule"]["version"] << '\n';
	std::cout << "Release " << map["OSModule"]["release"] << '\n';
	std::cout << "Sysname " << map["OSModule"]["sysname"] << '\n';

	std::cout << "Year " << map["DateTimeModule"]["year"] << '\n';
	std::cout << "Month " << map["DateTimeModule"]["month"] << '\n';
	std::cout << "Day " << map["DateTimeModule"]["day"] << '\n';
	std::cout << "Hour " << map["DateTimeModule"]["hour"] << '\n';
	std::cout << "Minute " << map["DateTimeModule"]["minute"] << '\n';
	std::cout << "Seconds " << map["DateTimeModule"]["second"] << '\n';
	std::cout << "Time qualify: " << map["DateTimeModule"]["timestr"] << '\n';

	std::cout << "Brand Name: " << map["CPUModule"]["brandName"] << '\n';
	std::cout << "Core Count: " << map["CPUModule"]["coreCount"] << '\n';
	std::cout << "CPU usage: " << map["CPUModule"]["cpuUsage"] << '\n';

	std::cout << "RAM usage: " << map["RAMModule"]["ramUsage"] << '\n';

	std::cout << "Network throughput: " << map["NetworkModule"]["network"] << '\n';

	std::cout << "Uptime: " << map["UptimeModule"]["uptime"] << '\n';

	std::cout << "Battery: " << map["BatteryModule"]["battery"] << '\n';
	std::cout << std::endl;
	return 0;
}
