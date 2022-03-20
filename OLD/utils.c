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

t_envp *search_name(t_envp *envp, char *name) // функция поиска по структуре envp
{
    t_envp *tmp_head;
    tmp_head = envp;
    int i = -1;

    while(tmp_head->next != NULL)
    {
        i = ft_strcmp(name, tmp_head->name);
        if(i == 0)            
            break;
       // printf("i = %d\n", i);
        tmp_head = tmp_head->next;
    }
    if (tmp_head->next == NULL)
        printf("not name, next-> NULL");//тоже подумать что должен выводить
    return (tmp_head);
}
 

void ft_cd(t_envp *envp) // добавить пременую команды, можно добавить сюда переменную о сообщении, или сделать их макросоми
{
    //t_envp *tmp;
    t_envp *pwd;
    t_envp *oldpwd;
    char *command = "../../"; //должна приходить из вне в виде строчки.
    pwd = envp;
    pwd = search_name(envp, "PWD");
    if(chdir(command) == 0)
    {
        oldpwd = search_name(envp, "OLDPWD");
        oldpwd->value = pwd->value;
        pwd->value = getcwd(NULL, 0); // возможно утечка, решение менять в самой структуре.
    }
     else
     {
         printf("cd: Нет такого файла или каталога: %s\n", command);//возможно стоит заменить на strerror(errno), STDERR_FILENO подробнее смотреть у вани static void	change_dir(char *new_path)
        // $? = 1;
        return ;
     }
    //free(pwd);
}
t_envp *ft_head(t_envp *list)
{
    while(list->prev)
        list = list->prev;
    return (list);
}

t_envp *max_p(t_envp *tmp, int sum)
{
    while(tmp->next || sum < 0)
        tmp = tmp->next;

    return (tmp);
}

void ft_export(t_envp *envp)
{
    t_envp *sort;
  
    sort = envp;
    swap_list(sort);
}

t_envp *ft_unset(t_envp *envp, char *name)
{
    t_envp *tmp;

    tmp = envp;
    tmp = search_name(tmp, name);

    // функция удаления листа

}