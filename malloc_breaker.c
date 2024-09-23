#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main ()
{

    char x = 0;
    char *ptr = &x;

    unsigned long long max_size = 16535684920;
    while (true)
    {
        ptr = (char*) malloc (max_size);

        if (!ptr)
        {
            break;
        }
        printf ("Сейчас маллок выделил %llu байт памяти\n", max_size);

        free(ptr);
        max_size++;
    }

    printf ("Максимальное количество байт которое может выделить malloc == %llu!\n", --max_size);

//     for (int i = 0;)
//     {
//         ptr = (char*) calloc (,sizeof(char) );
//
//          if (!ptr)
//         {
//             break;
//         }
//         printf ("Сейчас каллок выделил %llu байт памяти\n", max_size);
//
//         free(ptr);
//         max_size++;
//     }
//
//     printf ("Максимальное количество байт которое может выделить calloc == %llu!\n", --max_size);

}
