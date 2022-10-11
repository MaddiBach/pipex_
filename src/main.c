#include "pipex.h"

int main(int argc, char ** argv, char **envp) 
{
    int     i;
    int     j;
    int     fd[2];
    int     pd[2];
    pid_t   pid[argc - 2];
    if (argc < 5)
        return (0);
    i = 2;
    fd[INFILE] = ft_open_if(argv[1]);
    if (fd[INFILE] != -1)
    {
        dprintf(2, "fd = %i\n", fd[INFILE]);
        ft_stdin_redir(fd[INFILE]);
        close(fd[INFILE]);
    }
    else
    {
        i = 3;
        pipe(pd);
    }
    j = 0;
    while(i < argc - 1)
    {
        pipe(pd);
        dprintf(2, "readend = %i\n", pd[READ]);
        pid[j] = fork();
        if (!pid[j]) 
        {
            dprintf(2, "i = %i\n", i);
            if (i == argc -2)
            {
                fd[OUTFILE] = ft_open_of(argv[argc - 1]);
                ft_stdout_redir(fd[OUTFILE]);
                close(fd[OUTFILE]);
            }
            else
            {
                ft_stdout_redir(pd[WRITE]);
            }
            //close(pd[WRITE]);
            close_fd_couple(pd);
            char **args = ft_split(argv[i], ' ');
            dprintf(2, "arg = %s\n", args[0]);
            execve(check_and_find(argv[i], envp), args, envp);
            perror("exec");
        }
        ft_stdin_redir(pd[0]);
        close_fd_couple(pd);
        i++;
        j++;    
    }
    j = 0;
    while (pid[j])
    {
        waitpid(pid[j], NULL, 0);
        j++;
    }
}