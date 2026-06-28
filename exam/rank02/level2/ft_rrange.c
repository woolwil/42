#include <stdlib.h>

int *ft_rrange(int start, int end)
{
    int current = end;
    int step = (start < end) ? -1 : 1;
    int i = 0;
    int size = abs(end - start) + 1;
    int *arr = malloc(sizeof(int) * size);

    while(i < size)
    {
        arr[i] = current;
        current += step;
        ++i;
    }
    return arr;
}

