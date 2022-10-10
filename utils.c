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
    ret = malloc(sizeof(char **) * size + 1);
    //ret[size - 1] == NULL;
    ft_bzero(ret, sizeof(char **) * size + 1);
    while (path[i])
    {
        //dprintf(2, "path[i] = %s\n", path[i]);
        ret[i] = ft_join_to_path(path[i], bin);
        i++ ;
    }
    //dprintf(2, "retsize = %s\n", ret[size]);
    return (ret);
}

int    ft_strllen(char **str)
{
    int len;
    int tmp;

    if (str == NULL)
        return (0);
    tmp = str;
    while (*str)
    {
        str++;
    }
	return (str - len);
}

void	free_tab(char **tab, int size)
{
    int i;

    i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void    close_fd_couple(int couple[2])
{
    close(couple[0]);
    close(couple[1]);
}