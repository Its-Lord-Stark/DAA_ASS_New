#include <iostream>
#include <vector>
#include <chrono> 
// #include <valgrind/memcheck.h>
using namespace std;


// Non_Recursive:

vector<int> fibbnocciSeries(int n)
{
    vector<int> v;
    v.push_back(0);
    v.push_back(1);


    for(int i=2;i<=n;i++)
    {
        v.push_back(v[i-1]+v[i-2]);
    }

return v;
}

void printVector(vector<int> v)
{
    for(int i : v)
    {
        cout<<i<<" ";
    }
    cout<<endl;

}







//Recursive:

int fibRec(int n)
{
    if(n<=1)
        return n;
    
    return fibRec(n-1)+fibRec(n-2);
}


int main()
{
    int n;
    cout<<"Enter number"<<endl;
    cin>>n;

    int ans = fibRec(n);
    cout<<"The recursive fibbonacci "<<ans<<endl;

    vector<int> ansVec = fibbnocciSeries(n);
    cout<<"NonRecursive approach fibbonacci number is "<< ansVec[n];




    // auto start_time = chrono::high_resolution_clock::now();
    // int vec = fibRec(n);
    // auto end_time = chrono::high_resolution_clock::now();
    //     cout<<"The recursive fibbonacci "<<vec;
    // chrono::duration<double> execution_time = end_time - start_time;
    // cout << "Execution Time: " << execution_time.count() << " seconds" << endl;

        
}