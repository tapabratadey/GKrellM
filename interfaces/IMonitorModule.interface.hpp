/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.interface.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 01:41:52 by maghayev          #+#    #+#             */
/*   Updated: 2018/07/08 17:32:59 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_INTERFACE_HPP
# define IMONITORMODULE_INTERFACE_HPP

#include <map>
#include <string>
#include <sstream>

class IMonitorModule {
private:
	IMonitorModule & operator=(IMonitorModule const &);
protected:
	std::string moduleName;
	bool isUpdateRequired;
public:
	IMonitorModule ();
	IMonitorModule (IMonitorModule const &);
	virtual ~IMonitorModule ();

	std::string getModuleName();

	virtual void initData() = 0;
	virtual void updateData() = 0;
	virtual std::map<std::string, std::string> getData() = 0;
	virtual void dataRunner() = 0;
	template <typename T>
	std::string toString ( T Number )
	{
		std::ostringstream ss;
		ss << Number;
		return ss.str();
	}
};


#endif
