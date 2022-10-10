#include "pipex.h"

int main (int argc, char ** argv, char **envp) 
{
    int     i;
    int     fd[2];
    int     pd[2];
    pid_t   pid;

    i = 2;
    fd[INFILE] = ft_open_if(argv[1]);
    if (!fd[INFILE])
        ft_stdin_redir(fd[INFILE]);
    else
    {
        i = 3;
        pipe(pd);
    }




    while(i < argc - 2)
    {
        pipe(pd);
        pid = fork();
        if (!pid) 
        {
            ft_stdout_redir(pd[WRITE]);
            close_fd_couple(pd); 
            execve(check_and_find(argv[i], envp), ft_split(argv[i], ' '), envp);
            perror("exec");
        }
        dup2(pd[0], 0);
        close_fd_couple(pd);     
    }
    fd[OUTFILE] = ft_open_of(argv[argc - 1]);
    ft_stdin_redir(pd[READ]);
    ft_stdout_redir(fd[OUTFILE]);
    close_fd_couple(pd);
    close_fd_couple(fd);
    waitpid(-1, NULL, 0);
    execve(check_and_find(argv[i], envp), ft_split(argv[i], ' '), envp);
    perror("exec");
}