/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 02:53:03 by maghayev          #+#    #+#             */
/*   Updated: 2018/07/08 22:42:39 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sys/sysctl.h>
#include <sys/utsname.h>

#include "BaseBase.class.hpp"
#include "Minilibx.class.hpp"
#include "Ncurses.class.hpp"
#include "Graph.class.hpp"

#ifdef __cplusplus
extern "C"
{
#endif

#include "mlx.h"

#ifdef __cplusplus
}
#endif

void initNCurses() {
	Ncurses	*n = new Ncurses;
	n->starter();
}

void initMiniLibX() {
	Minilibx	n;
	while (1)
		n.mlxLoop();
}

int main(int argc, char const *argv[]) {
	if (argc == 1) {
		std::cout << "Usage: ./ft_ft_gkrellm [ text | gui ]." << '\n';
		return 1;
	}
	std::string ncurse = "text";
	std::string minilibx = "gui";
	argc--;
	argv++;
	if (!ncurse.compare(*argv))
		initNCurses();
	if (!minilibx.compare(*argv))
		initMiniLibX();
	return 0;
}
