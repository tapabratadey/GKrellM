/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.interface.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 01:41:52 by maghayev          #+#    #+#             */
/*   Updated: 2018/07/07 01:45:22 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_INTERFACE_HPP
# define IMONITORMODULE_INTERFACE_HPP

class IMonitorModule {
private:
	bool isUpdateRequired;
public:
	IMonitorModule ();
	IMonitorModule (IMonitorModule const &);
	virtual ~IMonitorModule ();
	IMonitorModule & operator=(IMonitorModule const &);

	virtual void initData() = 0;
	virtual void updateData() = 0;
	virtual void getData() = 0;
};


#endif
