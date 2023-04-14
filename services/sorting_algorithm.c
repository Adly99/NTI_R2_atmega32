#include<stdio.h>


void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void doubleSort(double arr[], int n) 
{ // Define the function doubleSort that takes an array and its size as input
    int i, j; // Declare variables for the iteration indices
    for (i = 0; i < n-1; i++) 
    { // Iterate over each element in the array except the last one
        for (j = i+1; j < n; j++) 
        { // Iterate over each element from the start of the unsorted portion of the array to the end
            if (arr[i] > arr[j]) 
            { // If the current element is greater than the next element, swap them
                swap(&arr[i],&arr[j]);
            }
        }
    }
}

void selectionSort(int arr[], int n) 
{ // Define the function selectionSort that takes an array and its size as input
    int i, j, minIndex, temp; // Declare variables for the iteration indices, the current minimum index, and a temporary variable for swapping elements
    
    for (i = 0; i < n-1; i++) 
    { // Iterate over each element in the array except the last one
        
        minIndex = i; // Assume that the current element is the minimum
        
        for (j = i+1; j < n; j++) 
        { // Iterate over each remaining element in the array
            
            if (arr[j] < arr[minIndex]) 
            { // If an element is smaller than the current minimum, update the minimum index
                minIndex = j;
            }
        }
        
        if (minIndex != i) 
        { // If the minimum element is not already in the correct position, swap it with the current element
            swap(&arr[i],arr[minIndex]);
        }
    }
}

void insertionSort(int arr[], int n) 
{
    int i, key, j;

    /* The for loop runs through the unsorted portion of the array */
    for (i = 1; i < n; i++) {

        /* The key variable stores the value of the current element we are working with */
        key = arr[i];

        /* The j variable stores the index of the last element in the sorted portion of the array */
        j = i - 1;

        /* This while loop shifts the elements in the sorted portion of the array that are greater than the key to the right */
        while (j >= 0 && arr[j] > key) 
        {
            arr[j+1] = arr[j];
            j = j - 1;
        }

        /* The key is inserted into its correct position in the sorted portion of the array */
        arr[j+1] = key;
    }
}