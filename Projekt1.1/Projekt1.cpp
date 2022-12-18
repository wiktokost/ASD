#include <iostream>

using namespace std;
int array_size;

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

void insertionSort(int A[]){
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
        A[i] = rand()%100;
        cout<<A[i]<<" ";
    }
}

void printArray(int A[], int Asize){
    for (int i = 0; i < Asize; i++) {
        cout<<A[i]<<" ";
    }
    cout<<"\n";
}

void printArraySortedByAllSorting(int A[], int Asize){
    cout<<"Sorted arrays By All Sorting:\n";
    cout<<"Insertion Sort: ";
    insertionSort(A);
    printArray(A, Asize);
    cout<<"QS-Lomuto: ";
    quicksort(A, 0, Asize-1);
    printArray(A, Asize);
}


int main() {
    srand(time(NULL));
    array_size = 6;
    int A1[array_size];
    cout<<"RANDOM ARRAY:\n";
    randArray(A1, array_size);
    cout<<"\n";
    printArraySortedByAllSorting(A1, array_size);
    int A2[] = {1, 2, 3, 4, 5, 6, 7, 14, 24, 55};
    int sizeA2 = sizeof(A2) / sizeof(A2[0]);
    cout<<"Sorted array:\n";
    printArray(A2, sizeA2);
    printArraySortedByAllSorting(A2, sizeA2);
    int A3[] = {15, 12, 10, 8, 5, 4, 2, 1};
    int sizeA3 = sizeof (A3) / sizeof(A3[0]);
    cout<<"Reverse sorted array:\n";
    printArray(A3, sizeA3);
    printArraySortedByAllSorting(A3, sizeA3);
}
