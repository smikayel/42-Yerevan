/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:02:08 by smikayel          #+#    #+#             */
/*   Updated: 2022/08/01 21:15:27 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	get_output_file(char *output_file)
{
	int	o_fd;

	o_fd = open(output_file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (o_fd == -1)
		huk_error(6);
	return (o_fd);
}

void	get_proc(t_proces **proc)
{
	*proc = malloc(sizeof(t_proces));
	if (!*proc)
		huk_error(5);
}

pid_t	fork_checking(void)
{
	pid_t	proces_id;

	proces_id = fork();
	if (proces_id < 0)
	{
		perror("Fork: ");
		exit(1);
	}
	return (proces_id);
}

void	run_command_one(t_proces *proc, char *command_name,
		char *cmd_input, char **env)
{
	dup2(proc->pip_in_out[1], 1);
	close(proc->pip_in_out[1]);
	close(proc->pip_in_out[0]);
	dup2(proc->input_file, 0);
	close(proc->input_file);
	if (execve(command_name, ft_split(cmd_input, ' '), env) == -1)
		exit(1);
}

void	run_command_two(t_proces *proc,
		char *command_name, char *cmd_input, char **env)
{
	dup2(proc->pip_in_out[0], 0);
	close(proc->pip_in_out[1]);
	close(proc->pip_in_out[0]);
	dup2(proc->output_file, 1);
	close(proc->output_file);
	if (execve(command_name, ft_split(cmd_input, ' '), env) == -1)
		exit(1);
}
