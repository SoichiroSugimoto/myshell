# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_list
{
	char	*value;
	char	*token_type;
	struct s_list	*next;
}	t_list;

t_list	*lstnew(char *value)
{
	t_list	*lst_new;

	lst_new = (t_list *)malloc(sizeof(t_list));
	lst_new->value = value;
	lst_new->next = NULL;
	return (lst_new);
}

void	lstadd_back(t_list **lst, t_list *new)
{
	while (*lst)
		lst = &((*lst)->next);
	*lst = new;
}

t_list *parse_argv(int argc, char **argv)
{
	t_list *list;
	t_list *token;

	for (int i=1;i<argc;i++)
	{
		token = lstnew(argv[i]);
		if (i == 1)
			list = token;
		if (i != 1)
			lstadd_back(&list, token);
	}
	return (list);
}

void	print_list(t_list *list)
{
	int i = 1;
	while(list != NULL)
	{
		printf("index : %i content : %s\n", i,list->value);
		list = list->next;
		i++;
	}
}

int main(int argc, char **argv)
{
	t_list *list;

	list = parse_argv(argc, argv);
	print_list(list);
}