/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:47:18 by smikayel          #+#    #+#             */
/*   Updated: 2022/08/01 20:07:13 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>

# ifndef ENV_PATH_NAME
#  define ENV_PATH_NAME "PATH"
# endif

typedef struct s_terminal_command {
	char	*command_name;
	char	*cmd_path;
}	t_terminal_command;

typedef struct s_command {
	t_terminal_command	*fir;
	t_terminal_command	*sec;
}	t_command;

typedef struct s_proces {
	int		pip_in_out[2];
	int		input_file;
	int		output_file;
	pid_t	child1;
	pid_t	child2;
}	t_proces;

char		**ft_split(char *s, char c);
size_t		ft_strlen(const char *str);
char		*ft_substr(char *s, unsigned int start, size_t len);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *src);
void		huk_error(int error_number);
int			get_input_file(char *input_file);
int			compare_strings(char *s1, char *s2, size_t n);
int			get_env_path_index(char **env);
char		**env_paths(int index, char **env);
int			compare_strings(char *s1, char *s2, size_t n);
int			get_env_path_index(char **env);
char		**env_paths(int index, char **env);
int			sp_fl_length(char **splited);
char		**get_flags(char *cmd_str);
void		parse_comands(t_command *commands, char **argv);
t_command	*get_2_commands(char **argv);
char		*get_cmd_path(char **env_path, char *cmd);
void		cmd_valide_error(t_command *commands);
t_command	*env_cmd_check(char **env, char**argv);
int			get_output_file(char *output_file);
void		get_proc(t_proces **proc);
pid_t		fork_checking(void);
void		run_command_one(t_proces *proc, char *command_name,
				char *cmd_input, char **env);
void		run_command_two(t_proces *proc, char *command_name,
				char *cmd_input, char **env);
void		close_pipe_to_ends(int *fd);
void		wait_process(pid_t p1, pid_t p2);
void		free_2d_char(char **arr);
void		get_in_out(t_proces	*proc, char **argv);

#endif