#include "wolf3d.h"
# include <fcntl.h>
#include <stdio.h>

int     error_usage()
{
    ft_putendl("Usage: ./wolf3d map");
    exit(0);
}

int     error()
{
    ft_putendl("error");
    exit(0);
}

int read_map(int argc, char **argv, t_game *game)
{
    int fd;
    int result;
    char *file;
    char *store;
    char buff[5];

    ft_bzero(buff, 5);
    fd = 0;
    result = 0;
    game->map = NULL;
    if (argc != 2)
        error_usage();
    file = argv[1];
    fd = open(file, O_RDONLY);
    if (result < 0)
        error();
    while ((result = read(fd, buff, 1)) > 0)
    {
        if (game->map == NULL)
            game->map = ft_strdup(buff);
        else
            {
                store = ft_strjoin(game->map, buff);
                free(game->map);
                game->map = store;
            }
    }
    if (argc == 2)
        close(fd);
    check_map(game);
    return (0);
}

void    check_map(t_game *game)
{
    int i;

    i = 0;
    while (game->map && game->map[i])
    {
        if (!((game->map[i] >= '0' && game->map[i] <= '4')) || game->map[i] == '\n')
        {
            printf("Invalid map\n");
            return ;
        }
        i +=  2;
    }
}