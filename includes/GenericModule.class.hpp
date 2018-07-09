/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GenericModule.class.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 02:03:47 by maghayev          #+#    #+#             */
/*   Updated: 2018/07/08 18:34:03 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERICMODULE_CLASS_HPP
# define GENERICMODULE_CLASS_HPP

#include <unistd.h>
#include "IMonitorModule.interface.hpp"

class GenericModule : public IMonitorModule {

# define STR_LEN 1024
private:
	const std::string _name;
	std::string name;
	std::string hostname;


public:
	GenericModule ();
	GenericModule (GenericModule const &);
	virtual ~GenericModule ();

	bool	getUpdateRequired() const;
	std::string getUserName() const;
	std::string getHostname() const;

	GenericModule & operator=(GenericModule const &);

	void readName();
	void readHostname();

	void initData();
	void updateData();
	std::map<std::string, std::string> getData();
	void dataRunner();
	std::string getName() const;
};

#endif
