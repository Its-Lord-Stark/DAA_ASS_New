#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


int knapSackDP(vector<int>&weights, vector<int>&profit,int n,int capacity)
{

    vector<vector<int>> k (n+1,vector<int>(capacity+1,0));

    for(int i=0;i<=n;i++)
    {
        for(int w=0;w<=capacity;w++)
        {
            if(i==0 || w==0)
                k[i][w]=0;
            else if (weights[i-1]<=w)
            {
                k[i][w] = max( profit[i-1]+k[i-1][w-weights[i-1]] ,k[i-1][w]);
            }

            else
            {
                k[i][w] = k[i-1][w];
            }

        }
    }

    return k[n][capacity];
}



int main()
{
    int n;
    cout<<"Enter number of elements"<<endl;
    cin>>n;

    int capacity;
    cout<<"Enter capacity"<<endl;
    cin>>capacity;

    vector<int> weights(n);
    vector<int> profit(n);

    for(int i=0;i<n;i++)
    {
        cout<<"Enter weight of "<<i<<" th element"<<endl;
        cin>>weights[i];


        cout<<"Enter profit of "<<i<<" th element"<<endl;
        cin>>profit[i];
    }

    cout<<"Max profit is "<<knapSackDP(weights,profit,n,capacity);

}

