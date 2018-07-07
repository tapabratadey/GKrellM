/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GenericModule.class.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 02:03:47 by maghayev          #+#    #+#             */
/*   Updated: 2018/07/07 03:02:43 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERICMODULE_CLASS_HPP
# define GENERICMODULE_CLASS_HPP

#include <unistd.h>
#include "IMonitorModule.interface.hpp"

class GenericModule : public IMonitorModule {

# define STR_LEN 1024
private:
	std::string name;
	std::string hostname;


public:
	GenericModule ();
	GenericModule (GenericModule const &);
	virtual ~GenericModule ();

	bool	getUpdateRequired() const;
	std::string getName() const;
	std::string getHostname() const;

	GenericModule & operator=(GenericModule const &);

	void readName();
	void readHostname();

	void initData();
	void updateData();
	std::map<std::string, std::string> getData();
	void dataRunner();
};

#endif
