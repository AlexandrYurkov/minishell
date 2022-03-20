#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int array_len(char **av)
{
    int i;

    i = 0;
    while (av[i])
        i++;
    return (i);    
}


int main(int ac, char **av)
{
    int a = 45464646;
    int b = array_len(av);
    
    printf("i = %d, strerror = %s len = %d", (unsigned char)a, strerror(a), b);

    return (0);
}