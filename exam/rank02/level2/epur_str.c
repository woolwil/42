#include <unistd.h>

int word_len(char *s)
{
    int len = 0;
    while(s[len] && s[len] != ' ' && s[len] != '\t')
        ++len;
    return len;
}

void epur_str(char *s)
{
    int len;
    int first_word = 1;

    while(*s)
    {
        while(*s == ' ' || *s == '\t')
            ++s;
        len = word_len(s);
        if(len > 0 && first_word == 0)
            write(1, " ", 1);
        first_word = 0;
        write(1, s, len);
        s = s + len;
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        epur_str(av[1]);
    }
    write(1, "\n", 1);
}