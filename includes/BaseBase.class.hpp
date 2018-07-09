/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseBase.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 16:34:43 by maghayev          #+#    #+#             */
/*   Updated: 2018/07/08 17:30:37 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASEBASE_CLASS_HPP
# define BASEBASE_CLASS_HPP

#include "IMonitorModule.interface.hpp"
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

	BaseBase & operator=(BaseBase const &);

	void initData();
	void updateData();
	std::map<std::string, std::map<std::string, std::string> > getData();
};

#endif
