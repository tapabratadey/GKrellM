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

int main()
{
    Hostname hostname;
    std::cout << "User: " << hostname.getUserName() << std::endl;
    std::cout << "Host: " << hostname.getHostName() << std::endl;
    return (0);
}