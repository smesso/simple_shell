/**
 * _strlen - Returns the length of a string.
 * @s: Pointer to the string.
 * Return: Length of the string.
 */
size_t _strlen(char *s)
{
    size_t ch = 0;

    while (s && *(s + ch) != '\0')
    {
        ch++;
    }

    return ch;
}

/**
 * _strncmp - Compares two strings up to a specified number of characters.
 * @s1: First string.
 * @s2: Second string.
 * @n: Number of characters to compare.
 * Return: Difference in characters or 0 if equal.
 */
int _strncmp(char *s1, char *s2, size_t n)
{
    size_t i;

    for (i = 0; i < n && s1 && s2 && s1[i] != '\0' && s2[i] != '\0'; i++)
    {
        int diff = s1[i] - s2[i];

        if (diff != 0)
        {
            return diff;
        }
    }

    return 0;
}

/**
 * _strcmp - Compares two strings.
 * @s1: First string.
 * @s2: Second string.
 * Return: Difference in characters or 0 if equal.
 */
int _strcmp(char *s1, char *s2)
{
    return _strncmp(s1, s2, SIZE_MAX);
}

/**
 * _strcpy - Copies the string pointed to by src into dest.
 * @dest: Destination of the copy.
 * @src: Source of the copy.
 * Return: Pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
    if (!src || !dest)
    {
        return dest; // handle NULL pointers
    }

    size_t i = 0;

    while (src[i] != '\0')
    {
        dest[i] = src[i];
        ++i;
    }

    dest[i] = '\0';

    return dest;
}

