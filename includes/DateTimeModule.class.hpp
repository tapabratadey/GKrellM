/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateTimeModule.class.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 04:17:11 by maghayev          #+#    #+#             */
/*   Updated: 2018/07/08 20:15:22 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATETIMEMODULE_CLASS_HPP
# define DATETIMEMODULE_CLASS_HPP

#include "IMonitorModule.interface.hpp"
#include <ctime>

class DateTimeModule : public IMonitorModule {

private:
	struct tm * ptm;
	std::string timestr;
public:
	DateTimeModule ();
	DateTimeModule (DateTimeModule const &);
	virtual ~DateTimeModule ();

	bool	getUpdateRequired() const;
	struct tm * getTmTime() const;
	std::string getTimeStr() const;

	DateTimeModule & operator=(DateTimeModule const &);

	void initData();
	void updateData();
	std::map<std::string, std::string> getData();
	void dataRunner();
};

#endif
