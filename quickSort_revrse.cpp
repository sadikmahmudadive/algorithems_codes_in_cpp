
#include<iostream>
using namespace std;

void Swap(int a[], int x, int y)
{
    int temp = a[x];
    a[x] = a[y];
    a[y]= temp;
}

int Partition(int a[], int low, int high )
{
    int pivot = a[high];
    int i =low, j = high;
    while(i<j)
    {
        while(a[i]<pivot)
        {
            i++;
        }
        while(a[j]>=pivot)
        {
            j--;
        }
        if(i<j)
        {
            Swap(a,i,j);
        }
    }
    Swap(a,high,i);
    return i;
}

void Quick_Sort(int a[], int low, int high)
{
    if(low<high)
    {
        int pivot = Partition(a,low, high);
        Quick_Sort(a, low, pivot-1);
        Quick_Sort(a, pivot,high);
    }
}
int main()
{
    cout<<"Array size: " <<endl;
    int n=0;
    cin>>n;
    int a[n+1];
    cout<<"Enter the ussorted array: "<<endl;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    a[0]=-10e5;
    Quick_Sort(a,0,n);

    cout<<"Sorted Array: ";
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}

