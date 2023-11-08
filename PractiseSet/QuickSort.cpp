#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int index=low;
    int pivot=high;

    for(int i=low;i<high;i++)
    {
        if(arr[i]<arr[pivot])
        {
            swap(arr[i], arr[index]);
            index++;
        }
    }
    swap(arr[index],arr[pivot]);
    return index;
}


int rand_part(vector<int> &arr,int low,int high)
{
    int n;
    n = rand();

    int pvt = low+n%(high-low+1);

    swap(arr[pvt],arr[high]);

    return partition(arr, low, high);

}

void printArray(vector<int> arr)
{
    for(int item:arr)
    {
        cout<<item<<" ";
    }
}

void quickSort(vector<int> &arr , int low, int high)
{
    int p_index;
    if(low<high)
    {
    // p_index = partition(arr,low,high);
    p_index = rand_part(arr, low, high);
    quickSort(arr, low, p_index-1);
    quickSort(arr, p_index+1, high);
    } 

}

int main()
{
    int n;
    cout<<"Enter the amount of numbers you want to sort"<<endl;
    cin>>n;
    vector<int> arr(n);

    for(int i=0;i<n;i++)
    {
        cout<<"Enter the elemnt "<<i<<": "<<endl;
        cin>>arr[i];
    }

    quickSort(arr,0,n-1);

    printArray(arr);

}