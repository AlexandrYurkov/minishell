#include "minishell.h"

t_envp *del_head(t_envp *envp)
{
    t_envp *tmp;

    tmp = envp;
    tmp->next->prev = NULL;
    envp = tmp;
    free(tmp);
}