#ifndef PIPEX_H
# define PIPEX_H
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft/libft.h"

# define READ 0
# define WRITE 1
# define FIRST 0
# define SECOND 1
# define INFILE 0
# define OUTFILE 1

typedef struct s_cmd t_cmd;
struct  s_cmd
{
	char	*bin;
	char	**args;
    int     pip[2];
	pid_t   pid;
};

// parsing.c
bool	check_infile(char *filename);
bool	check_outfile(char *filename);
int		ft_open_if(char *in);
int		ft_open_of(char *out);
t_cmd	fill_cmd(char **envp, char *arg);

// files.c
bool	cmd_in_workdir(char *cmd);
char	*check_and_find(char *cmd, char **envp);
char	**find_path(char **envp);
char	*is_in_path(char *cmd, char **envp);
char	*check_bin_in_path(char **path);

// redirexec.c
pid_t   ft_exec(t_cmd cmd, char **envp, int in, int out);
void	ft_stdin_redir(int in);
void	ft_stdout_redir(int out);

// utils.c
char    *ft_join_to_path(char *path, char *bin);
char **ft_join_bin(char **path, char *bin);
int    ft_strllen(char **str);
void	free_tab(char **tab, int size);
void    close_fd_couple(int couple[2]);


#endif