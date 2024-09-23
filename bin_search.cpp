#include <stdio.h>
#include <stdbool.h>

int bin_search (int arr[], int size, int required_elem);

const int SIZE = 6;

int main ()
{
    int result = 0;
    int arr[SIZE] = {1, 2 ,3, 5, 7, 9};

    result = bin_search (arr, 6, 14);

    printf ("result = %d", result);
}

int bin_search (int arr[], int size, int required_elem)
{
    int start = 0; //Передаю фактическое число элементов, но хочу чтобы последний элемент массива был arr[size]
    int end = --size;
    int mid = 0;

    while (true)
    {
        mid = (end - start + 1)/2 + start; // надеюсь, что так быстрее чем несколько раз вычислять выражение, но не уверен

        if (required_elem < arr[mid] && mid != end)
        {
            end = mid;
            printf ("required_elem < arr[mid] %d\n", mid);
            continue;
        }

        if (required_elem > arr[mid] && start <= end)
        {
            start = mid + 1;
            printf ("required_elem > arr[mid] %d\n", mid);
            continue;
        }

        if (arr[mid] == required_elem)
        {
            printf ("arr[mid] == required_elem\n");
            return mid + 1;
        }

        if (arr[mid-1] == required_elem)
        {
            return mid;
        }

        return 0;
    }
}
