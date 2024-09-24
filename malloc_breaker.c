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

    for (unsigned long long i = 4822135990, j = 1; ; i +=j) // примерно 4822135990 получается, работа цикла прекращается не брэйком, а операционной системой работа всей программы.
                                                            // Смешное сообщение в терминале появляется, когда visual studio code крашится, буквально пишет "Убит"
    {
        ptr = (char*) calloc (i ,sizeof(char));

         if (!ptr)
        {
            break;
        }
        printf ("Сейчас каллок выделил %llu байт памяти\n", i);

        free(ptr);
        max_size++;
    }

}
