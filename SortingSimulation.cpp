#include "SortingSimulation.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <utility>

using namespace std;


// Constructor
//precondition: none
//postcondition: initializes the array pointer to nullptr and size to 0, seeds the random number generator
SortingSimulation::SortingSimulation()
{
    array = nullptr;
    size = 0;

    srand(static_cast<unsigned int>(time(nullptr)));
}


// Destructor
//precondition: none
//postcondition: releases the memory allocated for the dynamic array and sets the pointer to nullptr
SortingSimulation::~SortingSimulation()
{
    delete[] array;
    array = nullptr;
}

// Option A - Create a dynamic array and fill with random elements
//precondition: none
//postcondition: creates a dynamic array of the specified size, fills it with random elements, and updates the size
void SortingSimulation::createArray(int newSize)
{
    // Create a larger dynamic array
    double* newArray = new double[size + newSize];

    // Copy existing elements
    for (int i = 0; i < size; i++)
    {
        newArray[i] = array[i];
    }

    // Add new random elements
    for (int i = size; i < size + newSize; i++)
    {
        newArray[i] = (rand() % 1000) / 10.0;
    }

    // Delete old array
    delete[] array;

    // Update array and size
    array = newArray;
    size += newSize;

    cout << "\n\t\tDynamic array's size of " << newSize << " has been created with random elements.\n";
}

// Check if the dynamic array is empty
//precondition: none
//postcondition: returns true if the dynamic array is empty, false otherwise
bool SortingSimulation::isEmpty() const
{
    return (array == nullptr || size == 0);
}

// Display array elements (15 elements per line)
//precondition: arr is a valid array of size n
//postcondition: displays the elements of the array with 15 elements per line
void SortingSimulation::displayArray(const double arr[], int n) const
{
    cout << "\n\t\t";

    for (int i = 0; i < n; i++)
    {
        cout << fixed << setprecision(1) << arr[i];

        if (i < n - 1)
        {
            if ((i + 1) % 15 == 0)
            {
                cout << "\n\t\t";
            }
            else
            {
                cout << ", ";
            }
        }
    }

    cout << "\n";
}

// Option B - Display the unsorted dynamic array
//precondition: the dynamic array is not empty
//postcondition: displays the elements of the unsorted dynamic array
void SortingSimulation::displayUnsortedArray() const
{
    if (isEmpty())
    {
        throw string("ERROR: The dynamic array is empty.");
    }

    cout << "\n\t\tUnsorted dynamic array:\n";

    displayArray(array, size);
}

// Recursive BubbleSort
//precondition: arr is a valid array of size n
//postcondition: sorts the array in ascending or descending order using recursive BubbleSort and counts the number of swaps
void SortingSimulation::bubbleSort(double arr[], int n, bool ascending, int& swaps)
{
    // Base case
    if (n <= 1)
    {
        return;
    }

    // Perform one pass of BubbleSort
    for (int i = 0; i < n - 1; i++)
    {
        if ((ascending && arr[i] > arr[i + 1]) || (!ascending && arr[i] < arr[i + 1]))
        {
            swap(arr[i], arr[i + 1]);
            swaps++;
        }
    }

    // Recursively sort the remaining elements
    bubbleSort(arr, n - 1, ascending, swaps);
}

// Option C - Perform BubbleSort
//precondition: the dynamic array is not empty
//postcondition: sorts the dynamic array in ascending or descending order using recursive BubbleSort and displays the sorted array along with the number of swaps
void SortingSimulation::performBubbleSort(bool ascending)
{
    if (array == nullptr || size == 0)
    {
        throw string("ERROR: The dynamic array is empty.");
    }
    // Create a copy of the original array
    double* temp = new double[size];
    for (int i = 0; i < size; i++)
    {
        temp[i] = array[i];
    }
    int swaps = 0;
    // Perform recursive BubbleSort
    bubbleSort(temp, size, ascending, swaps);

    // Display sorting order
    if (ascending)
    {
        cout << "\n\t\tAscending:\n";
    }
    else
    {
        cout << "\n\t\tDescending:\n";
    }
    cout << "\n\t\tnumber of swapping routines = " << swaps;
    cout << "\t\t";
    displayArray(temp, size);
    cout << "\n";
    // Release temporary memory
    delete[] temp;
}

