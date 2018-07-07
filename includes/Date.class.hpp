/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 02:41:59 by tadey             #+#    #+#             */
/*   Updated: 2018/07/07 02:42:00 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DATE_HPP_
#define DATE_HPP_
#include <iostream>


class Date
{
        char *dateInfo;
    public:
        Date();
        ~Date();
        Date(Date const &copy);
        Date &operator=(Date const &rhs);
        char *getDate();
};

#endif //DATE_HPP_
