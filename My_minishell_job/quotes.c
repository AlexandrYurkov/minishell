/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon <lfallon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:21:57 by dleaves           #+#    #+#             */
/*   Updated: 2022/03/20 20:17:18 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_unclosed_quotes(char *str, int *i, int c)
{
	int	quote_pair;

	quote_pair = 0;
	while (str[++(*i)])
	{
		if (str[*i] == c)
		{
			quote_pair++;
			break ;
		}
	}
	if (quote_pair == 0)
	{
		printf("minishell: error: unclosed quotes\n");
		return (1);
	}
	else
		return (0);
}

char	*ft_double_quotes(char *str, int *i, t_envp *envp)
{
	char	*str_new;
	int		start;

	start = *i;
	while (str[++(*i)])
	{
		if (str[*i] == '$')
		{
			str = ft_dollar(str, i, envp);
			if (!str)
				return (NULL);
		}
		if (str[*i] == '\"')
			break ;
	}
	str_new = cut_quotes(str, start, *i);
	if (!str_new)
		return (NULL);
	free(str);
	str = NULL;
	(*i) -= 2;
	return (str_new);
}

char	*ft_single_quotes(char *str, int *i)
{
	char	*str_new;
	int		start;

	start = *i;
	if (check_unclosed_quotes(str, &(*i), '\''))
		return (NULL);
	str_new = cut_quotes(str, start, *i);
	if (!str_new)
		return (NULL);
	free(str);
	str = NULL;
	(*i) -= 2;
	return (str_new);
}
