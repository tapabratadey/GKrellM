/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hostname.Class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 19:25:02 by tadey             #+#    #+#             */
/*   Updated: 2018/07/06 19:25:04 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HOSTNAME_HPP_
#define HOSTNAME_HPP_
#include <iostream>
#define USERNAME_LENGTH 256
#define LOGIN_LENGTH 256


class Hostname
{
        char username[USERNAME_LENGTH];
        char hostname[LOGIN_LENGTH];
    public:
        Hostname();
        ~Hostname();
        Hostname(Hostname const &copy);
        Hostname &operator=(Hostname const &rhs);
        char *getUserName();
        char *getHostName();
};

#endif //HOSTNAME_HPP_
