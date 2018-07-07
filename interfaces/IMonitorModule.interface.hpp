/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.interface.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 01:41:52 by maghayev          #+#    #+#             */
/*   Updated: 2018/07/07 02:59:15 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_INTERFACE_HPP
# define IMONITORMODULE_INTERFACE_HPP

#include <map>

class IMonitorModule {
private:
	IMonitorModule & operator=(IMonitorModule const &);
protected:
	bool isUpdateRequired;
public:
	IMonitorModule () {}
	IMonitorModule (IMonitorModule const &) {}
	virtual ~IMonitorModule () {}

	virtual void initData() = 0;
	virtual void updateData() = 0;
	virtual std::map<std::string, std::string> getData() = 0;
	virtual void dataRunner() = 0;
};


#endif
