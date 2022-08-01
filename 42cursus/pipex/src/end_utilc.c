/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_utilc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:07:46 by smikayel          #+#    #+#             */
/*   Updated: 2022/08/01 20:08:16 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	close_pipe_to_ends(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

void	wait_process(pid_t p1, pid_t p2)
{
	waitpid(p1, NULL, 0);
	waitpid(p2, NULL, 0);
}
