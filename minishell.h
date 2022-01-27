#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
//# include <readline/readline.h>
//# include <readline/history.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>
# include <sys/ioctl.h>
# include <termios.h>
//# include <curses.h>
//# include <term.h>

typedef struct s_envp t_envp;
typedef struct s_data t_data;
typedef struct s_sort t_sort;

struct node {
  int key;// имя envp->name
  struct node *left, *right;
};

struct s_sort
{
    t_envp *envp;
    
};

struct s_envp
{
    char *name;
    char *value;
    int key;
    int check_bit;
    struct s_envp *next;
    struct s_envp *prev;
};

struct s_data
{
    char *str;
    char **env;
};

void ft_echo(char *av, int flag);
char *getcwd(char *BUFFER, size_t SIZE);
char    **ft_strsplit(char const *s, char c);
char	*ft_strdup(char *src);
void push_back(char *name, char *value, t_envp *check);
t_envp *ft_lstnew(char *name, char *value);
size_t	ft_strnlen(const char *s, size_t maxlen);
size_t	ft_strlen(const char *str);
void	ft_lstclear(t_envp **lst);
void    ft_pwd(void);
int		ft_strcmp(const char *s1, const char *s2);
void    ft_cd(t_envp *envp);
void    swap_list(t_envp *list);
void    ft_export(t_envp *envp);
t_envp *struct_head (t_envp *envp);


#endif