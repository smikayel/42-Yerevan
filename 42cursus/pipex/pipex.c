/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:52:06 by smikayel          #+#    #+#             */
/*   Updated: 2022/07/28 20:50:29 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void huk_error(int error_number)
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

int	compare_strings(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int get_env_path_index(char **env)
{
    int index;

    index = 0;
    while (env[index])
    {
        if(compare_strings(ENV_PATH_NAME, env[index] ,4) == 0)
            return (index);
        index++;
    }
    return (-1);
}

char **env_paths(int index, char **env)
{
    char *path_equal;
    char *path;
    char **sp_env_path;

    path_equal = env[index];
    path = ft_substr(path_equal, 5, ft_strlen(path_equal));
    sp_env_path = ft_split(path, ':');
    return (sp_env_path);
}

void free_2d_char(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

char *join_flags(char **sp)
{
    int i;
    char *j_cmd;

    i = 1;
    j_cmd = NULL;
    while (sp[i])
    {
        if (!j_cmd)
            j_cmd = ft_strdup(sp[i]);
        else
        {
            j_cmd = ft_strjoin(j_cmd, " ");
            j_cmd = ft_strjoin(j_cmd, sp[i]);
        }
        i++;
    }
    return (j_cmd);
}

void parse_comands(t_command *commands,char **argv)
{
    char **s_first;
    char **s_second;

    s_first = ft_split(argv[2], ' ');
    s_second = ft_split(argv[3], ' ');
    if (!s_first || !s_second)
        huk_error(5);
    commands->fir->command_name = ft_strdup(s_first[0]);
    commands->fir->flags = s_first;
    commands->sec->command_name = ft_strdup(s_second[0]);
    commands->sec->flags = s_second;
}

t_command *get_2_commands(char **argv)
{
    t_command *commands;
    t_terminal_command *first;
    t_terminal_command *seconnd;

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
    int i;
    char *cmd_path;
    char *tmp;

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
    return NULL;
}

void cmd_valide_error(t_command *commands)
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

void env_cmd_check(t_command *commands,char **env, char**argv)
{
    int env_path_index;
    char **env_path;

    env_path_index = get_env_path_index(env);
    if (env_path_index == -1)
        huk_error(3);
    env_path = env_paths(env_path_index, env);
    if (!env_path)
        huk_error(5); 
    commands = get_2_commands(argv);
    commands->fir->cmd_path = get_cmd_path(env_path, commands->fir->command_name);
    commands->sec->cmd_path = get_cmd_path(env_path, commands->sec->command_name);
      
    cmd_valide_error(commands);
}

int get_input_file(char *input_file)
{
    int in_fd;

    in_fd = open(input_file, O_RDONLY);
    if (in_fd == -1)
        huk_error(2);
    return (in_fd);
}

int get_output_file(char *output_file)
{
    int o_fd;

    o_fd = open(output_file, O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (o_fd == -1)
        huk_error(6);
    return (o_fd);
}

void get_proc(t_proces **proc)
{
    *proc = malloc(sizeof(t_proces));
    if (!*proc)
        huk_error(5);
}

pid_t fork_checking()
{
    pid_t proces_id;

    proces_id = fork();
    if (proces_id == -1)
    {
        perror("fork");
        exit(1);
    }
    return (proces_id);
}

void run_command(t_proces *proc, char *command_name, char **flags,char **env)
{
    dup2(proc->pip_in_out[1], 1);
	close(proc->pip_in_out[1]);
	close(proc->pip_in_out[0]);
    dup2(proc->input_file, 0);
    close(proc->input_file);
    if (execve(command_name, flags, env) == -1)
        exit(1);
}

int main(int ac, char **argv, char **env)
{
    t_command *commands;
    t_proces *proc;

    if (ac != 5)
        huk_error(1);

    // get_proc(&proc);
    // proc->input_file = get_input_file(argv[1]);
    // proc->output_file = get_output_file(argv[4]);
    env_cmd_check(commands, env, argv);

  

    char **asd =  get_argv_cmd(commands->fir->flags);
    int i = 0;
    while (asd[i])
    {
        printf("%s", asd[i]);
        i++;
    }
  
  
  /*
    if (pipe(proc->pip_in_out) == -1)
        huk_error(7);
    proc->pid1 =  fork_checking();
    if (proc->pid1 == 0)
        run_command(proc, commands->fir->command_name, get_argv_cmd(commands->fir->flags), env);
    proc->pid2 =  fork_checking();
    if (proc->pid2 == 0)
        run_command(proc, commands->sec->command_name, get_argv_cmd(commands->fir->flags), env);
    
    close(proc->input_file);
    close(proc->output_file);
    //===========
    waitpid(proc->pid1, NULL, 0);
	waitpid(proc->pid2, NULL, 0);
    //===========
    */
    printf("%s\n", commands->fir->cmd_path);
    printf("%s\n", commands->sec->cmd_path);
    return (0);

}