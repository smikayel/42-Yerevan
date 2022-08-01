/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:52:06 by smikayel          #+#    #+#             */
/*   Updated: 2022/08/01 20:24:31 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **argv, char **env)
{
	t_command	*commands;
	t_proces	*proc;

	if (ac != 5)
		huk_error(1);
	get_proc(&proc);
	get_in_out(proc, argv);
	commands = env_cmd_check(env, argv);
	if (pipe(proc->pip_in_out) == -1)
		huk_error(7);
	proc->child1 = fork_checking();
	if (proc->child1 == 0)
		run_command_one(proc, commands->fir->cmd_path, argv[2], env);
	proc->child2 = fork_checking();
	if (proc->child2 == 0)
		run_command_two(proc, commands->sec->cmd_path, argv[3], env);
	close_pipe_to_ends(proc->pip_in_out);
	wait_process(proc->child1, proc->child2);
	return (0);
}
