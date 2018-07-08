/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 02:53:03 by maghayev          #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2018/07/07 15:05:45 by tadey            ###   ########.fr       */
=======
/*   Updated: 2018/07/07 15:09:25 by bpierce          ###   ########.fr       */
>>>>>>> Stashed changes
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
#include "Minilibx.class.hpp"
#include "Graph.class.hpp"
#ifdef __cplusplus
extern "C"
{
#endif

#include "mlx.h"

#ifdef __cplusplus
}
#endif


int main() {
	GenericModule gen_mod;

	std::map<std::string, std::string> map = gen_mod.getData();
	std::cout << "Hostname " << map["hostname"] << '\n';
	std::cout << "Name " << map["name"] << '\n';

	OSModule os_mod;

	std::map<std::string, std::string> mapos = os_mod.getData();
	std::cout << "Architecture " << mapos["arhitecture"] << '\n';
	std::cout << "Version " << mapos["version"] << '\n';
	std::cout << "Release " << mapos["release"] << '\n';
	std::cout << "Sysname " << mapos["sysname"] << '\n';

	DateTimeModule time_mod;

	std::map<std::string, std::string> mapotime = time_mod.getData();
	std::cout << "Year " << mapotime["year"] << '\n';
	std::cout << "Month " << mapotime["month"] << '\n';
	std::cout << "Day " << mapotime["day"] << '\n';
	std::cout << "Hour " << mapotime["hour"] << '\n';
	std::cout << "Minute " << mapotime["minute"] << '\n';
	std::cout << "Seconds " << mapotime["second"] << '\n';
	std::cout << "Time qualify: " << mapotime["timestr"] << '\n';

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

	Minilibx	m;
	Graph		g(m.getMlx());

	for (int i = 0 ; i < 1000 ; i++) {
		g.addToHistory(rand() % 1000);
	}

	g.backgroundFill(2132127);
	g.setX(200);
	g.setY(200);
	g.fillDataAll();
	g.drawToScreen(m.getWin());

	m.screenDraw(gen_mod);
	m.screenDraw(os_mod);
	m.screenDraw(time_mod);
	m.screenDraw(cpu_mod);

	while (1)
	{
		m.screenDraw();
		m.screenRefresh();
	}
	// mlx_loop(m.getMlx());

	return 0;
}
