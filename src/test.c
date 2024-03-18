#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#include "pipex.h"

char	*find_path(char *cmd, char **env)
{
	char	**dirs;
	char	*path;
	char	*temp;
	int		i;

	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	dirs = ft_split(env[i] + 5, ':');
	i = 0;
	while (dirs[i])
	{
		temp = ft_strjoin(dirs[i], "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path, F_OK | X_OK) == 0)
		{
//			free(dirs[i];
//			free(dirs);
			return (path);
		}
		free(path);
		i++;
	}
	i = -1;
	while (dirs[++i])
		free(dirs[i]);
	free(dirs);
	return (0);
}

void	execute_cmd(char *cmd, char **env)
{
	char **cmd_args;
	char *path;
	int	i;

	i = -1;
	cmd_args = ft_split(cmd, ' ');
	path = find_path(cmd_args[0], env);
	if (!path)
	{
		while (cmd_args[++i])
			free(cmd_args[i]);
		free(cmd_args);
		perror("no path found");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (cmd_args[i] != NULL)
	{
		++i;
	}
	cmd_args[i] = NULL;
	printf("Path: %s\n", path);
	if (execve(path, cmd_args, env) == -1)
	{
		perror("error executing cmd");
		exit(EXIT_FAILURE);
	}
	while (cmd_args[++i])
		free(cmd_args[i]);
	free(cmd_args);
	free(path);
}

#include "pipex.h" // Include the necessary header file

int main(void)
{
    char *env[] = {
        "PATH=/usr/local/bin:/System/Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Users/tuyennguyen/.composer/vendor/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/local/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/appleinternal/bin:/Applications/XAMPP/xamppfiles/bin:/Users/tuyennguyen/Desktop/nand2tetris/tools",
		"SHELL=/bin/zsh",
		"HOME=/Users/tuyennguyen",
		"USER=tuyennguyen",
        NULL
    };

    // Test find_path function
    char *cmd_to_find = "ls";
    char *found_path = find_path(cmd_to_find, env);

	if (!found_path)
    {
        fprintf(stderr, "Error: Command '%s' not found in PATH.\n", cmd_to_find);
        return EXIT_FAILURE;
    }

    printf("Path for '%s': %s\n", cmd_to_find, found_path);

    // Test execute_cmd function
    char *cmd_to_execute = "ls -l";
    execute_cmd(cmd_to_execute, env);

    return 0;
}

