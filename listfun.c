#include "minishell.h"

t_envp *init_key(t_envp *envp)
{
	int i;

	envp->check_bit = 0;
	envp->key = 0;
	i = 0;
	while (i < 1)
		envp->key = envp->key + envp->name[i++];
	i = 0;
	while(envp->name[i])
		envp->check_bit = envp->check_bit + envp->name[i++];
	return (envp);
}

t_envp *ft_lstnew(char *name, char *value)
{
	t_envp *check;

	if (!(check = (t_envp *)malloc(sizeof(t_envp))))
		return (NULL);
	check->value = value;
    check->name = name;
	check = init_key(check);
	check->prev = NULL;
	check->next = NULL;
	return (check);
}

void push_back(char *name, char *value, t_envp *check)
{
	t_envp *next_node;

	if (!(next_node = (t_envp *)malloc(sizeof(t_envp))))
		return ;
	while (check->next)
    {
        check = check->next;
    }
	next_node->value = value;
    next_node->name = name;
	next_node = init_key(next_node);
	next_node->prev = check;
	next_node->next = NULL;
	check->next = next_node;
	// return (next_node);
}

void	ft_lstclear(t_envp **lst)
{
	if (!lst || !*lst)
		return ;
	ft_lstclear(&(*lst)->next);
	free((*lst)->name);
	free((*lst)->value);
	free(*lst);
	*lst = NULL;
}