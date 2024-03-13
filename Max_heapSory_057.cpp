#include<iostream>

using namespace std;

void maxHeapify(int arr[], int n, int i)
{
    int root = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if (left < n && arr[left] > arr[root])
        root = left;
    else
        root = i;
    if (right < n && arr[right] > arr[root])
        root = right;
    if (root != i)
    {
        swap (arr[i], arr[root]);
        maxHeapify(arr , n, root);
    }
}

void buildMaxHeap(int arr[], int n)
{
    for(int i = n/2-1; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }
}

void heapSort(int arr[], int n)
{
    buildMaxHeap(arr, n);
    
    for (int i = n-1; i>0; i--)
    {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = {27, 17, 3, 4, 8, 9, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    heapSort(arr, n);
    cout << "Sorted array" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "" <<endl;
    }
    return 0;
}