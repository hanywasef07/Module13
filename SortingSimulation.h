#pragma once

class SortingSimulation
{
private:
    double* array;
    int size;

    void bubbleSort(double arr[], int n, bool ascending, int& swaps);
    // Recursive SelectionSort
    void selectionSort(double arr[], int n, bool ascending, int& swaps);
    // Recursive InsertionSort
    void insertionSort(double arr[], int n, bool ascending, int& swaps);
    // Recursive QuickSort
    void quickSort(double arr[], int low, int high, bool ascending, int& swaps);
    // Partition helper
    int partition(double arr[], int low, int high, bool ascending, int& swaps);
    // Recursive MergeSort
    void mergeSort(double arr[], int left, int right, bool ascending, int& swaps);
    // Merge helper
    void merge(double arr[], int left, int mid, int right, bool ascending, int& swaps);
    // HeapSort helper
    void heapify(double arr[], int n, int i, bool ascending, int& swaps);
    void heapSort(double arr[], int n, bool ascending, int& swaps);
    // Display array helper
    void displayArray(const double arr[], int n) const;
public:
    SortingSimulation();
    ~SortingSimulation();

    SortingSimulation(const SortingSimulation&) = delete;
    SortingSimulation& operator=(const SortingSimulation&) = delete;

    void createArray(int newSize);
    void displayUnsortedArray() const;

    bool isEmpty() const;

    // Sorting functions 
    void performBubbleSort(bool ascending);
    // Option D
    void performSelectionSort(bool ascending);
    // Option E
    void performInsertionSort(bool ascending);
    // Option F
    void performQuickSort(bool ascending);
    // Option G
    void performMergeSort(bool ascending);
    // Option H
    void performHeapSort(bool ascending);
};