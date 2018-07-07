/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 02:53:03 by maghayev          #+#    #+#             */
/*   Updated: 2018/07/07 04:11:13 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GenericModule.class.hpp"
#include "OSModule.class.hpp"

#include <iostream>
#include <sys/sysctl.h>
#include <sys/utsname.h>
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



	return 0;
}
