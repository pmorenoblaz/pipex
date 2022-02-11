#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>

//Commands list
typedef struct s_comm_path
{
	char				**comm;
	struct s_comm_path	*next;
}	t_comm_path;

// List methods
void			ft_lstadd_back(t_comm_path **lst, t_comm_path *new);
t_comm_path		*ft_lstlast(t_comm_path *lst);
int				ft_lstsize(t_comm_path *lst);

// main.c
t_comm_path		**ft_accesslist(char **l_paths, char **argv, int argc);
char			*ft_envp_path(char **envp, int argc);
void			ft_check_path(char **l_paths, char *argv, t_comm_path **aux_l);
t_comm_path		**ft_accesslist(char **l_paths, char **argv, int argc);

// ft_first_command.c
void			ft_second_part(t_comm_path *act, int *fd1,
					char **argv, char **envp);
void			ft_first_pipe(t_comm_path *act, char **envp, char **argv);

// Libft methods
size_t			ft_strlen(const char *str);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strchr(const char *s, int c);
char			**ft_split(char const *s, char c);
char			*ft_strjoin(char const *s1, char const *s2);
void			*ft_memcpy(void *dst, const void *src, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif
