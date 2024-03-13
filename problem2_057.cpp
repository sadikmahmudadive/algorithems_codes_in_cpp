<<<<<<< HEAD
#include <iostream>

using namespace std;

struct Item 
{
    int value;
    int weight;
};

double fractionalKnapsack(int W, Item arr[], int size) 
{
    for (int i = 0; i < size - 1; ++i) 
    {
        for (int j = 0; j < size - i - 1; ++j) 
        {
            if (arr[j].value * 1.0 / arr[j].weight < arr[j + 1].value * 1.0 / arr[j + 1].weight) 
            {
                Item temp = arr[j];

                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    double totalValue = 0.0;
    int remainingWeight = W;

    for (int i = 0; i < size; ++i) 
    {
        if (arr[i].weight <= remainingWeight) 
        {
            totalValue += arr[i].value;
            remainingWeight -= arr[i].weight;
        }
        else 
        {
            totalValue += (arr[i].value * 1.0 / arr[i].weight) * remainingWeight;
            break;
        }
    }

    return totalValue; 
}

int main() 
{
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int W = 50;
    int size = sizeof(arr) / sizeof(arr[0]);

    double maxValue = fractionalKnapsack(W, arr, size);

    cout << "Maximum possible value = " << maxValue << " by taking items of weight 10 and 20kg and 2/3 fraction of 30 kg. here total price will be 60+ 100+(2/3)(120)-24" << endl;

    return 0;
}
=======
#include <iostream>

using namespace std;

struct Item 
{
    int value;
    int weight;
};

double fractionalKnapsack(int W, Item arr[], int size) 
{
    for (int i = 0; i < size - 1; ++i) 
    {
        for (int j = 0; j < size - i - 1; ++j) 
        {
            if (arr[j].value * 1.0 / arr[j].weight < arr[j + 1].value * 1.0 / arr[j + 1].weight) 
            {
                Item temp = arr[j];

                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    double totalValue = 0.0;
    int remainingWeight = W;

    for (int i = 0; i < size; ++i) 
    {
        if (arr[i].weight <= remainingWeight) 
        {
            totalValue += arr[i].value;
            remainingWeight -= arr[i].weight;
        }
        else 
        {
            totalValue += (arr[i].value * 1.0 / arr[i].weight) * remainingWeight;
            break;
        }
    }

    return totalValue; 
}

int main() 
{
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int W = 50;
    int size = sizeof(arr) / sizeof(arr[0]);

    double maxValue = fractionalKnapsack(W, arr, size);

    cout << "Maximum possible value = " << maxValue << " by taking items of weight 10 and 20kg and 2/3 fraction of 30 kg. here total price will be 60+ 100+(2/3)(120)-24" << endl;

    return 0;
}
>>>>>>> 59f02f6c7ef4248ba7d85964ef2a53455d58ad43
