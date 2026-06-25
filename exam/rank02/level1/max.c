int max(int *tab, unsigned int len)
{
    if(!tab)
        return 0;
    int tmp = 0;
    unsigned int i = 0;
    while (tab[i] && i < len)
    {
        if(tab[i] > tmp)
        {
            tmp = tab[i];
            i++;
        }
    }
    return tmp;
}