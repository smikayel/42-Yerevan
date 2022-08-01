/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:45:53 by smikayel          #+#    #+#             */
/*   Updated: 2022/08/01 18:33:05 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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

int	get_env_path_index(char **env)
{
	int	index;

	index = 0;
	while (env[index])
	{
		if (compare_strings(ENV_PATH_NAME, env[index], 4) == 0)
			return (index);
		index++;
	}
	return (-1);
}

char	**env_paths(int index, char **env)
{
	char	*path_equal;
	char	*path;
	char	**sp_env_path;

	path_equal = env[index];
	path = ft_substr(path_equal, 5, ft_strlen(path_equal));
	sp_env_path = ft_split(path, ':');
	return (sp_env_path);
}

int	sp_fl_length(char **splited)
{
	int	i;

	i = 0;
	while (splited && splited[i])
		i++;
	return (i);
}

char	**get_flags(char *cmd_str)
{
	char	**flags;
	int		length;
	char	**splited;
	int		i;

	i = 1;
	splited = ft_split(cmd_str, ' ');
	if (!splited)
		return (NULL);
	length = sp_fl_length(splited);
	flags = malloc((length -1) * sizeof(char *));
	while (splited && splited[i])
	{
		flags[i - 1] = splited[i];
		i++;
	}
	flags[i - 1] = NULL;
	return (flags);
}
