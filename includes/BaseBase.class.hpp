/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseBase.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 16:34:43 by maghayev          #+#    #+#             */
/*   Updated: 2018/07/08 20:17:37 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASEBASE_CLASS_HPP
# define BASEBASE_CLASS_HPP

#include "IMonitorModule.interface.hpp"
#include "CPUModule.class.hpp"
#include "DateTimeModule.class.hpp"
#include "GenericModule.class.hpp"
#include "OSModule.class.hpp"
#include "RAMModule.class.hpp"
#include "Network.class.hpp"
#include "Uptime.class.hpp"
#include "Battery.class.hpp"
#include <vector>
#include <functional>

class BaseBase {
private:
	std::vector<IMonitorModule*> modules;
	std::map<std::string, std::map<std::string, std::string> > data;
	void updater(IMonitorModule * module);
	void dataGetter(IMonitorModule * module);

public:
	BaseBase ();
	BaseBase (BaseBase const &);
	virtual ~BaseBase ();

	std::map<std::string, std::map<std::string, std::string> > getDataVar() const;
	std::vector<IMonitorModule*> getModulesVar() const;

	BaseBase & operator=(BaseBase const &);

	void initData();
	void updateData();
	std::map<std::string, std::map<std::string, std::string> > getData();
};

#endif
