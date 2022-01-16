#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "minishell.h"

// typedef struct s_data
// {
//     char *str;
//     char **env;
// }   t_data;

void free_env(t_data *data)
{
    int i;

    i = 0;
    while (data->env[i])
        free(data->env[i++]);
    free(data->env);
}

t_envp *struct_head (t_envp *envp)
{
    t_envp *tmp;

    tmp = envp;
    while(tmp->prev)
        tmp = tmp->prev;
    envp = tmp;
    return (envp);
}

t_envp *init_t_envp(t_data *data, t_envp *envp)
{
    int i = -1;
    char **tmp;
   

    while (data->env[++i])
    {
        tmp = ft_strsplit(data->env[i], '=');
        // printf("%p\n", envp);
        if (envp == NULL)
            envp = ft_lstnew(tmp[0], tmp[1]);
        else
            push_back(tmp[0], tmp[1], envp);
           free(tmp);
    }
    return (envp);
}

int env_copy(t_data *data, char **env)
{
    int i;
    int j;

    i = 0;
    j = -1;
    while (env[i] != NULL)
        i++;
    data->env = (char **)malloc(sizeof(char *) * (i + 1));
    if (!data->env)
        return (1);
    while (env[++j] != NULL)
    {
        data->env[j] = strdup(env[j]);
        if (!data->env[j])
            return (1);
    }
    data->env[j] = NULL;
    return (0);
}

int main(int argc, char **argv, char **env)
{
    t_data *data;
    t_envp *envp;
    //t_sort *sort;
    int i = 0;
    (void)argc;
    (void)argv;

    data = malloc(sizeof(t_data));

    envp = NULL; 
    if (!data)
        exit(1);
    if (env_copy(data, env) == 1)
        return (1);
    if ((envp = init_t_envp(data, envp)) == 0)
    {
        printf("kkkzzz");
        exit(2);
    }
    ft_pwd();
    ft_cd(envp);
    while (envp)
    {
        printf("\t%d -- %s = %s\n", envp->key, envp->name, envp->value);
        envp = envp->next;
    }

    printf("%s\n", data->env[i]);
    //printf("%s=%s\n", envp->name, envp->value);

    free_env(data);
    ft_lstclear(&envp);
    //free(envp);
    free(data);
    return (0);
}