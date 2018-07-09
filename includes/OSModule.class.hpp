/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSModule.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 01:55:53 by maghayev          #+#    #+#             */
/*   Updated: 2018/07/08 20:16:33 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSMODULE_CLASS_HPP
# define OSMODULE_CLASS_HPP

#include <sys/utsname.h>
#include "IMonitorModule.interface.hpp"

class OSModule : public IMonitorModule {

private:
	struct utsname uts;
public:
	OSModule ();
	OSModule (OSModule const &);
	virtual ~OSModule ();

	struct utsname getUts() const;

	OSModule & operator=(OSModule const &);

	void initData();
	void updateData();
	std::map<std::string, std::string> getData();
	void dataRunner();

};

#endif
