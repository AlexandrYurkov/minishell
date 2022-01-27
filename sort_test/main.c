#include <unistd.h>
#include <stdio.h>
int arr[7] = {10, 12, 4, 14, 3, 6, 1};

void swap(int *i, int *j)
{
    int g;
    g = *i;
    *i = *j;
    *j = g;
    
}

int main(void)
{
    
    int i, j, g;

    i = 0;
    while(i < 10) //пока существует
    {
        j = 0;//точка старта
        while(j < 6)//  указания места от куда идти
        {
            if (arr[j] > arr[j + 1])
              swap(&arr[j], &arr[j+1]);
            j++;
        }
        i++;//где остановислся
    }
    i = 0;
    while (i < 10)
        printf("%d ", arr[i++]);
    

    return (0);
}