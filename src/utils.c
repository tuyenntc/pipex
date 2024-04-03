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
			return (path);
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

/*
int	get_next_line(char **line)
{
	char 	*buffer;
	int		i;
	char	c;
	int		read_content;

	i = 0;
	read_content = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	read_content = read(0, &c, 1);
	while (read_content && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		read_content = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (read_content);
}


*/
