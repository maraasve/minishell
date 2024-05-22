/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:10:22 by maraasve          #+#    #+#             */
/*   Updated: 2024/05/22 17:50:10 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	is_token(char *str)
{
	if (ft_strcmp(str, "|") == 0 || ft_strcmp(str, "<") == 0
		|| ft_strcmp(str, ">") == 0 || ft_strcmp(str, "<<") == 0
			|| ft_strcmp(str, ">>") == 0)
		return (1);
	return (0);
}

t_lexer	*new_lexer(char *str)
{
	t_lexer	*new;

	new = (t_lexer *)malloc(sizeof(t_lexer));
	if (!new)
		return (NULL);
	new->str = str;
	new->token = 0;
	new->next = NULL;
	new->prev = NULL;
	if (is_token(str))
		new->token = 1;
	return (new);
}

t_lexer	*lexer_find_last(t_lexer **list)
{
	t_lexer	*tmp;

	tmp = *list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	lexer_add_back(t_lexer **list, t_lexer *new)
{
	t_lexer	*tmp;

	if (!new)
		return ;
	if (!list || !*list)
	{
		*list = new;
		return ;
	}
	tmp = lexer_find_last(list);
	tmp->next = new;
	new->prev = tmp;
}

void	lexer(char **str_arr)
{
	int		i;
	t_lexer	*new;
	t_lexer	*list;

	list = NULL;
	i = 0;
	while (str_arr[i])
	{
		new = new_lexer(str_arr[i]);
		if (!new)
		{
			free_lexer(&list);
		}
		lexer_add_back(&list, new);
		i++;
	}

	for (t_lexer *tmp = list; tmp != NULL; tmp = tmp->next)
		printf("%s - %i\n", tmp->str, tmp->token);
	
	free_lexer(&list);
}

int	main(int argc, char *argv[])
{
	char **str_arr;

	lexer(&argv[1]);
}
