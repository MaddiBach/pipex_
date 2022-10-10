#include "pipex.h"

char    *ft_join_to_path(char *path, char *bin)
{
    char    *tmp;
    char    *ret;

    tmp = ft_strjoin(path, "/");
    ret = ft_strjoin(tmp, bin);
    free(tmp);
    return (ret);
}

char **ft_join_bin(char **path, char *bin)
{
    int     i;
    int     size;
    char    **ret;
    i = 0 ;
    size = ft_strllen(path);
    ret = malloc(sizeof(char **) * size);
    while (path[i])
    {
        ret[i] = ft_slash_join(path[i]);
        i++ ;
    }

    return (ret);
}

int    ft_strllen(char **str)
{
    int len;

    len = 0;
    while (str[len])
    {
        len++;
    }
		return (len);
}

void	free_tab(char **tab)
{
	while (*tab)
	{
		free(*tab);
		tab++;
	}
	free(tab);
}

void    close_fd_couple(int couple[2])
{
    close(couple[0]);
    close(couple[1]);
}