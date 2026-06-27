#include <stdlib.h>

int absolute_value(int n);

int *ft_rrange(int start, int end)
{
    int nbr_ints;
    int *arr;
    int direction;
    int i;

    nbr_ints = 1 + absolute_value(end - start);
    arr = malloc(sizeof(int) * nbr_ints);

    if(start > end)
        direction = 1;
    else
        direction = -1;
    i = 0;
    while(i < nbr_ints)
    {
        arr[i] = end;
        end += direction;
        ++i;
    }
    return arr;
}