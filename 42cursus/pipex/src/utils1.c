/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:00:29 by smikayel          #+#    #+#             */
/*   Updated: 2022/08/02 15:05:56 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	parse_comands(t_command *commands, char **argv)
{
	char	**s_first;
	char	**s_second;

	s_first = ft_split(argv[2], ' ');
	s_second = ft_split(argv[3], ' ');
	if (!s_first || !s_second)
		huk_error(5);
	commands->fir->command_name = ft_strdup(s_first[0]);
	commands->sec->command_name = ft_strdup(s_second[0]);
	free_2d_char(s_first);
	free_2d_char(s_second);
}

t_command	*get_2_commands(char **argv)
{
	t_command			*commands;
	t_terminal_command	*first;
	t_terminal_command	*seconnd;

	commands = malloc(sizeof(t_command *));
	first = malloc(sizeof(t_command *));
	seconnd = malloc(sizeof(t_command *));
	if (!commands || !first || !seconnd)
		huk_error(5);
	commands->fir = first;
	commands->sec = seconnd;
	parse_comands(commands, argv);
	return (commands);
}

char	*get_cmd_path(char **env_path, char *cmd)
{
	int		i;
	char	*cmd_path;
	char	*tmp;

	i = 0;
	cmd_path = NULL;
	while (env_path[i])
	{
		if (cmd_path)
		{
			tmp = cmd_path;
			cmd_path = NULL;
			free(tmp);
		}
		cmd_path = ft_strdup(env_path[i]);
		cmd_path = ft_strjoin(cmd_path, "/");
		cmd_path = ft_strjoin(cmd_path, cmd);
		if (access(cmd_path, X_OK | R_OK) == 0)
			return (cmd_path);
		i++;
	}
	return (NULL);
}

void	cmd_valide_error(t_command *commands)
{
	if (!commands->fir->cmd_path)
	{
		printf("Command not valide: %s", commands->fir->command_name);
		exit(0);
	}
	else if (!commands->sec->cmd_path)
	{
		printf("Command not valide: %s", commands->sec->command_name);
		exit(0);
	}
}

t_command	*env_cmd_check(char **env, char**argv)
{
	int			env_path_index;
	t_command	*commands;
	char		**env_path;

	env_path_index = get_env_path_index(env);
	if (env_path_index == -1)
		huk_error(3);
	env_path = env_paths(env_path_index, env);
	if (!env_path)
		huk_error(5);
	commands = get_2_commands(argv);
	commands->fir->cmd_path = get_cmd_path(env_path,
			commands->fir->command_name);
	commands->sec->cmd_path = get_cmd_path(env_path,
			commands->sec->command_name);
	free_2d_char(env_path);
	free(commands->sec->command_name);
	cmd_valide_error(commands);
	return (commands);
}
