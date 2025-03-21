#include <stdio.h>
#include <stdlib.h> // Include this for malloc() and free()

void bubbleSort(int arr[], int n) 
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++) 
    {
        for (j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j+1]) 
            {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() 
{
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Correct memory allocation
    int *arr = (int*)malloc(n * sizeof(int)); 
    if (arr == NULL) 
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n); // Function call to sort the elements

    // Display sorted elements
    printf("Sorted array elements are:\n"); 
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr); // Free allocated memory

    return 0; 
}
