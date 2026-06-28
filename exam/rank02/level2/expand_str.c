#include <unistd.h>

int word_len(char *s)
{
    int len = 0;
    while(s[len] && s[len] != ' ' && s[len] != '\t')
        ++len;
    return len;
}

void expand_str(char *s)
{
    int first_word = 1;
    int len;

    while(*s)
    {
        while(*s == ' ' || *s == '\t')
            ++s;
        len = word_len(s);
        if(len > 0 && !first_word)
            write(1, "   ", 3);
        first_word = 0;
        write(1, s, len);
        s = s + len;
    }
}

int main(int ac, char **av)
{
    if(ac == 2)
        expand_str(av[1]);
    write(1, "\n", 1);
}