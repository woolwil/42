#include <stdlib.h>

int *ft_rrange(int start, int end)
{
    int *arr;
    int size;
    int i = 0;

    size = abs((end - start)) + 1;
    arr = malloc(sizeof(int) * size);

    if(!arr)
        return NULL;
        
    while(i < size)
    {
        arr[i] = end;
        if(start > end)
            end++;
        else
            end--;
        i++;
    }
    return arr;
}