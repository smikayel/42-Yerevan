/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:43:55 by smikayel          #+#    #+#             */
/*   Updated: 2022/08/02 15:22:48 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_2d_char(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	get_in_out(t_proces	*proc, char **argv)
{
	if (!*argv[2] || !*argv[3])
	{
		ft_printf("%s", "Input error!");
		exit(0);
	}
	proc->input_file = get_input_file(argv[1]);
	proc->output_file = get_output_file(argv[4]);
}
