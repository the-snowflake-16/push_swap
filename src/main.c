#include <stdio.h>
#include <string.h>
#include "push_swap.h"
char *str_concat(int argc, char *argv[])
{
    int i = 0;
    int j = 1;
    int n = 0;

    int total_lenght = 0;
    for (int i = 1; i < argc; i++)
    {
        total_lenght += ft_strlen(argv[i]);
        total_lenght++;
    }
    char *result =  malloc(sizeof(char) * (total_lenght+1));
    if (!result)
        return NULL;
    while (j < argc)
    {
        i = 0;
        while(argv[j][i])
        {
            result[n++] = argv[j][i++];
        }
        result[n++] = ' ';
        j++;
    }
    result[n] = '\0';
    return(result);
}

char *ft_strcpy(const char *src)
{
    if (!src)
        return NULL;

    char *dst = malloc(sizeof(char) * (strlen(src) + 1));
    if (!dst)
        return NULL;

    int i = 0;
    while (src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';

    return dst;
}
int main(int argc, char *argv[])
{
    struct push_swap *a = NULL;
    struct push_swap *b = NULL;
    char *string;
    char **ss = NULL;
    if (argc < 2 || (2 == argc && !argv[1][0])) {
        return (0);
    }
    if (argc > 2)
    {
        string = str_concat(argc, argv);
        ss = ft_split(string, ' ');
        free(string);
    }
    else
        ss = ft_split(argv[1], ' ');
    
    stack_init(ss, &a);
    if(len_stack(a) == 1)
    {
        free_list(a);
        return (0);        
    }
    if(stack_sorted(a))
    {
        free_list(a);
        return (0);
    }
    push_swap(&a, &b);

    if (len_stack(a) == 3)
        tiny_sort(&a);
    // print_list(a);
    free_list(a);
    return(0);
}

// int main(int argc, char *argv[])
// {
//     // struct push_swap *start_a;
//     char *string;

//     printf("%s\n", string);
//     // char **arr = extract_word(string);
//     // free(string);
//     // for(int i = 0; arr[i]; i++)
//     // {
//     //     printf("%s\n", arr[i]);
//     // }
//     // char **string = extract_word(argv[1]);
//     // int i = 0;
//     // while(string[i])
//     // {
//     //     printf("%s\n", string[i]);
//     //     i++;
//     // }
//     // free(string);
//     // print_list(start_a);
//     // free_list(start_a);
//     // printf("%s\n", argv[1]);
// }
// int main(int argc, char *argv[]) {

//     struct push_swap *start_a = NULL;
//     struct push_swap *start_b = NULL;

//     if (argc < 2 || (2 == argc && !argv[1][0])) {
//         printf("Usage: %s <numbers>\n", argv[0]);
//         return 1;
//     }
//     if(argc > 2)
//     {
//         str_concat(argc, argv);
//     }
//     atoj(&start_a, argv[1]);
//     if (len_stack(start_a ) < 2)
//     {
//         printf("ERROR less than 2 numbers\n");
//         return (0);
//     }
//     push_swap(&start_a, &start_b);
//     if(stack_sorted(start_a))
//     {
//         free_list(start_a);
//         return (0);
//     }
//     if (len_stack(start_a) == 3)
//         tiny_sort(&start_a);
//     free_list(start_a);
//     // free_list(start_b);
//     return 0;
// }
// // int main(int argc, char *argv[]) {
// //     struct push_swap *start_a = NULL;
// //     struct push_swap *start_b = NULL;

// //     if (argc < 2 || (argc == 2 && !argv[1][0])) {
// //         fprintf(stderr, "Error\n");
// //         exit(EXIT_FAILURE);
// //     }

// //     char *input_str = NULL;
// //     if (argc > 2) {
// //         input_str = str_concat(argc, argv);
// //     } else {
// //         input_str = argv[1];
// //     }

// //     atol(&start_a, input_str);
// //     if (len_stack(start_a) < 2) {
// //         // fprintf(stderr, "Error\n");
// //         if (argc > 2) {
// //             free(input_str);
// //         }
// //         free_list(start_a);
// //         exit(EXIT_FAILURE);
// //     }

// //     if (!stack_sorted(start_a)) {
// //         if (len_stack(start_a) == 3) {
// //             tiny_sort(&start_a);
// //         } else {
// //             push_swap(start_a, start_b);
// //         }
// //     }

// //     if (argc > 2) {
// //         free(input_str);
// //     }
// //     free_list(start_a);
// //     // free_list(start_b); // Uncomment if start_b is dynamically allocated

// //     return 0;
// // }