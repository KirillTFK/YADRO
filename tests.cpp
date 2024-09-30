#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "Yadro.h"


const int NUM_OF_TEST = 20;
FILE *fd;




enum ERRORS
{
    INDEFINITE_SIZE = 1,
    INCOMPLETE_INPUT,
    INCOMPLETE_REFERENCE,
    TEST_FAILED,
    NO_DATA,
    NO_SIZE,
    NO_D,
    NO_R,
    NO_REFERENCE
};

void check_test ()
{
    char test_pathname[TEST_NAME_SIZE] = "tests/test1";

    int last_elem = 0;

    while (!isdigit(test_pathname[last_elem]))
        last_elem++;

    for (int i = 1; i <= NUM_OF_TEST && i <= 9; i++)
    {
        test_pathname[last_elem] = '0' + i; //таким образом меняю имя теста.

        check_unittest (test_pathname, i);
    }

    for (int i = 10; i <= NUM_OF_TEST && i <= 99; i++)
    {
        test_pathname[last_elem] = '0' + i%10;
        test_pathname[last_elem+1] = '0' + (i-10*(i%10));
        check_unittest ( test_pathname, i);
    }
}


int check_open (FILE** f_ptr, const char *name, const char *mode)
{
    if ((*f_ptr = fopen(name, mode)) == NULL)
    {
        printf ("Не удалось найти тест\n");

        return 0;
    }

    return 1;
}


int read_test (int *size, int test_input[MAX_TEST_SIZE], FILE *test_fd, int test_reference[MAX_TEST_SIZE])
{
    int ch = 0;
    while (tolower((ch = getc(test_fd))) != 'e') // Считает до конца слова size
        //printf ("Ищу e\n");

    if (ch == EOF)
        return NO_SIZE;


      if(!fscanf (test_fd,"%d", size))          //После слова size читает число
          return INDEFINITE_SIZE;

    {
        char input[10] = {};
        while (tolower((ch = getc(test_fd))) != 'd')
        {
         //printf ("Ищу d\n");
        }
        if (ch == EOF)
            return NO_D;
        input[0] = ch;

        for (int i = 1;strcmp(input,"data") && i < 10; i++)
            input[i] = tolower(getc(test_fd));

        if (strcmp(input,"data"))
            return NO_DATA;
    }

    for (int i = 0; i < *size; i++ )
    {
        if(!fscanf(test_fd,"%d", &test_input[i]))
        {
            return INCOMPLETE_INPUT;
        }

    }


    while (tolower((ch = getc(test_fd))) != 'r');

    if (ch == EOF)
        return NO_R;
    char input [11] = {};
    input [0] = ch;

    for (int i = 1; strcmp(input, "reference") && i < 11; i++)
    {
        input[i] = tolower(getc(test_fd));
        //printf ("Я проверяю референс\n");
    }

    if (strcmp(input, "reference"))
        return NO_REFERENCE;

    for (int i = 0; i < *size; i++)
    {
        if (!fscanf(test_fd,"%d", &test_reference[i]))
        {
            return INCOMPLETE_REFERENCE;
        }
    }

    return 0;

}


void check_error (int test_num, int error)
{
    if (error == INDEFINITE_SIZE)
    {
        printf ("В тесте %d не смог определить размер массива входных данных\n", test_num);
        return;
    }

    if (error == INCOMPLETE_INPUT)
    {
        printf ("В тесте %d входной массив содержит меньше данных чем указано в size", test_num);
        return;
    }

    if (error == INCOMPLETE_REFERENCE)
    {
        printf ("В тесте %d эталонный массив содержит меньше данных чем указано в size", test_num);
        return;
    }

    if (error == NO_DATA)
    {
        printf ("Не нашел слово data\n");
        return;
    }

    if (error == NO_SIZE)
    {
        printf ("Не нашел слово size\n");
        return;
    }

    if (error == NO_D)
    {
        printf ("Не нашел букву D\n");
        return;
    }

    if (error == NO_R)
    {
        printf ("Не нашел букву R\n");
        return;
    }

    if (error == NO_REFERENCE)
    {
        printf ("Не нашел слово reference\n");
        return;
    }

    return;
}


void check_unittest (const char test_pathname[TEST_NAME_SIZE], const int test_num)
{

    //puts (test_pathname);

    if (!check_open (&fd, test_pathname,"r"))
        return;
                                        //На этом этапе имеем открытый тест в тесте будут лежать 1)размер массива 2)данные 3)ответ/эталон
    int test_input[MAX_TEST_SIZE] = {};
    int test_reference[MAX_TEST_SIZE] = {};
    int error = 0;
    int size = 0;

    error = read_test (&size, test_input, fd, test_reference);

    if (error)
    {
        check_error (test_num,error);
        return;
    }

    insertion_sort (size, test_input);

//     for (int i = 0 ; i < size; i++)
//         printf ("%d", test_input[i]);
//
//     for (int i = 0; i < size; i++)
//         printf ("%d", test_reference[i]);

    for (int j = 0; j < size; j++)
    {
        if (test_input[j] == test_reference[j])
            continue;
        else
        {
            printf ("Тест %d провален\n", test_num);
            error = TEST_FAILED;
            break;
        }

    }
    if (error != TEST_FAILED)
    {
        printf ("Тест %d успешно пройден\n", test_num);
    }
}
