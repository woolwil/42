#include <unistd.h>

void str_capitalizer(char *c)
{
    while(*c)
    {
        while(*c && (*c == ' ' || *c == '\t'))
        {
            write(1, c, 1);
            ++c;
        }
        while(*c && *c != ' ' && *c != '\t')
        {
            if(*c >= 'a' && *c <= 'z' && (*(c + 1) == '\0' || *(c + 1) == ' ' || *(c + 1) == '\t'))
                *c -= 32;
            else if(*c >= 'A' && *c <= 'Z' && *(c + 1) != '\0' && *(c + 1) != ' ' && *(c + 1) != '\t')
                *c += 32;
            write(1, c, 1);
            ++c;
        }
    }
    write(1, "\n", 1);
}

int main(int ac, char **av)
{
    if(ac > 1)
    {
        int i = 1;
        while(i < ac)
        {
            str_capitalizer(av[i]);
            ++i;
        }
    }
    else
        write(1, "\n", 1);
}