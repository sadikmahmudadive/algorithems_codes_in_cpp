<<<<<<< HEAD
#include <iostream>

using namespace std;

struct Activity 
{
    int startTime;
    int finish;
    int index;
};

void printMaxActivities(Activity arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        for (int j = i + 1; j < size; j++) 
        {
            if (arr[i].finish > arr[j].finish) 
            {
                swap(arr[i], arr[j]);
            }
        }
    }

    int i = 0;
    cout << "(" << arr[i].startTime << "," << arr[i].finish << ") ";

    for (int j = 1; j < size; j++) 
    {
        if (arr[j].startTime >= arr[i].finish) 
        {
            cout << "(" << arr[j].startTime << "," << arr[j].finish << ") ";
            i = j;
        }
    }
}

int main() 
{
    int startTime[] = {5, 1, 3, 0, 5, 8};
    int finish[] = {9, 2, 4, 6, 7, 9};
    const int size = sizeof(startTime) / sizeof(startTime[0]);

    Activity arr[size];
    for (int i = 0; i < size; i++) 
    {
        arr[i].startTime = startTime[i];
        arr[i].finish = finish[i];
        arr[i].index = i + 1;
    }

    cout << "Output: ";
    printMaxActivities(arr, size);

    return 0;
}
=======
#include <iostream>

using namespace std;

struct Activity 
{
    int startTime;
    int finish;
    int index;
};

void printMaxActivities(Activity arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        for (int j = i + 1; j < size; j++) 
        {
            if (arr[i].finish > arr[j].finish) 
            {
                swap(arr[i], arr[j]);
            }
        }
    }

    int i = 0;
    cout << "(" << arr[i].startTime << "," << arr[i].finish << ") ";

    for (int j = 1; j < size; j++) 
    {
        if (arr[j].startTime >= arr[i].finish) 
        {
            cout << "(" << arr[j].startTime << "," << arr[j].finish << ") ";
            i = j;
        }
    }
}

int main() 
{
    int startTime[] = {5, 1, 3, 0, 5, 8};
    int finish[] = {9, 2, 4, 6, 7, 9};
    const int size = sizeof(startTime) / sizeof(startTime[0]);

    Activity arr[size];
    for (int i = 0; i < size; i++) 
    {
        arr[i].startTime = startTime[i];
        arr[i].finish = finish[i];
        arr[i].index = i + 1;
    }

    cout << "Output: ";
    printMaxActivities(arr, size);

    return 0;
}
>>>>>>> 59f02f6c7ef4248ba7d85964ef2a53455d58ad43
