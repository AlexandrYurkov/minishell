/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon <lfallon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 17:32:32 by dleaves           #+#    #+#             */
/*   Updated: 2022/03/20 19:35:45 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	prepars_syntax_errors(char *str)
{
	int	i;
	int	c;

	i = -1;
	c = 0;
	while (str[++i])
	{
		if (str[0] == '|')
		{
			printf("minishell: syntax error near unexpected token `|'\n");
			return (1);
		}
		else if (str[i] == '|' && str[i + 1] == '\0')
		{
			printf("minishell: error: no command after pipe\n");
			return (1);
		}
		else if ((str[i] == '>' || str[i] == '<') && str[i + 1] == '\0')
		{
			printf("minishell: syntax error near unexpected token `newline'\n");
			return (1);
		}
	}
	return (0);
}

int	char_count(char *str, int i, int c)
{
	int	count;

	count = 0;
	i++;
	if (str[i] == c)
	{
		while (str[i] == c)
		{
			count++;
			i++;
		}
	}
	return (count);
}

int	syntax_errors(char *str, int i)
{
	if (str[i] == '|')
	{
		if (char_count(str, i, '|') > 0
			|| (str[i + 1] == '>' || str[i + 1] == '<'))
		{
			g_data.exit_status = 258;
			printf("minishell: syntax error\n");
			return (1);
		}
	}
	return (0);
}

int	redir_syntax_errors(char *str, int i)
{
	if (str[i] == '>')
	{
		if (char_count(str, i, '>') >= 2 || (str[i + 1] == ' '
				&& (str[i + 2] == '>' || str[i + 2] == '<'))
			|| str[i + 1] == '|' || str[i + 1] == '<')
		{
			g_data.exit_status = 258;
			printf("minishell: syntax error\n");
			return (1);
		}
	}
	else if (str[i] == '<')
	{
		if (char_count(str, i, '<') >= 2 || (str[i + 1] == ' '
				&& (str[i + 2] == '>' || str[i + 2] == '<'))
			|| str[i + 1] == '|' || str[i + 1] == '>')
		{
			g_data.exit_status = 258;
			printf("minishell: syntax error\n");
			return (1);
		}
	}
	return (0);
}
