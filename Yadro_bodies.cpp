#include <stdio.h>
#include <stdbool.h>

#include "Yadro.h"


int bin_search (int arr[], int size, int required_elem)
{
    int start = 0; //Передаю фактическое число элементов, но хочу чтобы последний элемент массива был arr[size]
    int end = --size;
    int mid = 0;

    while (true)
    {
        mid = (end - start + 1)/2 + start; // надеюсь, что так быстрее чем несколько раз вычислять выражение, но не уверен

        if (required_elem < arr[mid] && mid < end)
        {
            end = mid;
            //printf ("required_elem < arr[mid] %d\n", mid);
            continue;
        }

        if (required_elem > arr[mid] && start <= end)
        {
            start = mid + 1;
           // printf ("required_elem > arr[mid] %d\n", mid);
            continue;
        }

        if (arr[mid] == required_elem)
        {
            //printf ("arr[mid] == required_elem\n");
            //printf("Верну такое число: %d\n", mid+1);
            return mid + 1;
        }

        if (mid != 0 && arr[mid-1] == required_elem)
        {
           // printf("Верну такое число: %d\n", mid);
            return mid;
        }


        if (mid != 0 && arr[mid-1] > required_elem) //Случай когда нужно поставить новый элемент в массив из двух элементов
        {
            //printf("Верну такое число: %d\n", mid);
            return mid;
        }

        //printf("Верну такое число: %d\n", mid+1);
        return mid + 1; //показывает куда вставить новый элемент
    }
}

void insertion_sort (int size, int arr[] )
{
    int pos_of_new_elem = 0;
    int new_elem = 0;
    for (int sorted_size = 0; sorted_size < size - 1; sorted_size++)
    {
        new_elem = arr[sorted_size+1];
        pos_of_new_elem = bin_search (arr, sorted_size + 1, arr[sorted_size+1]);

        //printf ("%d \n",sorted_size + 1 - pos_of_new_elem + 1);
        insertion_copy (arr + pos_of_new_elem - 1,arr + pos_of_new_elem ,sorted_size + 1 - pos_of_new_elem + 1);
        arr[pos_of_new_elem - 1] = new_elem;

    for (int i = 0; i < size; i++)
    {
        //printf ("%d ", arr[i]);
    }
    //putchar ('\n');
    }
}

void insertion_copy (int *old_beginning, int *new_beginning, int num_elem_to_copy)
{

    if (num_elem_to_copy <= 0)
    {
        //printf ("Я в ошибке\n");
        return;
    }

    int count = num_elem_to_copy;
    while (true)
    {
        if (count - 2 >= 0 )
        {
            //printf ("Я зашел в лонги\n");
            *((long*)(new_beginning + count-2)) = *((long*)(old_beginning + count-2));
            //printf ("Итерация номер %d\n", count);
            count-=2;
        }
        else
        {
            //printf ("Я в else\n");
            if (count > 0)
            {
                new_beginning[count-1] = old_beginning[count-1];
                //printf ("дополнить последним интом\n");
            }
            return;
        }
    }
}
