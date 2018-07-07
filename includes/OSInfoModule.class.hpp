/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfoModule.class.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 22:02:08 by tadey             #+#    #+#             */
/*   Updated: 2018/07/06 22:02:10 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef OS_INFO_MODULE_HPP_
#define OS_INFO_MODULE_HPP_
#include <iostream>
#define BUFF_LEN 256


class OSInfoModule
{
        char buffer[BUFF_LEN];
    public:
        OSInfoModule();
        ~OSInfoModule();
        OSInfoModule(OSInfoModule const &copy);
        OSInfoModule &operator=(OSInfoModule const &rhs);
        char *getInfo();
};

#endif //OS_INFO_MODULE_HPP_
