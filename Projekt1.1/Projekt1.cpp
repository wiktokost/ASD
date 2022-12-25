#include <iostream>
#include <stdio.h>

using namespace std;

int partition (int A[], int p, int r){
    int pivot = A[r];
    int smaller = p;
    int temp;
    for (int j = p; j <= r -1; j++) {
        if (A[j] <= pivot) {
            temp = A[smaller];
            A[smaller] = A[j];
            A[j] = temp;
            smaller = smaller + 1;
        }
    }
    temp = A[smaller];
    A[smaller] = A[r];
    A[r] = temp;

    return smaller;
}

void quicksort(int A[], int p, int r){
    if (p < r) {
        int q = partition(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q + 1, r);
    }
}

void maxHeapify(int A[], int array_size, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
        if (l < array_size && A[l] > A[largest])
            largest = l;

        if (r < array_size && A[r] > A[largest])
            largest = r;

        if (largest != i) {
            swap(A[i], A[largest]);
            maxHeapify(A, array_size, largest);
        }
}

void buildMaxHeap(int A[], int array_size){
    for (int i = array_size/2 - 1; i >= 0; i--) {
        maxHeapify(A, array_size, i);
    }
}

void heapSort(int A[], int array_size){
    buildMaxHeap(A, array_size);
    for (int i = array_size - 1; i >= 0; i--) {
        swap(A[0], A[i]);
        maxHeapify(A, i, 0);
    }
}

void insertionSort(int A[], int array_size){
    int key;
    int j;
    for (int i = 1; i < array_size; i++) {
        key=A[i];
        j = i-1;
        while (key < A[j] && j>= 0){
            A[j+1] = A[j];
            j = j-1;
        }
        A[j+1] = key;
    }
}

void randArray(int A[], int Asize){
    for (int i = 0; i < Asize; i++) {
        A[i] = rand()%10000;
        printf("%d ", A[i]);
    }
}

void printArray(int A[], int Asize){
    for (int i = 0; i < Asize; i++) {
        printf("%d ", A[i]);
    }
    cout<<"\n";
}

void printArraySortedByAllSorting(int A[], int Asize){
    cout<<"Sorted arrays By All Sorting:\n";
    cout<<"HeapSort: ";
    heapSort(A, Asize);
    printArray(A, Asize);
    cout<<"QS-Lomuto: ";
    quicksort(A, 0, Asize-1);
    printArray(A, Asize);
    cout<<"Insertion Sort: ";
    insertionSort(A, Asize);
    printArray(A, Asize);
}


int main() {
    srand(time(NULL));
    int array_size = 6;
    int A1[array_size];
    cout<<"RANDOM ARRAY:\n";
    randArray(A1, array_size);
    cout<<"\n";
    printArraySortedByAllSorting(A1, array_size);
}
