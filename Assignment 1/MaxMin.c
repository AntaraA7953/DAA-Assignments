#include <stdio.h>
#include <limits.h>
#include<stdlib.h> 

// Recursive function to find min and max
void findMinMax(int arr[], int low, int high, int *min, int *max) {
    // If there is only one element
    if (low == high) {
        if (*min > arr[low]) *min = arr[low];
        if (*max < arr[low]) *max = arr[low];
        return;
    }

    // If there are two elements
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            if (*max < arr[low]) 
            *max = arr[low];
            if (*min > arr[high]) 
            *min = arr[high];
        } 
        else {
            if (*max < arr[high]) 
            *max = arr[high];
            if (*min > arr[low])
             *min = arr[low];
        }
        return;
    }

   
    int mid = (low + high) / 2;
    
    
    findMinMax(arr, low, mid, min, max);
    
   
    findMinMax(arr, mid + 1, high, min, max);
}


int main() {
    

    int n;
    printf("Enter the number of elements in the array:");
    scanf("%d",&n);
    int * A = (int *) malloc (n*sizeof(int));
    printf("Enter the elements of the array:");
    for(int i=0;i<n;i++)
    scanf("%d",(A+i));
    int min = INT_MAX, max = INT_MIN;

    findMinMax(A, 0, n - 1, &min, &max);

    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);

    return 0;
}