// Recursive SelectionSort
//precondition: arr is a valid array of size n
//postcondition: sorts the array in ascending or descending order using recursive SelectionSort and counts the number of swaps
void SortingSimulation::selectionSort(double arr[], int n, bool ascending, int& swaps)
{
    // Base case
    if (n <= 1)
    {
        return;
    }
    int selectedIndex = 0;
    // Find the largest element for ascending order
    // or the smallest element for descending order
    for (int i = 1; i < n; i++)
    {
        if ((ascending && arr[i] > arr[selectedIndex]) || (!ascending && arr[i] < arr[selectedIndex]))
        {
            selectedIndex = i;
        }
    }

    // Place the selected element at the end
    if (selectedIndex != n - 1)
    {
        swap(arr[selectedIndex], arr[n - 1]);
        swaps++;
    }
    // Recursively sort the remaining elements
    selectionSort(arr, n - 1, ascending, swaps);
}

// Option D - Perform SelectionSort
//precondition: the dynamic array is not empty
//postcondition: sorts the dynamic array in ascending or descending order using recursive SelectionSort and displays the sorted array along with the number of swaps
void SortingSimulation::performSelectionSort(bool ascending)
{
    if (isEmpty())
    {
        throw string("ERROR: The dynamic array is empty.");
    }
    // Create a copy of the original array
    double* temp = new double[size];
    for (int i = 0; i < size; i++)
    {
        temp[i] = array[i];
    }
    int swaps = 0;
    // Perform recursive SelectionSort
    selectionSort(temp, size, ascending, swaps);
    // Display sorting order
    if (ascending)
    {
        cout << "\n\t\tAscending:\n";
    }
    else
    {
        cout << "\n\t\tDescending:\n";
    }
    cout << "\n\t\tnumber of swapping routines = " << swaps;
    cout << "\t\t";
    displayArray(temp, size);
    cout << "\n";
    // Release temporary memory
    delete[] temp;
}

// Recursive InsertionSort
//precondition: arr is a valid array of size n
//postcondition: sorts the array in ascending or descending order using recursive InsertionSort and counts the number of swaps
void SortingSimulation::insertionSort(double arr[], int n, bool ascending, int& swaps)
{
    // Base case
    if (n <= 1)
    {
        return;
    }

    // Recursively sort the first n - 1 elements
    insertionSort(arr, n - 1, ascending, swaps);

    // Insert the last element into its correct position
    int j = n - 1;

    while (j > 0 &&
        ((ascending && arr[j] < arr[j - 1]) || (!ascending && arr[j] > arr[j - 1])))
    {
        swap(arr[j], arr[j - 1]);
        swaps++;
        j--;
    }
}

// Option E - Perform InsertionSort
//precondition: the dynamic array is not empty
//postcondition: sorts the dynamic array in ascending or descending order using recursive InsertionSort and displays the sorted array along with the number of swaps
void SortingSimulation::performInsertionSort(bool ascending)
{
    if (isEmpty())
    {
        throw string("ERROR: The dynamic array is empty.");
    }
    // Create a temporary copy
    double* temp = new double[size];

    for (int i = 0; i < size; i++)
    {
        temp[i] = array[i];
    }
    int swaps = 0;
    // Perform recursive InsertionSort
    insertionSort(temp, size, ascending, swaps);
    // Display sorting order
    if (ascending)
    {
        cout << "\n\t\tAscending:\n";
    }
    else
    {
        cout << "\n\t\tDescending:\n";
    }
    cout << "\n\t\tnumber of swapping routines = " << swaps;
    cout << "\t\t";
    displayArray(temp, size);
    cout << "\n";
    // Release temporary memory
    delete[] temp;
}

