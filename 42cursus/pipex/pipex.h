#ifndef PIPEX_H
#define PIPEX_H

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef ENV_PATH_NAME
#define ENV_PATH_NAME "PATH"
#endif

typedef struct s_terminal_command {
    char *command_name;
    char *cmd_path;
    char **flags;
} t_terminal_command;

typedef struct s_command {
    t_terminal_command *fir;
    t_terminal_command *sec;
} t_command;

typedef struct s_proces {
    int pip_in_out[2];
    int input_file;
    int output_file;
    pid_t pid1;
    pid_t pid2;
} t_proces;

char	**ft_split(char *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);

#endif