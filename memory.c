#include <stdio.h>
#include <stdlib.h>

int global_var = 0;

int main ()
{
    char *ptr = "Я СТРОКОВЫЙ ЛИТЕРАЛ";

    int var = 0;
    static int static_var = 0;

    char *pt = calloc (10, sizeof(char));

    printf ("Адрес строкого литерала: %p\n", ptr);
    printf ("Адрес переменной на стеке: %p\n", &var);
    printf ("Адрес переменной в статической памяти: %p\n", &static_var);
    printf ("Адрес глобальной переменной : %p\n", &global_var);
    printf ("Адрес переменной в динамической памяти: %p\n", pt);

    free (pt);
}
