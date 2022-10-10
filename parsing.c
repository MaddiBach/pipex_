#include "pipex.h"

char	*check_and_find(char *cmd, char **envp)
{
	char	*binpath;

	if (cmd_in_workdir(cmd))
		return(ft_strdup(cmd));
	if (*envp == NULL)
		return (NULL);
	binpath = is_in_path(cmd, envp);
	return (binpath);
}

char	**find_path(char **envp)
{
	char	**path;
	int		i;

	i = 0;
	if (!envp)
		return (NULL);
	while (ft_strncmp(envp[i], "PATH=", 5) && envp[i + 1])
		i++;
	if (envp[i] == NULL)
		return (NULL);
	return (ft_split(envp[i] + 5, ':'));
}

char	*ft_strdup_first_word(const char *s)
{
	char	*p;
	int		i;

	i = 0;
	p = malloc(sizeof(char) * ft_strlen((char *)s) + 1);
	if (p == 0)
		return (NULL);
	while (s[i] && s[i] != ' ')
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*is_in_path(char *cmd, char **envp)
{
	char	**path;
	char	*binpath;
    char *tmp;

	path = find_path(envp);
	if (path == NULL)
		return (NULL);
    tmp = ft_strdup_first_word(cmd);
    path = ft_join_bin(path, tmp);
	if (path == NULL)
		return (NULL);
    free(tmp);
	binpath = check_bin_in_path(path);
	if (!binpath)
    {
        free_tab(path, ft_strllen(path));
		return (NULL);
    }
  free_tab(path, ft_strllen(path));
  return(binpath);
}

char	*check_bin_in_path(char **path)
{
	char	*dup;
	int i;

	i = 0;
	while (*path)
	{
		if (access(*path, F_OK ) == 0)
		{
			dup = ft_strdup(*path);
			return (dup);
		}
		path++;
	}
	return (NULL);
}

t_cmd	fill_cmd(char **envp, char *arg)
{
    t_cmd   cmd;

	cmd.bin = check_and_find(arg, envp);
	cmd.args = ft_split(arg, ' ');
    return (cmd);
}