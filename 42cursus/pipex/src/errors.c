/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:34:23 by smikayel          #+#    #+#             */
/*   Updated: 2022/08/01 14:36:11 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	huk_error(int error_number)
{
	if (error_number == 1)
		printf("Arguments count not correct!!!");
	else if (error_number == 2)
		printf("Somthing went wrong with input file!!!");
	else if (error_number == 3)
		printf("env. path not found, or somthing went wrong!!!");
	else if (error_number == 4)
		printf("Commands not valide or not found in path!!!");
	else if (error_number == 5)
		printf("Error with memory alocation!");
	else if (error_number == 6)
		printf("Somthing went wrong with output file!!!");
	else if (error_number == 7)
		printf("Pipe error!!!");
	exit(0);
}

int	get_input_file(char *input_file)
{
	int	in_fd;

	in_fd = open(input_file, O_RDONLY);
	if (in_fd == -1)
		huk_error(2);
	return (in_fd);
}
