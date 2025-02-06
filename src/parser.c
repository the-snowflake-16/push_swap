#include "push_swap.h"

int count_words(const char *s, char sep)
{
    int count = 0;
    int checker = 0;
    int i = 0;
    while(s[i])
    {
        if(sep!=s[i] && checker == 0)
        {
            count++;
            checker = 1;
        }
        else if (sep==s[i])
        {
            checker = 0;
        }
        i++;
    }
    return (count);
}

static char *get_next_word(const char *str, char separator) {
    static int cursor = 0;
    int len = 0, i = 0;
    char *next_str;

    while (str[cursor] == separator)
        ++cursor;
    while (str[cursor + len] && str[cursor + len] != separator)
        ++len;

    next_str = malloc((len + 1) * sizeof(char));
    if (!next_str)
        return NULL;
    
    while (i < len)
        next_str[i++] = str[cursor++];
    next_str[i] = '\0';

    return next_str;
}

char **ft_split(const char *str, char separator) {
    int words_number, i = 0;
    char **vector_strings;

    if (!str)
        return NULL;

    words_number = count_words(str, separator);
    vector_strings = malloc(sizeof(char *) * (words_number + 1));
    if (!vector_strings)
        return NULL;

    while (i < words_number) {
        vector_strings[i] = get_next_word(str, separator);
        if (!vector_strings[i]) {
            while (i > 0) free(vector_strings[--i]);
            free(vector_strings);
            return NULL;
        }
        i++;
    }
    vector_strings[i] = NULL;
    return vector_strings;
}

int	error_syntax(char *str_nbr)
{
	if (!(*str_nbr == '+'
			|| *str_nbr == '-'
			|| (*str_nbr >= '0' && *str_nbr <= '9')))
		return (1);
	if ((*str_nbr == '+'
			|| *str_nbr == '-')
		&& !(str_nbr[1] >= '0' && str_nbr[1] <= '9'))
		return (1);
	while (*++str_nbr)
	{
		if (!(*str_nbr >= '0' && *str_nbr <= '9'))
			return (1);
	}
	return (0);
}
static long	ft_atol(const char *str)
{
	long	num;
	int		isneg;
	int		i;

	num = 0;
	isneg = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * isneg);
}

void free_argv(char **argv)
{
    int i = 0;
    while(argv[i])
    {
        free(argv[i++]);
    }
    free(argv);
}
void	stack_init(char **argv, struct push_swap **a)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
        if(error_syntax(argv[i]))
        {
            free_argv(argv);
            free_list(*a);
            exit(EXIT_FAILURE);
        }
        
		nbr = ft_atol(argv[i]);
        if(!check_double(*a, nbr))
        {
            free_argv(argv);
            free_list(*a);
            exit(EXIT_FAILURE);
        }
        push_to_a(a, new_stract(nbr));

        // printf("%ld\n", nbr);
        i++;
	}
    free_argv(argv);
}

int ft_strlen(const char *s)
{
    int i = 0;
    while(s[i])
    {
        i++;
    }
    return (i);
}