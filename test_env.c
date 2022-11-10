#include "main.h"

extern char **environ;

int main(void)
{
	char **env = environ;
	env_node *head = env_list(env);

	add_to_existing(&head, "NAME", "cheezaram");
	add_to_existing(&head, "OTHER_NAME", "dpmax");
	add_to_existing(&head, "OBSESSION", "superstar");
	add_to_existing(&head, "WORTH", "too_large_to_handle");
	replace_env_node(head, "WORTH", "immeasurable");
	delete_env_node(head, "NAME");
	for (env_node *temp = head; temp; temp = temp->next)
	{
		write(1, temp->name, _strlen(temp->name));
		write(1, temp->equals, 1);
		write(1, temp->value, _strlen(temp->value));
		write(1, "\n", 1);
	}

	free_env_list(head);
	return (0);
}

