/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Network.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 18:20:40 by tadey             #+#    #+#             */
/*   Updated: 2018/07/07 18:20:41 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef NETWORK_CLASS_HPP
# define NETWORK_CLASS_HPP

#include <sys/types.h>
#include <sys/sysctl.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include "IMonitorModule.interface.hpp"

class Network : public IMonitorModule {

private:
	/* Data to store for Network */
	const std::string _name;
	std::string net_stat;

public:
	Network ();
	Network (Network const &);
	virtual ~Network ();

	bool	getUpdateRequired() const;

	Network & operator=(Network const &);

	void initData();
	void updateData();
	std::map<std::string, std::string> getData();
	void dataRunner();
	std::string getName() const;

    std::string parseNetworkUsage();
};

#endif //NETWORK_CLASS_HPP_
