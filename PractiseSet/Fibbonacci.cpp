#include <iostream>
#include <vector>
#include <chrono> 

using namespace std;
// Non_Recursive:

int fibbnocciSeries(int n)
{
    vector<int> v;
    v.push_back(0);
    v.push_back(1);


    for(int i=2;i<=n;i++)
    {
        v.push_back(v[i-1]+v[i-2]);
    }

return v[n];
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


    auto start_time = chrono::high_resolution_clock::now();
    int vec = fibRec(n);
    auto end_time = chrono::high_resolution_clock::now();
        cout<<"The recursive fibbonacci "<<vec<<endl;
    chrono::duration<double> execution_time = end_time - start_time;
    cout << "Execution Time: " << execution_time.count() << " seconds" << endl;


    auto start_time_nonrec = chrono::high_resolution_clock::now();
    int vect = fibbnocciSeries(n);
    auto end_time_nonrec = chrono::high_resolution_clock::now();
        cout<<"The non recursive fibbonacci "<<vec<<endl;
    chrono::duration<double> execution_time_nonrec = end_time - start_time;
    cout << "Execution Time: " << execution_time.count() << " seconds" << endl;

        
}