#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft.h"

char *ft_strchr(const char *s, int c);
char    *ft_substr(char const *s, unsigned int start, size_t len);
void	ft_putendl_fd(char *s, int fd);
size_t  ft_strlen(const char *s);
int ft_strncmp(const char *s1, const char *s2, size_t n);
size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize);
char    *get_path(char *cmd, char **env);
char    *get_env_var(char *env_var, char **env);
char    *find_path(char *cmd, char **env);
void    execute_cmd(char *av, char **env);
int		get_next_line(char **line);
void    execute_cmd(char *av, char **env);
char    *ft_strdup(const char *s1);
char	*ft_strndup(const char *s, size_t n);
char	**ft_free(char **list);
size_t	ft_wordcount(char const *s, char c);
char	**ft_split(char const *s, char c);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strnstr(const char *haystack, const char *needle, size_t len);

#endif
