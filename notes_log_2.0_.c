/**
 * With love.
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
 * time_stamp - Gets the current local time.
 *
 * Return: A string of the current time.
 */
char *time_stamp()
{
	time_t t;

	time(&t);
	return (asctime(localtime(&t)));
}

/**
 * writetofile - Writes to a file.
 * @chee_ptr - Open stream associated with the file.
 */
void writetofile(FILE *chee_ptr)
{
	char *evb_buff	= NULL;
	size_t size	= 0;

	printf("---------- Enter note. End with newline ----------\n");
	if (getline(&evb_buff, &size, stdin)== -1)
	{
		perror("Can't read text");
		fclose(chee_ptr);
		free(evb_buff);
		exit(EXIT_FAILURE);
	}
	fprintf(chee_ptr, "%s %s\n", time_stamp(), evb_buff);
	free(evb_buff);
}

/**
 * main - Entry point of program.
 *
 * Description: Appends notes with current time and date to a file.
 * Return: 0 on success, 1 on failure.
 */
int main(void)
{
	FILE *chee_ptr;
	char *filename = "notes.log";

	if ((chee_ptr = fopen(filename, "a")) == NULL)
	{
		perror("Couldn't open file");
		exit(EXIT_FAILURE);
	}
	writetofile(chee_ptr);
	fclose(chee_ptr);

	return (0);
}

