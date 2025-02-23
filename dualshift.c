#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char *av[])
{
    if (ac != 2)
    {
        printf("you need to enter an argument\n");
        return (-1);
    }
     
    char *str;
    str = malloc((sizeof(char) * strlen(av[1]) + 1));
    if (!str)
    {
        printf("allocation failed\n");
        return -1;
    }
    
    int i = 0;
    while (av[1][i])
    {
        if ((av[1][i] <= 'z' && av[1][i] >= 'a'))
        {
            str[i] = 'a' + ('z' - av[1][i]);
        }
        else if (av[1][i] <= 'Z' && av[1][i] >= 'A')
        {
            str[i] = 'A' + ('Z' - av[1][i]);
        }
        else
            str[i] = av[1][i];
        i++;
    }
    str[i] = '\0';

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] <= 'z' && str[i] >= 'a')
        {
            str[i] = (str[i] - 'a' + 3) % 26 + 'a';
        }
        else if (str[i] <= 'Z' && str[i] >= 'A')
        {
            str[i] = (str[i] - 'A' + 3) % 26 + 'A';
        }
        i++;
    }
    str[i] = '\0';
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = (str[i] - 'a' + (3 + i % 5)) % 26 + 'a';
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = (str[i] - 'A' + (3 + i % 5)) % 26 + 'A';
        }
        i++;
    }

    printf("%s\n", str);
    free(str);
    return 0;
}
