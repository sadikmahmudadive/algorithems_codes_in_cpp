#include<iostream>
using namespace std;
void Swap(int arr[], int s, int e)
{
    int temp=arr[s];
    arr[s]=arr[e];
    arr[e]=temp;
}
int Partition(int arr[], int s, int e)
{
    int pivot= arr[s];
    int i=s,j=e;
    while(i<j)
    {
       do
        {
            i++;
        }
        while(arr[i]<=pivot);
        do
        {
            j--;
        }
        while(arr[j]>pivot);
        if(i<j)
            Swap(arr,i,j);
    }
    Swap(arr,s,j);
    return j;
}
void quicksort(int arr[],int s, int e)
{
    if(s<e)
    {
        int pivot=Partition(arr,s,e);
        quicksort(arr,s,pivot);
        quicksort(arr,pivot+1,e);
    }
}
int main()
{
    int arr[]={3,5,2,6,4,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}