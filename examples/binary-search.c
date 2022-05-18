#include <stdio.h>
#include <stdlib.h>


int binary_search(int* arr, size_t n,  int val)
{
    size_t mid = n/2; 
    if( arr[mid] == val)
    {
        return 1;
    }
    else if( arr[mid] < val)
    {
        return binary_search(arr, mid, val);
    }
    else// arr[mid] > val
    {
        return binary_search(arr + mid, mid, val);
    }
}

int main()
{
    size_t n;
    int val;
    scanf("%zu",&n); 
    scanf("%d", &val);

    
    int* arr = calloc(n, sizeof(int));
    for(size_t i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    int contains = binary_search(arr, n, val);
    if(contains)
    {
        printf("array contains %d\n", val);
    }
    else
    {
        printf("array doesn't contain %d\n", val);
    }

    
    

}
