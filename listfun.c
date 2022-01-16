#include "minishell.h"

t_envp *ft_lstnew(char *name, char *value)
{
	t_envp *check;
	int i;

	if (!(check = (t_envp *)malloc(sizeof(t_envp))))
		return (NULL);
	check->value = value;
    check->name = name;
	check->key = 0;
	i = 0;
        while(i < 2)
            check->key = check->key + check->name[i++];
	check->prev = NULL;
	check->next = NULL;
	return (check);
}

void push_back(char *name, char *value, t_envp *check)
{
	t_envp *next_node;
	int i;

	if (!(next_node = (t_envp *)malloc(sizeof(t_envp))))
		return ;
	while (check->next)
    {
        check = check->next;
    }
	next_node->value = value;
    next_node->name = name;
	next_node->key = 0;
	i = 0;
        while(i < 2)
            next_node->key = next_node->key + next_node->name[i++];
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