#include <stdlib.h>

int *ft_range(int start, int end)
{
    int *arr;
    int size;
    int i = 0;

    size = abs((end - start)) + 1;
    arr = malloc(sizeof(int) * size);
    if(start > end)
    {
        while(start >= end)
        {
            arr[i] = start;
            start -= 1;
            i++;
        }
    }
    else
        while(start <= end)
        {
            arr[i] = start;
            start += 1;
            i++;
        }
    return arr;
}