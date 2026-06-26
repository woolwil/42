#include <unistd.h>

int wordlen(char *str)
{
    int len = 0;

    while(str[len] && str[len] != ' ' && str[len] != '\t')
        len++;
    return len;
}

void expand_str(char *str)
{
    int first_word = 1;
    int len;
    while(*str)
    {
        while(*str == ' ' || *str == '\t')
            ++str;
        len = wordlen(str);
        if(len > 0 && first_word == 0)
            write(1, "   ", 3);
        first_word = 0;
        write(1, str, len);
        str = str + len;
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
        expand_str(av[1]);
    write(1, "\n", 1);
}