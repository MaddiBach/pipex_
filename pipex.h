#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#define READ 0
#define WRITE 1
#define FIRST 0
#define SECOND 1
#define INFILE 0
#define OUTFILE 1

typedef struct s_cmd t_cmd;
struct  s_cmd
{
	char	*bin;
	char	**args;
    int     pip[2];
	pid_t   *pid;
};


bool	check_infile(char *filename);
bool	check_outfile(char *filename);
int		ft_open_if(char *in);
int		ft_open_of(char *out);
bool	cmd_in_workdir(char *cmd);
char	*check_and_find(char *cmd, char **envp);
char	**find_path(char **envp);
char	*is_in_path(char *cmd, char **envp);
char	*check_bin_in_path(char **path);
void	fill_cmd(t_cmd cmd,char *envp, char *arg);