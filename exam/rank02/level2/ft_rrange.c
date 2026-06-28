#include <stdlib.h>

int *ft_rrange(int start, int end)
{
    int *arr;
    int size;
    int i;
    int current;
    int step;

    size = abs(end - start) + 1;
    arr = malloc(sizeof(int) * size);

    if(!arr)
        return NULL;
        
    i = 0;
    current = end;
    step = (start < end) ? -1 : 1;
    while(i < size)
    {
        arr[i] = current;
        current += step;
        ++i;
    }
    return arr;
}