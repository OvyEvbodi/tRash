#include "main.h"

/**
 * _realloc - reallocates a memory block using malloc and free
 *
 * @ptr: a pointer to the memory previously allocated
 * @old_size: the old size
 * @new_size: the new size
 * Return: a pointer to the space in memory
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *arr;
	char *new_ptr = ptr;
	unsigned int i = 0;

	if (new_size == old_size)
		return (new_ptr);
	if (new_size == 0 && new_ptr != NULL)
	{
		free(new_ptr);
		return (NULL);
	}
	else if (new_ptr == NULL)
	{
		free(new_ptr);
		arr = malloc(new_size);
		if (arr == NULL)
			return (NULL);
		return (arr);
	}
	arr = malloc(new_size);
	if (arr == NULL)
		return (NULL);
	/*initialize new array*/
	if (new_size > old_size)
	{
		for (; i < old_size; i++)
			arr[i] = new_ptr[i];
	}
	else
	{
		for (; i < new_size; i++)
			arr[i] = new_ptr[i];
	}
	free(new_ptr);
	return (arr);
}
