#include "pipex.h"
#include <string.h>
/*
PATH=/nfs/homes/tunguyen/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
env
"/usr/bin/ls"
*/

char *ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
		if (*s == (char)c)
			return (char *)s;
		return (NULL);
}



char    *ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	size;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if(!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	size_t	len;

	len = ft_strlen(s);
	write(fd, s, len);
	write(fd, "\n", 1);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	
	if (!dstsize)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && (i < dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char    *ft_strdup(const char *s1)
{
	char	*new;
	int	i;

	i = 0;
	if (!(new = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	while (*s1)
		new[i++] = *s1++;
	new[i] = '\0';
	return (new);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*new;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, len1 + 1);
	ft_strlcpy(new + len1, s2, len1 + len2 + 1);
	return (new);
}


char    *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	j;

	if (*needle == '\0' || (!haystack && len == 0))
		return (char *)haystack;
	while (*haystack && len--)
	{
		j = 0;
		while (haystack[j] == needle[j] && needle[j] && j <= len)
		{
			if (!needle[j + 1])
				return (char *)haystack;
			j++;
		}
		haystack++;
	}
	return (NULL);
}

char	*ft_strndup(const char *s, size_t n)
{
	char *str;
	size_t	i;

	i = 0;
	if (n == 0)
		return (NULL);
	str = (char *)malloc(n + 1);
	if (!str)
		return (NULL);
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_free(char **list)
{
	size_t	i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
	return (NULL);
}

size_t	ft_wordcount(char const *s, char c)
{
	size_t	list_size;
	size_t	i;

	list_size = i = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c) || (s[i] == c && s[i + 1] != '\0' && s[i + 1] != c))
			list_size++;
		i++;
	}
	return (list_size);
}

char	**ft_split(char const *s, char c)
{
	char **str_list;
	size_t	i;
	size_t	k;
	size_t	save;

	i = k = 0;
	str_list = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!str_list)
		return (NULL);
	while (i < ft_wordcount(s, c) && s[k] != '\0')
	{
		while (s[k] == c)
			k++;
		save = k;
		while (s[k] != c && s[k] != '\0')
			k++;
		str_list[i] = ft_strndup(&s[save], k - save);
		if (str_list[i] == NULL)
			return (ft_free(str_list));
		i++;
	}
	str_list[i] = NULL;
	return (str_list);
}

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i = 0;
	while (n != '\0' && s1[i] && (s1[i] == s2[i]))
	{
		i++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return (*(unsigned char *)&s1[i] - *(unsigned char *)&s2[i]);
}


char	*find_path(char *cmd, char **env)
{
	char	**paths;
	char	*path;
	char	*part_path;
	int		i;

	while (ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

void	execute_cmd(char *av, char **env)
{
	char **cmd;
	char *path;
	int	i;

	i = -1;
	cmd = ft_split(av, ' ');
	path = find_path(cmd[0], env);
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		perror("no path found");
		exit(EXIT_FAILURE);
	}
	if (execve(path, cmd, env) == -1)
	{
		perror("error executing cmd");
		exit(EXIT_FAILURE);
	}
}

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

void	exec(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	path = find_path(s_cmd[0], env);
	if (execve(path, s_cmd, env) == -1)
	{
		write(2, "pipex: cmd not found: ", 22);
		ft_putendl_fd(s_cmd[0], 2);
		ft_free(s_cmd);
		exit(0);
	}
}
/*

char	*find_path(char *cmd, char **env)
{
	char	*path_value;
	char	*path_copy;
	char	*dir;
	char	*full_path;
	char	*exec_path;

	path_value = get_env("PATH", env);
	if (!path_value)
		return (cmd);
	path_copy = ft_strdup(path_value);
	if (!path_copy)
		return (cmd);
	dir = ft_split(path_copy, ":");
	while (dir != NULL)
	{
		full_path = ft_strjoin(dir, "/");
		exec_path = ft_strjoin(full_path, cmd);
		free(full_path);
		if (access(exec_path, F_OK | X_OK) == 0)
		{
			free(path_copy);
			return (exec_path);
		}
		free(exec_path);
		dir = ft_split(NULL, ":");
	}
	free(path_copy);
	return (cmd);
}

int main(void)
{
    char *env[] = {
        "PATH=/usr/bin:/bin",
        NULL
    };

    char *cmd1 = "ls";
    char *cmd2 = "nonexistent_cmd";
    char *cmd3 = "echo Hello";

    char *result1 = get_path(cmd1, env);
    char *result2 = get_path(cmd2, env);
    char *result3 = get_path(cmd3, env);

    printf("Result 1: %s\n", result1);
    printf("Result 2: %s\n", result2);
    printf("Result 3: %s\n", result3);

    return 0;
}
*/

char *get_env_var(char *env_var, char **env)
{
	char	*equal_sign;
	size_t	size;

	while (*env)
	{
		equal_sign = ft_strchr(*env, '=');
		if (!equal_sign || equal_sign == *env)
	
		{
			env++;
			continue;
		}
		size = equal_sign - (*env);
		if (ft_strncmp(*env, env_var, size) == 0)
			return (equal_sign + 1);
		env++;
	}
	return (NULL);
}
/*
int main(void)
{
    char *env[] = {
        "PATH=/usr/bin",
        "HOME=/user/home",
        "TERM=xterm-256color",
        NULL
    };
    char *result1 = get_env("PATH", env);
	char *result2 = get_env("HOME", env);
    char *result3 = get_env("SHELL", env);

    printf("PATH: %s\n", result1 ? result1 : "Not found");
    printf("HOME: %s\n", result2 ? result2 : "Not found");
    printf("SHELL: %s\n", result3 ? result3 : "Not found");

    return 0;
}


char	*my_getenv(char	*env_var, char **env)
{
	int	i, j;
	char	*sub;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		sub = ft_substr(env[i], 0, j);
		if (ft_strncmp(sub, env_var) == 0)
		{
			free(sub);
			return (env[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}
*/
char	*get_path(char *cmd, char **env)
{
	int i;
	char	*exec_path;
	char	*sub_path;
	char	**directories;
	char	**cmd_option;

	i = -1;
	directories = ft_split(get_env_var("PATH", env), ':');
	cmd_option = ft_split(cmd, ' ');
	while (directories[++i])
	{
		sub_path = ft_strjoin(directories[i], "/");
		exec_path = ft_strjoin(sub_path, cmd_option[0]);
		free(sub_path);
		if (access(exec_path, F_OK | X_OK) == 0)
		{
			ft_free(cmd_option);
			return (exec_path);
		}
		free(exec_path);
	}
	ft_free(directories);
	ft_free(cmd_option);
	return (cmd);
}
