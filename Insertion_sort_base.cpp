#include<iostream>
using namespace std;

void insertion_sort(int arr[], int size);

int main()
{
    int arr[] = {8, 2, 7, 4, 5, 1, 9, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    insertion_sort(arr, size);

    for(int i = 0; i < size; i++)
    {
        cout << "a[" << i << "] = " << arr[i] << endl;
    }
    return 0;
}

void insertion_sort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i]; //sorted part after cheacking
        int j = i-1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--; 
        }
        arr[j + 1] = key;
    }
}