#include "pipex.h"

int    main(int ac, char **av, char **envp)
{
    t_cmd cmd[2];
    int fd[2];
    int ret;

    ret = pipe(cmd[FIRST].pip);
    if (ret == -1)
    {
        perror("pipe fail");
    }
    cmd[FIRST] = fill_cmd(cmd[FIRST], envp, av[2]);
    cmd[SECOND] = fill_cmd(cmd[SECOND], envp, av[3]);
    printf("command :%s\n", cmd[FIRST].bin);
    fd[INFILE] = ft_open_if(av[1]);
    cmd[FIRST].pid = ft_exec(cmd[FIRST], envp, fd[INFILE], cmd[FIRST].pip[WRITE]);
    cmd[SECOND].pip[READ] = cmd[FIRST].pip[READ];
    fd[OUTFILE] = ft_open_of(av[4]);
    cmd[SECOND].pid = ft_exec(cmd[SECOND], envp, cmd[SECOND].pip[READ], fd[OUTFILE]);
    waitpid(cmd[FIRST].pid, NULL, 0);
    waitpid(cmd[FIRST].pid, NULL, 0);
    close_fd_couple(cmd[FIRST].pip);
    close_fd_couple(fd);
}