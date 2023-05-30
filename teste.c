#include <stdlib.h>
#include <stdio.h>

char *str_duplicate(const char *str);
int str_length(const char *str);
int str_compare(const char *stra, const char *strb);
int str_reverse(char *str);
int str_upper(char *str);
int str_lower(char *str);
int str_copy(char *dst, const char *src);
char *str_concatenate(const char *stra, const char *strb);
int str_find_first(const char *str, const char c);
int str_find_last(const char *str, const char c);
int str_count_words(const char *str);

#include "strlib.h"

int str_length(const char *str)
{
    int cont = 0;
    int i = 0;

    if (str == NULL)
        return -1;

    else
    {
        while (str[i] != '\0')
        {
            i++;
            cont++;
        }
    }
    return cont;
}

char *str_duplicate(const char *str)
{
    if (str == NULL)
        return NULL;
    char *copy = (char *)malloc((str_length(str)) * sizeof(char));

    int i;

    for (i = 0; i < str_length(str); i++)
    {
        copy[i] = str[i];
    }
    copy[i] = '\0';
    return copy;
}

int str_compare(const char *stra, const char *strb)
{
    if (stra == NULL || strb == NULL)
        return 666;

    else if (str_length(stra) < str_length(strb)) return -1;

    else if (str_length(stra) > str_length(strb)) return +1;

    int i = 0;
    while (stra[i] != '\0' && strb[i] != '\0')
    {
        if (stra[i] == strb[i])
        {
            i++;
        }
        else if (stra[i] != strb[i])
        {
            return 999;
        }
    }

    return 0;

}

int str_reverse(char *str)
{
    if (str == NULL) return 0;
    else{
    char reverse [str_length(str)];
    int i = 0;
    for (i = 0; i < str_length(str); i++)
        reverse[i] = str[str_length(str) - i - 1];

    reverse[i] = '\0';

    printf("%s\n", reverse);
    return 1;
    }
}

int str_upper(char *str)
{
    if (str == NULL)
        return -1;

    int cont = 0;
    int n = 0;
    char min[] = "abcdefghijklmnopqrstuvwxyz";
    char max[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    while (str[n] != '\0')
    {
        for (int l = 0; l < str_length(min); l++)
            if (str[n] == min[l])
            {
                str[n] = max[l];
                cont++;
            }
        n++;
    }

    return cont;
}

int str_lower(char *str)
{
    if (str == NULL)
        return -1;

    int cont = 0;
    int n = 0;
    char min[] = "abcdefghijklmnopqrstuvwxyz";
    char max[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    while (str[n] != '\0')
    {
        for (int l = 0; l < str_length(min); l++)
            if (str[n] == max[l])
            {
                str[n] = min[l];
                cont++;
            }
        n++;
    }

    return cont;
}

int str_copy(char *dst, const char *src)
{
    if (dst == NULL || src == NULL)
        return -1;

    else if (str_length(dst) < str_length(src))
        return 0;

    for (int i = 0; i <= str_length(src); i++)
    {
        dst[i] = src[i];
    }

    return 1;
}

char *str_concatenate(const char *stra, const char *strb)
{
    if (stra == NULL && strb == NULL) return NULL;

    else if (stra == NULL && strb != NULL)
    {
        char *concat = (char *)malloc((str_length(strb)) * sizeof(char));
        for (int i = 0; i <= str_length(strb); i++)
        {
            concat[i] = strb[i];
        }
        return concat;
    }

    else if (strb == NULL && stra != NULL)
    {
        char *concat = (char *)malloc((str_length(stra)) * sizeof(char));
        for (int i = 0; i <= str_length(stra); i++)
        {
            concat[i] = stra[i];
        }
        return concat;
    }

    else{
    char *concat = (char *)malloc(((str_length(stra) + str_length(strb))) * sizeof(char));

    int i = 0;

    while (stra[i] != '\0')
    {
        concat[i] = stra[i];
        i++;
    }

    int j = i;
    i = 0;
    while (strb[i] != '\0')
    {
        concat[j] = strb[i];
        i++;
        j++;
    }

    concat[j] = '\0';
    return concat;
    }
}

int str_find_first(const char *str, const char c)
{
    if (str == NULL)
        return -1;

    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] == c)
            return i;
        else
            i++;
    }

    return -1;
}

int str_find_last(const char *str, const char c)
{
    if (str == NULL)
        return -1;

    int ultimo = -1;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == c)
        {
            ultimo = i;
        }
    }

    if (ultimo != -1)
        return ultimo;
    else
        return -1;
}

int str_count_words(const char *str)
{
    if (str == NULL)
        return -1;

    int cont = 1;

    for (int i = 0; i < str_length(str); i++)
    {
        if (str[i] != ' ' && str[i + 1] == ' ')
            cont++;
            else if (str[i] == ' '&& str[i+1] == '\0')
            {
                cont --;
            }
    }

    return cont;
}

int main()
{
char frase[] = "programadora";
char aux[] = "programadoras";
int x = str_compare(frase,aux);
printf("%d\n",x);
return 0;
}