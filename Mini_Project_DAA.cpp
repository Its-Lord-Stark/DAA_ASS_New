// #include <iostream>
// #include <pthread.h>
// using namespace std;
// #define MAX 4
// #define MAX_THREAD 4

// int matA[MAX][MAX];
// int matB[MAX][MAX];
// int matC[MAX][MAX];
// int step_i = 0;

// void* multi(void* arg)
// {
// int i = step_i++;
// for (int j = 0; j < MAX; j++)
// for (int k = 0; k < MAX; k++)
// matC[i][j] += matA[i][k] * matB[k][j];
// }

// int main()
// {
// for (int i = 0; i < MAX; i++) {
// for (int j = 0; j < MAX; j++) {
// int x;
// int y;
// cout<<"Enter ["<<i<<"] ["<<j<<"] Value for matrix A";
// cin>>x;
// matA[i][j] = x;
// cout<<"Enter ["<<i<<"] ["<<j<<"] Value for matrix B";
// cin>>y;
// matB[i][j] = y;

// }
// }

// cout << endl
// << "Matrix A" << endl;
// for (int i = 0; i < MAX; i++) {
// for (int j = 0; j < MAX; j++)
// cout << matA[i][j] << " ";
// cout << endl;
// }

// cout << endl
// << "Matrix B" << endl;
// for (int i = 0; i < MAX; i++) {
// for (int j = 0; j < MAX; j++)
// cout << matB[i][j] << " ";
// cout << endl;
// }

// pthread_t threads[MAX_THREAD];

// for (int i = 0; i < MAX_THREAD; i++) {
// int* p;
// pthread_create(&threads[i], NULL, multi, (void*)(p));
// }

// for (int i = 0; i < MAX_THREAD; i++)
// pthread_join(threads[i], NULL);

// cout << endl
// << "Multiplication of A and B" << endl;
// for (int i = 0; i < MAX; i++) {
// for (int j = 0; j < MAX; j++)
// cout << matC[i][j] << " ";
// cout << endl;
// }
// return 0;
// }


#include <iostream>
#include <vector>

using namespace std;

int main() {
    int row1, col1, row2, col2;

    cout << "Enter the dimensions of the first matrix (row column): ";
    cin >> row1 >> col1;

    cout << "Enter the dimensions of the second matrix (row column): ";
    cin >> row2 >> col2;

    if (col1 != row2) {
        cout << "Matrix multiplication is not possible. The number of columns in the first matrix must equal the number of rows in the second matrix." << endl;
        return 1;
    }

    vector<vector<int>> matrix1(row1, vector<int>(col1));
    vector<vector<int>> matrix2(row2, vector<int>(col2));
    vector<vector<int>> result(row1, vector<int>(col2, 0));

    cout << "Enter elements of the first matrix:" << endl;
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            cin >> matrix1[i][j];
        }
    }

    cout << "Enter elements of the second matrix:" << endl;
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            cin >> matrix2[i][j];
        }
    }


    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            for (int k = 0; k < col1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    cout << "Result of matrix multiplication:" << endl;
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}