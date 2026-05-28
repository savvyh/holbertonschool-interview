#include <stdlib.h>
#include <string.h>

#include "substring.h"

/**
 * find_substring - finds all starting indices in s where a concatenation
 *                  of all words (each used exactly once) begins
 * @s: string to scan
 * @words: array of words (all same length)
 * @nb_words: number of words
 * @n: address to store the number of results
 *
 * Return: allocated array of indices, or NULL if none found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int word_len, total_len, s_len;
	int *result, *used;
	int count, i, j, k, found;

	*n = 0;
	if (!s || !words || nb_words <= 0 || !words[0])
		return (NULL);

	word_len = strlen(words[0]);
	if (word_len == 0)
		return (NULL);

	total_len = word_len * nb_words;
	s_len = strlen(s);

	if (s_len < total_len)
		return (NULL);

	result = malloc(sizeof(int) * (s_len - total_len + 1));
	if (!result)
		return (NULL);

	used = malloc(sizeof(int) * nb_words);
	if (!used)
	{
		free(result);
		return (NULL);
	}

	count = 0;
	for (i = 0; i <= s_len - total_len; i++)
	{
		memset(used, 0, sizeof(int) * nb_words);

		for (j = 0; j < nb_words; j++)
		{
			found = -1;
			for (k = 0; k < nb_words; k++)
			{
				if (!used[k] &&
					strncmp(s + i + j * word_len, words[k], word_len) == 0)
				{
					found = k;
					break;
				}
			}
			if (found == -1)
				break;
			used[found] = 1;
		}

		if (j == nb_words)
			result[count++] = i;
	}

	free(used);

	if (count == 0)
	{
		free(result);
		return (NULL);
	}

	*n = count;
	return (result);
}
