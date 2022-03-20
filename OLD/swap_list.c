#include "minishell.h"

// t_envp *ft_lstnew(int value)
// {
// 	t_envp *check;

// 	if (!(check = (t_envp *)malloc(sizeof(t_envp))))
// 		return (NULL);
// 	check->value = value;
// 	check->prev = NULL;
// 	check->next = NULL;
// 	return (check);
// }

// void push_back(int value, t_envp *check)
// {
// 	t_envp *next_node;

// 	if (!(next_node = (t_envp *)malloc(sizeof(t_envp))))
// 		return ;
// 	while (check->next)
//     {
//         check = check->next;
//     }
// 	next_node->value = value;
// 	next_node->prev = check;
// 	next_node->next = NULL;
// 	check->next = next_node;
// 	// return (next_node);
// }

// int		ft_strcmp(const char *s1, const char *s2)
// {
// 	const unsigned char *p1;
// 	const unsigned char *p2;

// 	p1 = (const unsigned char *)s1;
// 	p2 = (const unsigned char *)s2;
// 	while (*p1 && (*p1 == *p2))
// 	{
// 		++p1;
// 		++p2;
// 	}
// 	return (*p1 - *p2);
// }


// void swap_current_of_next_list(t_envp *list)
// {
//     t_envp *begin = list->prev;
//     t_envp *next = list->next;
//     t_envp *end = list->next->next;

//     begin->next = next;
//     next->next = list;
//     list->next = end;

//     end->prev = list;
//     list->prev = next;
//     next->prev = begin;
// }

// void swap_pred_end_list (t_envp *list) // list->next->next = NULL
// {
//     t_envp *begin = list->prev;
//     t_envp *next = list->next;
//     t_envp *begin_prev = list->prev->prev;
    
//     begin->prev = list;
//     list->prev = begin_prev;
//     next->prev = begin;
        
//     begin->next = next;
//     list->next = begin;
//     begin_prev->next = list;
// }
// void swap_end_list(t_envp *list) // list->next == null
// {
//     t_envp *begin = list->prev;
//     t_envp *begin_prev = list->prev->prev;

//     begin_prev->next = list;
//     list->next = begin;
//     begin->next = NULL;

//     list->prev = begin_prev;
//     begin->prev = list;
// }

// void swap_begin_of_next_list(t_envp *list) // swap 1 && 2 list (list->prev->prev == NULL)
// {
//     t_envp *begin = list->prev;
//     t_envp *next = list->next;
//     //t_envp *end = list->next->next; 

//     begin->next = next;
//     list->next = begin;

//     begin->prev = list;
//     next->prev = begin;
//     list->prev = NULL;
// }

// void swap_one_list(t_envp *list)
// {
//     t_envp *end = list->next->next;
//     t_envp *next = list->next;

//     next->next = list;
//     list->next = end;

//     list->prev = next;
//     end->prev = list;
//     next->prev = NULL;
// }

// void swap_list(t_envp *list)
// {
//     if(list->prev == NULL)
//         swap_one_list(list);
//    //else if(list->prev->prev == NULL)
//       // swap_begin_of_next_list(list);
//     else if(list->next == NULL)
//         swap_end_list(list);
//     else if(list->next->next == NULL)
//         swap_pred_end_list(list);
//     else
//         swap_current_of_next_list(list);
// }

// void ft_end_one(t_envp *tmp)
// {

// }

// int main()
// {
//     t_envp *sort;
//     int i = 1;
//     sort = malloc(sizeof(t_envp));
//     sort = NULL;
//     int j = -1;

//     while(i < 8)
//     {
//         if(sort == NULL)
//             sort = ft_lstnew(i);
//         else
//             push_back(i, sort);
//         //j = (j*(-1))*3;
//         i++;
//     }
//     t_envp *tmp = sort;
//     while (tmp)
//     {
//         printf("%d\n", tmp->value);
//         tmp = tmp->next;
//     }
//     tmp = sort;
//     while(tmp)
//     {
//         if (tmp->value == 1)
//         {
//             break;
//         }
//         tmp = tmp->next;
//     }
//     swap_list(tmp);

//     // gпрогнать значение 1 от начала списка до конца
  
//     printf("current_pointer_value: %d\n", tmp->value);
//     //swap_current_of_next_list(tmp);
//     while(tmp->prev)
//         tmp = tmp->prev;
//     sort = tmp;
//     while(sort)
//     {
//         printf("%d\n", sort->value);
//         sort = sort->next;
//     }
//     printf("_________________________\n");

//     //swap_begin_of_next_list(tmp->next);
//     while(tmp->prev)
//         tmp = tmp->prev;
//     sort = tmp;
//     while(sort)
//     {
//         printf("%d\n", sort->value);
//         sort = sort->next;
//     }
   
//     return (0);
// }