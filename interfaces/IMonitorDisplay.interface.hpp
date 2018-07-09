/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.interface.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 01:50:39 by maghayev          #+#    #+#             */
/*   Updated: 2018/07/07 13:51:02 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_INTERFACE_HPP
# define IMONITORDISPLAY_INTERFACE_HPP

class IMonitorDisplay {

private:
	IMonitorDisplay & operator=(IMonitorDisplay const &);

protected:
	bool 		isUpdateRequired;
	BaseBase 	*baseModule;

public:
	IMonitorDisplay () {}
	IMonitorDisplay (IMonitorDisplay const &) {}
	virtual ~IMonitorDisplay () {}

	virtual void screenInit() = 0;
	virtual void screenDraw() = 0;
	virtual void screenRefresh() = 0;

	virtual void getBaseModule() = 0;
};


#endif
