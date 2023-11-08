#include <iostream>
#include <vector>
#include <chrono> 

using namespace std;
long long fibbnocciSeries(int n)
{
    if (n <= 1) {
        return n;
    }
    long long a = 0, b = 1;
    for (int i = 2; i <= n; ++i) {
        long long temp = a;
        a = b;
        b = temp + b;
    }
    return b;
}


int main()
{
    int n;
    cout<<"Enter number"<<endl;
    cin>>n;


    auto start_time_nonrec = chrono::high_resolution_clock::now();
    int vect = fibbnocciSeries(n);
    auto end_time_nonrec = chrono::high_resolution_clock::now();
        cout<<"The non recursive fibbonacci "<<vect<<endl;
    chrono::duration<double> execution_time_nonrec = end_time_nonrec - start_time_nonrec;
    cout << "Execution Time: " << execution_time_nonrec.count() << " seconds" << endl;

}




// #include <iostream>
// #include <vector>
// #include <chrono> 

// using namespace std;


// int fibRec(int n)
// {
//     if(n<=1)
//         return n;
    
//     return fibRec(n-1)+fibRec(n-2);
// }





// int main()
// {
//     int n;
//     cout<<"Enter number"<<endl;
//     cin>>n;


//     auto start_time = chrono::high_resolution_clock::now();
//     int vec = fibRec(n);
//     auto end_time = chrono::high_resolution_clock::now();
//         cout<<"The recursive fibbonacci "<<vec<<endl;
//     chrono::duration<double> execution_time = end_time - start_time;
//     cout << "Execution Time: " << execution_time.count() << " seconds" << endl;


    // auto start_time_nonrec = chrono::high_resolution_clock::now();
    // int vect = fibbnocciSeries(n);
    // auto end_time_nonrec = chrono::high_resolution_clock::now();
    //     cout<<"The non recursive fibbonacci "<<vec<<endl;
    // chrono::duration<double> execution_time_nonrec = end_time - start_time;
    // cout << "Execution Time: " << execution_time.count() << " seconds" << endl;

        
// }