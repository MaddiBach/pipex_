#include "pipex.h"

int    main(int ac, char **av, char **envp)
{
    t_cmd first_cmd;
    t_cmd second_cmd;
    int fd[2];
    int pip[2];
    int ret;

    ret = pipe(pip);
    if (ret == -1)
    {
        perror("pipe fail");
    }
    first_cmd = fill_cmd(envp, av[2]);
    second_cmd = fill_cmd(envp, av[3]);
    ret = check_infile(av[1]);
   // if (ret == -1)
   // {
   //     perror("infile");
   //     return(0);
   // }
    fd[INFILE] = ft_open_if(av[1]);
    first_cmd.pid = ft_exec(first_cmd, envp, fd[INFILE], pip[WRITE]);
    fd[OUTFILE] = ft_open_of(av[4]);
    second_cmd.pid = ft_exec(second_cmd, envp, pip[READ], fd[OUTFILE]);
    waitpid(first_cmd.pid, NULL, 0);
    waitpid(second_cmd.pid, NULL, 0);
    close_fd_couple(pip);
    close_fd_couple(fd);
}