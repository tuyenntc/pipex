#include "pipex.h"



void child_process(char **av, int *fd, char **env);
void parent_process(char **av, int *fd, char **env);

int main(int ac, char **av, char **env)
{
	int fd[2];
	pid_t cpid;
	if (ac == 5)
	{
		if (pipe(fd) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
		cpid = fork();
		if (cpid == -1)
		{
			perror("fork child1");
			exit(EXIT_FAILURE);
		}
		else if (cpid == 0)
			child_process(av, fd, env);
		waitpid(cpid, NULL, 0);
		parent_process(av, fd, env);
	}	
	else
		perror("invalid");
	return (0);
}

void child_process(char **av, int *fd, char **env)
{
	int infile;
	infile = open(av[1], O_RDONLY, 0777);
	if (infile == -1)
	{
		perror("error opening infile");
		exit(EXIT_FAILURE);
	}
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	execute_cmd(av[2], env);
}

void parent_process(char **av, int *fd, char **env)
{
	int outfile;
	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
	{
		perror("error opening outfile");
		exit(EXIT_FAILURE);
	}
	dup2(outfile, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	execute_cmd(av[3], env);
}

//env: PATH=/usr/local/bin:/System/Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Users/tuyennguyen/.composer/vendor/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/local/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/appleinternal/bin:/Applications/XAMPP/xamppfiles/bin:/Users/tuyennguyen/Desktop/nand2tetris/tools