// Partition helper for QuickSort
//precondition: arr is a valid array of size n, low and high are valid indices
//postcondition: partitions the array around a pivot and returns the index of the pivot, counts the number of swaps
int SortingSimulation::partition(double arr[], int low, int high,
    bool ascending, int& swaps)
{
    double pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if ((ascending && arr[j] < pivot) || (!ascending && arr[j] > pivot))
        {
            i++;

            if (i != j)
            {
                swap(arr[i], arr[j]);
                swaps++;
            }
        }
    }

    if (i + 1 != high)
    {
        swap(arr[i + 1], arr[high]);
        swaps++;
    }

    return i + 1;
}

// Recursive QuickSort
//precondition: arr is a valid array of size n, low and high are valid indices
//postcondition: sorts the array in ascending or descending order using recursive QuickSort and counts the number of swaps
void SortingSimulation::quickSort(double arr[], int low, int high, bool ascending, int& swaps)
{
    // Base case
    if (low >= high)
    {
        return;
    }

    // Partition the array
    int pivotIndex = partition(arr, low, high, ascending, swaps);

    // Recursively sort the left side
    quickSort(arr, low, pivotIndex - 1, ascending, swaps);

    // Recursively sort the right side
    quickSort(arr, pivotIndex + 1, high, ascending, swaps);
}

// Option F - Perform QuickSort
//precondition: the dynamic array is not empty
//postcondition: sorts the dynamic array in ascending or descending order using recursive QuickSort and displays the sorted array along with the number of swaps
void SortingSimulation::performQuickSort(bool ascending)
{
    if (isEmpty())
    {
        throw string("ERROR: The dynamic array is empty.");
    }
    // Create a temporary copy
    double* temp = new double[size];
    for (int i = 0; i < size; i++)
    {
        temp[i] = array[i];
    }
    int swaps = 0;
    // Perform recursive QuickSort
    quickSort(temp, 0, size - 1, ascending, swaps);
    // Display sorting order
    if (ascending)
    {
        cout << "\n\t\tAscending:\n";
    }
    else
    {
        cout << "\n\t\tDescending:\n";
    }
    cout << "\n\t\tnumber of swapping routines = " << swaps;
    cout << "\t\t";
	displayArray(temp, size);
    cout << "\n";

    // Release temporary memory
    delete[] temp;
}

