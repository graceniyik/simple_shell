#include "shell.h"

/**
 **kiki - copies a string
 *@kweli: the destination string to be copied to
 *@kwendaaa: the source string
 *@kwiryaaa: the amount of characters to be copied
 *Return: the concatenated string
 */
char *kiki(char *kweli, char *kwendaaa, int kwiryaaa)
{
	int i, j;
	char *s = kweli;

	i = 0;
	while (kwendaaa[i] != '\0' && i < kwiryaaa - 1)
	{
		kweli[i] = kwendaaa[i];
		i++;
	}
	if (i < kwiryaaa)
	{
		j = i;
		while (j < kwiryaaa)
		{
			kweli[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **kwiryaaa - concatenates two strings
 *@kweli: the first string
 *@kwendaaa: the second string
 *@kwiryaaa: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *kwiryaaa(char *kweli, char *kwendaaa, int kwiryaaa)
{
	int i, j;
	char *s = kweli;

	i = 0;
	j = 0;
	while (kweli[i] != '\0')
		i++;
	while (kwendaaa[j] != '\0' && j < kwiryaaa)
	{
		kweli[i] = kwendaaa[j];
		i++;
		j++;
	}
	if (j < kwiryaaa)
		kweli[i] = '\0';
	return (s);
}

/**
 **kwibbaaa - locates a character in a string
 *@kweli: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *kwibbaaa(char *kweli, char c)
{
	do {
		if (*kweli == c)
			return (kweli);
	} while (*kweli++ != '\0');

	return (NULL);
}
