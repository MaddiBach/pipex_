#include "pipex.h"

bool	check_infile(char *filename)
{
	return(access(filename, R_OK));
}


bool	check_outfile(char *filename)
{
	return(access(filename, W_OK));

}

int		ft_open_if(char *in)
{
	int		ret;

	ret = open(in, S_IRUSR);
	if (ret == -1)
		handle_error();
	return (ret);
}

int		ft_open_of(char *out)
{
	int		ret;

	ret = open(out, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (ret == -1)
		handle_error();
	return (ret);
}


bool	cmd_in_workdir(char *cmd)
{
	return (access(cmd, F_OK | X_OK) == 0);
}