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
