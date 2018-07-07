/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.interface.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 01:50:39 by maghayev          #+#    #+#             */
/*   Updated: 2018/07/07 01:54:05 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_INTERFACE_HPP
# define IMONITORDISPLAY_INTERFACE_HPP

class IMonitorDisplay {
private:
	IMonitorDisplay & operator=(IMonitorDisplay const &);
protected:
	bool isUpdateRequired;
public:
	IMonitorDisplay () {}
	IMonitorDisplay (IMonitorDisplay const &) {}
	virtual ~IMonitorDisplay () {}

	virtual void screenInit() = 0;
	virtual void screenDraw() = 0;
	virtual void screenRefresh() = 0;
};


#endif
