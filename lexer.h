#include <stdio.h>
#include <stdlib.h>

typedef struct s_lexer
{
	char			*str;
	int				token;
	struct s_lexer	*prev;
	struct s_lexer	*next;
} t_lexer;

enum e_types
{
	SPACES = 1,
	WORD,
	PIPE,
	REDIRECT,
	INPUT,
	TRUNC,
	HEREDOC,
};

void	free_arr(char **arr);
void	free_lexer(t_lexer	**list);
int		ft_strcmp(char *str1, char *str2);