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

static int monitor_id = 0;
class IMonitorModule {
private:
	IMonitorModule & operator=(IMonitorModule const &);
protected:
<<<<<<< HEAD
	std::string moduleName;
	bool isUpdateRequired;
public:
	IMonitorModule ();
	IMonitorModule (IMonitorModule const &);
	virtual ~IMonitorModule ();

	std::string getModuleName();
=======
    int const _id;
	bool isUpdateRequired;
public:
	IMonitorModule ()  : _id(monitor_id++) {}
	IMonitorModule (IMonitorModule const &) : _id(monitor_id++) {}
	virtual ~IMonitorModule () {}
>>>>>>> 675a5940fa477ea6b65e9920e25e79192fbe8775

	virtual void initData() = 0;
	virtual void updateData() = 0;
	virtual std::map<std::string, std::string> getData() = 0;
	virtual void dataRunner() = 0;
	int getID() { return this->_id; }
	virtual std::string getName() const = 0;
	template <typename T>
	std::string toString ( T Number )
	{
		std::ostringstream ss;
		ss << Number;
		return ss.str();
	}
};

#endif
