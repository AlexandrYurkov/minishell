#include "minishell.h"

int size_list(t_envp *envp)
{
    int size;

    size = 0;
    while (envp)
    {
        size++;
        envp = envp->next;
    }
    return (size);
}

char    *ft_strjoin2(char *s1, char *s2)
{
    char    *s3;
    int     i;
    int     j;
    if (!s1 || !s2)
        return (NULL);
    s3 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
    if (!s3)
        return (NULL);
    i = 0;
    j = 0;
    while (s1[i])
    {
        s3[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        s3[j + i] = s2[j];
        j++;
    }
    s3[j + i] = '\0';
    return (s3);
}

int ft_array_envp(t_envp *envp, t_data **data) //
{
    char *tmp;
    char *string;
    int i;

    tmp = ft_strdup("=");
    if((*data)->env)
        (*data)->env = malloc_free((*data)->env);
    (*data)->env = (char **)malloc((size_list(envp) + 1) * sizeof(char *));
    if (!(*data)->env)
		return (0);
    i = 0;
    while (envp)
    {
        string = ft_strjoin2(envp->name, tmp);
        (*data)->env[i] = ft_strjoin2(string, envp->value);
        free(string);
        i++;
        envp = envp->next;
    }
    (*data)->env[i] = NULL;
    free(tmp);
    return (1);
}