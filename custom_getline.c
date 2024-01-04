#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream);

/**
 * custom_getline - Custom implementation of the getline function.
 * @lineptr: Pointer to the buffer storing the line.
 * @n: Pointer to the size of the buffer.
 * @stream: File stream to read from.
 *
 * Return: Number of characters read (including newline), or -1 on failure.
 */
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t buffer_size = 128;
	int c;
	size_t i = 0;

	char *temp;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		errno = EINVAL; /* Invalid argument */
		return (-1);
	}

	if (*lineptr == NULL)
	{
		*lineptr = (char *)malloc(buffer_size);
		if (*lineptr == NULL)
		{
			errno = ENOMEM; /* Memory allocation error */
			return (-1);
		}
	}

	while ((c = fgetc(stream)) != EOF)
	{
		if (i >= buffer_size - 1)
		{
			buffer_size *= 2;
			temp = (char *)realloc(*lineptr, buffer_size);
			if (temp == NULL)
			{
				free(*lineptr);
				*lineptr = NULL;
				errno = ENOMEM; /* Memory allocation error */
				return (-1);
			}
			*lineptr = temp;
		}

		(*lineptr)[i++] = (char)c;

		if (c == '\n')
		{
			break;
		}
	}

	if (i < buffer_size)
	{
		(*lineptr)[i] = '\0';
	}
	else
	{
		(*lineptr)[buffer_size - 1] = '\0';
	}

	if (n != NULL)
	{
		*n = i;
	}

	return ((ssize_t)i);
}
