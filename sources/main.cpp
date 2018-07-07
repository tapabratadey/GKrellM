/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 14:59:00 by tadey             #+#    #+#             */
/*   Updated: 2018/07/06 14:59:02 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hostname.class.hpp"
#include "OSInfoModule.class.hpp"
#include "Date.class.hpp"

#if 1
int main()
{
    //hostname/username
    Hostname hostname;
    std::cout << std::endl;
    std::cout << "User: " << hostname.getUserName() << std::endl;
    std::cout << "Host: " << hostname.getHostName() << std::endl;

    //OS info module
    OSInfoModule osInfo;
    std::cout << "OS info: " << osInfo.getInfo() << std::endl;

    //date/time
    Date date;
    std::cout << "Date: " << date.getDate() << std::endl;

    return (0);
}
#endif
