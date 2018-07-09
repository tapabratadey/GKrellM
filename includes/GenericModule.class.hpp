/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GenericModule.class.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 02:03:47 by maghayev          #+#    #+#             */
/*   Updated: 2018/07/08 20:17:10 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERICMODULE_CLASS_HPP
# define GENERICMODULE_CLASS_HPP

#include <unistd.h>
#include <fstream>
#include "IMonitorModule.interface.hpp"

class GenericModule : public IMonitorModule {

# define STR_LEN 1024
private:
	std::string name;
	std::string hostname;
	std::string model;
	std::string memory;
	std::string serial;
public:
	GenericModule ();
	GenericModule (GenericModule const &);
	virtual ~GenericModule ();

	bool	getUpdateRequired() const;
	std::string getUserName() const;
	std::string getHostname() const;
	std::string parseSerialInfo();
	std::string parseMemoryInfo();
	std::string parseModelInfo();
	GenericModule & operator=(GenericModule const &);

	void readName();
	void readHostname();

	void initData();
	void updateData();
	std::map<std::string, std::string> getData();
	void dataRunner();
};

#endif
