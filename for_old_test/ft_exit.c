#include "minishell.h"
// exit
// bash: exit: too many arguments
//если нет argv выходит с value = 0
//  если приходит строка возвращяет первое слово до пробел или число больше 19 знаков и выходит $? = 255
// bash: exit: adcbkk: numeric argument required
//  если подается одно число меньше 19 знаков, то в зависимости от знака возвращает от 0 до 255 (unsignet char)
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int ft_not_digit(char *str)
{
	int i;

	while (str[i])
	{
		if((str[i] < 33 && !ft_isdigit(str[i]) && str[i] == 127) || i < 19)
			return (0);
		i++;
	}
	return (1);	
}


int	ft_isalldigit(char *str)
{
	int	i;

	i = -1;
	if (str[0] == '-')
		i++;
	while (str[++i])
	{
		if (!ft_isdigit((unsigned char)str[i]) || ft_strlen(str) >= 19)
			return (1);
	}
	return (0);
}

int array_len(char **av)
{
	int i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

void ft_out(int value)
{
	//$? = value;
	printf("exit\n");
	exit(value); // возможно понадобиться делать через return
}

void ft_exit(char *av)
{
	char **str;
	int i;

	if(!av)
		ft_out(0);
	else
	{
		str = ft_strsplit(av, ' ');
		i = array_len(str);
		
	}
}