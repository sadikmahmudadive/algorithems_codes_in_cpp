<<<<<<< HEAD
#include <iostream>

using namespace std;

int main()
{
    // Array of sorted integers
    int arr[100];
    int n;

    int target; // Element to search for
    int low = 0;   // Index of the lowmost element

    int foundIndex = 0; // Index where the target is found (-1 means not found)

    //for arry input
    cout << "Enter Array size : ";
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cout << "Enter array Elements " <<i <<": ";
        cin >> arr[i];
    }

    cout << "Enter the element you want to find : " ;
    cin >> target;

    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2; // Calculate the middle index

        if (arr[mid] == target)
        {
            foundIndex = mid;
            break; // Target found, exit the loop
        }
        else if (arr[mid] < target)
        {
            low = mid + 1; // Target is in the high half
        }
        else
        {
            high = mid - 1; // Target is in the low half
        }
    }

    if (foundIndex != 0)
    {
        cout << "Element " << target << " found at index " << foundIndex << endl;
    }
    else
    {
        cout << "Element " << target << " not found in the array." << endl;
    }
    
    return 0;
}
=======
#include <iostream>

using namespace std;

int main()
{
    // Array of sorted integers
    int arr[100];
    int n;

    int target; // Element to search for
    int low = 0;   // Index of the lowmost element

    int foundIndex = 0; // Index where the target is found (-1 means not found)

    //for arry input
    cout << "Enter Array size : ";
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cout << "Enter array Elements " <<i <<": ";
        cin >> arr[i];
    }

    cout << "Enter the element you want to find : " ;
    cin >> target;

    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2; // Calculate the middle index

        if (arr[mid] == target)
        {
            foundIndex = mid;
            break; // Target found, exit the loop
        }
        else if (arr[mid] < target)
        {
            low = mid + 1; // Target is in the high half
        }
        else
        {
            high = mid - 1; // Target is in the low half
        }
    }

    if (foundIndex != 0)
    {
        cout << "Element " << target << " found at index " << foundIndex << endl;
    }
    else
    {
        cout << "Element " << target << " not found in the array." << endl;
    }
    
    return 0;
}
>>>>>>> 59f02f6c7ef4248ba7d85964ef2a53455d58ad43
