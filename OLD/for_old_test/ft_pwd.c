#include "minishell.h"

void ft_pwd(void) // передать струкруру в которой храниться история, и $?(сделать ее глабальной)
{
    char *tmp;
    tmp = getcwd(NULL, 0);
    if(!tmp)
    {
        printf("я сломался"); //временно не нашел как сломать pwd!)
        exit(1);
    }
    printf("\t%s\n", tmp);
    free(tmp);
}