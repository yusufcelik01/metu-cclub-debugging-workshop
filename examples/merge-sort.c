#include <stdio.h>
#include <stdlib.h>

void merge_sort(int* arr, size_t n);

int main()
{
    size_t n;
    scanf("%zu",&n); 
    
    int* arr = calloc(n, sizeof(int));
    for(size_t i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    merge_sort(arr, n);
    for(size_t i = 0; i < n; ++i)
    {
        printf(" %d" , arr[i]);
    }
    printf("\n");


    return 0;
}

void merge(int* arr, size_t n, size_t size_left)
{
    size_t size_right = n - size_left;
    int* left_arr = calloc(size_left, sizeof(int));
    int* right_arr = calloc(size_right, sizeof(int)); 

    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    for(i = 0; i < size_left; ++i)
    {
        left_arr[i] = arr[i];
    }
    for(j = 0; j < size_right; ++j)
    {
        right_arr[j] = arr[size_left + j];
    }

    i = 0;
    j = 0;
    k = 0;
    while(i < size_left && j < size_right)
    {
        if(left_arr[i] < right_arr[j]) 
        {
            arr[k] = left_arr[i];        
            ++i;
        }
        else
        {
            arr[k] = right_arr[j];
        }
        k++;
    }
    while(i < size_left)
    {
        arr[k] = left_arr[i];        
        ++i;
        ++k;
    }
    while(j < size_right)
    {
        arr[k] = right_arr[j];
        ++j;
        ++k;
    }


    free(left_arr);
    free(right_arr);
}

void merge_sort(int* arr, size_t n)
{
    if(n < 2) { return; }

    size_t mid = n/2;
    merge_sort(arr, mid);
    merge_sort(arr + mid, mid);

    merge(arr, n, mid);
}
