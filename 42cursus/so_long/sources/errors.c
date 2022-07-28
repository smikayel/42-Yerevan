/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:01:55 by smikayel          #+#    #+#             */
/*   Updated: 2022/07/26 17:38:16 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_error(int err_num)
{
	if (err_num == 1)
		ft_printf("%s", "Error! \nThe map path does not correct...\n");
	else if (err_num == 2)
		ft_printf("%s", "Error! \nThe map is not rectangle...\n");
	else if (err_num == 3)
		ft_printf("%s", "Error! \nWalls part is not correct...\n");
	else if (err_num == 4)
		ft_printf("%s", "Error! \nSomething is missing...\n");
	else if (err_num == 5)
		ft_printf("%s", "Error! \nThere is 2 or more players...\n");
	else if (err_num == 6)
		ft_printf("%s", "Error! \nThere is undiscovered object on the map...\n");
	else if (err_num == 7)
		ft_printf("%s", "Error! \nEmpty map...\n");
	exit(0);
}
