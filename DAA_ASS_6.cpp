#include <iostream>
#include <vector>
using namespace std;

int partiton(vector<int> &arr, int low , int high)
{
    int pivot = arr[high];
    int j=low-1;

    for (int i = low; i <=high-1; i++)
    {
        if(arr[i]<pivot)
        {
            j++;
            swap(arr[j],arr[i]);
        }
    }

    swap(arr[j+1],arr[high]);
    return j+1;
    
}

void quickSort(vector<int> &v , int low , int high)
{
    if(low<high)
    {
    int p = partiton(v, low , high);
    quickSort(v,low,p-1);
    quickSort(v,p+1,high);
    }
}
int main()
{
    vector<int> v = {11,2,7,4,99,3};
    quickSort(v , 0 , v.size()-1);
    for(int x : v)
    {
        cout<< x<<" ";
    }
}