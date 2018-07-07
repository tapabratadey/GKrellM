/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSModule.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 01:55:53 by maghayev          #+#    #+#             */
/*   Updated: 2018/07/07 04:03:37 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSMODULE_CLASS_HPP
# define OSMODULE_CLASS_HPP

#include <string>
#include <sys/utsname.h>
#include "IMonitorModule.interface.hpp"

class OSModule : public IMonitorModule {

private:
	struct utsname uts;
public:
	OSModule ();
	OSModule (OSModule const &);
	virtual ~OSModule ();

	bool	getUpdateRequired() const;

	OSModule & operator=(OSModule const &);

	void initData();
	void updateData();
	std::map<std::string, std::string> getData();
	void dataRunner();
};

#endif