// Merge helper for MergeSort
//precondition: arr is a valid array of size n, left, mid, and right are valid indices
//postcondition: merges two sorted subarrays into a single sorted array and counts the number of swaps
void SortingSimulation::merge(double arr[], int left, int mid, int right,
    bool ascending, int& swaps)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    // Create temporary arrays
    double* leftArray = new double[n1];
    double* rightArray = new double[n2];
    // Copy elements into temporary arrays
    for (int i = 0; i < n1; i++)
    {
        leftArray[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        rightArray[j] = arr[mid + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = left;
    // Merge the two sorted arrays
    while (i < n1 && j < n2)
    {
        if ((ascending && leftArray[i] <= rightArray[j]) || (!ascending && leftArray[i] >= rightArray[j]))
        {
            arr[k] = leftArray[i];
            i++;
        }
        else
        {
            arr[k] = rightArray[j];
            j++;
        }

        swaps++;
        k++;
    }
    // Copy remaining elements from leftArray
    while (i < n1)
    {
        arr[k] = leftArray[i];
        swaps++;
        i++;
        k++;
    }
    // Copy remaining elements from rightArray
    while (j < n2)
    {
        arr[k] = rightArray[j];
        swaps++;
        j++;
        k++;
    }
    // Release temporary memory
    delete[] leftArray;
    delete[] rightArray;
}

// Recursive MergeSort
//precondition: arr is a valid array of size n, left and right are valid indices
//postcondition: sorts the array in ascending or descending order using recursive MergeSort and counts the number of swaps
void SortingSimulation::mergeSort(double arr[], int left, int right,
    bool ascending, int& swaps)
{
    // Base case
    if (left >= right)
    {
        return;
    }
    // Find the middle
    int mid = left + (right - left) / 2;
    // Recursively sort the left half
    mergeSort(arr, left, mid, ascending, swaps);
    // Recursively sort the right half
    mergeSort(arr, mid + 1, right, ascending, swaps);
    // Merge the two sorted halves
    merge(arr, left, mid, right, ascending, swaps);
}

// Option G - Perform MergeSort
//precondition: the dynamic array is not empty
//postcondition: sorts the dynamic array in ascending or descending order using recursive MergeSort and displays the sorted array along with the number of swaps
void SortingSimulation::performMergeSort(bool ascending)
{
    if (isEmpty())
    {
        throw string("ERROR: The dynamic array is empty.");
    }
    // Create a temporary copy
    double* temp = new double[size];
    for (int i = 0; i < size; i++)
    {
        temp[i] = array[i];
    }
    int swaps = 0;
    // Perform recursive MergeSort
    mergeSort(temp, 0, size - 1, ascending, swaps);
    // Display sorting order
    if (ascending)
    {
        cout << "\n\t\tAscending:\n";
    }
    else
    {
        cout << "\n\t\tDescending:\n";
    }
    cout << "\n\t\tnumber of merging writes = " << swaps;
    cout << "\t\t";
    displayArray(temp, size);
    cout << "\n";

    // Release temporary memory
    delete[] temp;
}

// Heapify helper for HeapSort
//precondition: arr is a valid array of size n, i is a valid index
//postcondition: maintains the heap property for the subtree rooted at index i and counts the number of swaps
void SortingSimulation::heapify(double arr[], int n, int i, bool ascending, int& swaps)
{
    int selected = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    // Compare left child
    if (left < n)
    {
        if ((ascending && arr[left] > arr[selected]) || (!ascending && arr[left] < arr[selected]))
        {
            selected = left;
        }
    }
    // Compare right child
    if (right < n)
    {
        if ((ascending && arr[right] > arr[selected]) || (!ascending && arr[right] < arr[selected]))
        {
            selected = right;
        }
    }

    // Swap if necessary
    if (selected != i)
    {
        swap(arr[i], arr[selected]);
        swaps++;

        // Recursively heapify the affected subtree
        heapify(arr, n, selected, ascending, swaps);
    }
}

// HeapSort
//precondition: arr is a valid array of size n
//postcondition: sorts the array in ascending or descending order using HeapSort and counts the number of swaps
void SortingSimulation::heapSort(double arr[], int n, bool ascending, int& swaps)
{
    // Build the heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i, ascending, swaps);
    }

    // Extract elements from the heap
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        swaps++;

        // Restore heap property
        heapify(arr, i, 0, ascending, swaps);
    }
}

// Option H - Perform HeapSort
//precondition: the dynamic array is not empty
//postcondition: sorts the dynamic array in ascending or descending order using HeapSort and displays the sorted array along with the number of swaps
void SortingSimulation::performHeapSort(bool ascending)
{
    if (isEmpty())
    {
        throw string("ERROR: The dynamic array is empty.");
    }
    // Create a temporary copy
    double* temp = new double[size];
    for (int i = 0; i < size; i++)
    {
        temp[i] = array[i];
    }
    int swaps = 0;
    // Perform HeapSort
    heapSort(temp, size, ascending, swaps);

    // Display sorting order
    if (ascending)
    {
        cout << "\n\t\tAscending:\n";
    }
    else
    {
        cout << "\n\t\tDescending:\n";
    }
    cout << "\n\t\tnumber of swapping routines = " << swaps;
    cout << "\n\t\t";
	displayArray(temp, size);
    cout << "\n";
    // Release temporary memory
    delete[] temp;
}
