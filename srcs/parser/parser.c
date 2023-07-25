#include "../../include/minishell.h"


char	*cmd_path(char *str, t_ms *ms)
{
	char	**path_splited;
	char	*path_access;
	char	*command;

	path_splited = NULL;
	path_access = NULL;

	if (str)
	{
		command = str;
		command = ft_strjoin("/", str);
	}
	path_splited = ms->bin_path;
	path_access = join_path_cmd(path_splited, command);

	if (path_access == NULL)
		return (NULL);

	return (path_access);
}


void	tab_maker(t_token *curr_token, t_command *command)
{
    int i;
    t_token *tmp;
    
    tmp = curr_token;
    i = 0;
    while (tmp && tmp->type == TOKEN_CMD_FLAG)
    {
        tmp = tmp->next;
        i++;
    }
    command->tab_options = malloc((i + 2) * sizeof(char*));
    tmp = curr_token;
    
    command->tab_options[0] = command->cmd_path;
    i = 1;
    while (tmp && tmp->type == TOKEN_CMD_FLAG)//NOTE - si il ya des options pour la commande
    {
        command->tab_options[i] = tmp->contenue;
        tmp = tmp->next;
        i++;
    }
    command->tab_options[i] = NULL;
}

void    parser(t_ms *ms)
{
    t_command   *command;
    t_command   *tmp;
    t_token     *token;
    
    token = ms->token;
 while (token != NULL)
{
        if (token->type == TOKEN_CMD)
        {
            command = ((t_command *)malloc(sizeof(t_command)));
            command->cmd_path = cmd_path(token->contenue, ms);
            command->cmd_name = token->contenue;
            command->next = NULL;
            
            //TODO - si pas d option de commande quand meme remplir tab_options avec la commande de base en [0]
            
            if (token->next != NULL)
            {
                if (token->next->type == TOKEN_CMD_FLAG)
                    tab_maker(token->next, command);
                else
                    tab_maker(token, command);
            }
            else
                    tab_maker(token, command);
            if (ms->command == NULL)
                ms->command = command;
            else
            {
                tmp = ms->command;
                while (tmp->next != NULL)
                    tmp = tmp->next;
                tmp->next = command;
            }
        }
        if (token->type == TOKEN_BUILTINS)
        {
            call_builtins(token, ms);
        }
        token = token->next;
    }
    print_lst_command(ms);
}


void	print_lst_command(t_ms *ms)
{
	t_command *cur;
    int i = 0;

	cur = ms->command;

	while (cur)
	{
		printf("COMMAND = %s\n", cur->cmd_name);
        while (cur->tab_options[i])
        {
            printf("flag[%i] = %s\n",i, cur->tab_options[i]);
            i++;
        }
		cur = cur->next;
	}
    printf("\n");
}