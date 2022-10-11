#include "pipex.h"

void	ft_stdout_redir(int out)
{
	int	ret;

	ret = dup2(out, STDOUT_FILENO);
	if (ret == -1)
		perror("stdout redir");
}

void	ft_stdin_redir(int in)
{
	int	ret;

	ret = dup2(in, STDIN_FILENO);
	if (ret == -1)
		perror("stdin redir");
}

pid_t   ft_exec(t_cmd cmd, char **envp, int in, int out)
{
    int execret;
    
    cmd.pid = fork();
    if (cmd.pid == 0)
    {
        ft_stdin_redir(in);
        ft_stdout_redir(out);
        close_fd_couple(cmd.pip);
        execret = execve(cmd.bin, cmd.args, envp);
        if (execret == -1)
        {
           perror("exec");
           exit(1);
        }
    }
    return (cmd.pid);
}