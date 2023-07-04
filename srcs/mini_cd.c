#include "miniJoker.h"

int mini_cd(t_miniJoker *mini)
{
    char    *path;
    char    *str;


    if (!mini->tokens[1] || ft_strcmp(mini->tokens[1], "~", 0) == 0)
        chdir(getEnv(mini, "HOME"));
    else if (chdir(mini->tokens[1]) == -1)
    {
        path = getcwd(NULL, 0);
        str = ft_strjoin(path, "/");
        path = ft_strjoin(str, mini->tokens[1]);
        free(str);
        if (access(path, X_OK) == 0)
            printf("Executable file\n");
        else
            printf("Directory not found\n");
        free(path);
        return (EXIT_SUCCESS);
    }
    return (EXIT_SUCCESS);
}
