#include<iostream>

using namespace std;

void insertionSort(int arr[], int n)
{
    int i, mini, j;
    for (i = 1; i < n; i++)
    {
        mini = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > mini)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = mini;
    }
}

int median(int a[], int p)
{
    int i;
    int l;
    int k=(p-1)/2;
    cout<<"median: "<<a[k]<<endl;
    for(l=k; l<p; l++)
    {
        a[l]=a[l+1];
    }
    p--;
    return p;
}

int main()
{
    int i=0, j, k, l,p=1;
    int a[1000];
    int mini;
    int num;
    cout<<"Input Number: "<<endl;
    while(true)
    {
        cin>>num;

        if(num==0)
        {
            return 0;
        }
        else if(num==-1)
        {
            if(i==0)
            {
                cout<<"Invalid";
                return 0;
            }
            insertionSort(a,i);
            i=median(a,i);
        }
        else if(num>0)
        {
            a[i]=num;
            i++;
        }
    }
}


