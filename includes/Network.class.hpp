/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Network.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <tadey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 18:20:40 by tadey             #+#    #+#             */
/*   Updated: 2018/07/08 20:16:23 by maghayev         ###   ########.fr       */
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
	std::string netStat;

public:
	Network ();
	Network (Network const &);
	virtual ~Network ();

	std::string getNetStat() const;

	Network & operator=(Network const &);

	void initData();
	void updateData();
	std::map<std::string, std::string> getData();
	void dataRunner();
    std::string parseNetworkUsage();
};

#endif //NETWORK_CLASS_HPP_
