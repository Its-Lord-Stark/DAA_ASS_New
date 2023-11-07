
#include<iostream>
#include<vector>
using namespace std;

void showNqueen(int n, vector<vector<int>> &v)
{
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

}


bool isSafe(vector<vector<int>> &mat,int row,int col,int n)
{
    for(int left=0;left<col;left++)
    {
        if(mat[row][left]==1)
            return false;
    }


    for(int i=row,j=col;i>=0 && j>=0; i--,j--)
    {
        if(mat[i][j]==1)
        return false;
    }

     for(int i=row,j=col;i<n && j>=0; i++,j--)
    {
        if(mat[i][j]==1)
        return false;
    }

    return true;


}


bool solveNQ(int n,vector<vector<int>> &mat, int col)
{
    if(col>=n)
        return true;

    for(int row=0;row<n;row++)
    {
        if(isSafe(mat,row,col,n))
        {
            mat[row][col]=1;
            
            if(solveNQ(n, mat, col+1))
                {
                    return true;
                }
            
            mat[row][col]=0;

        }
    }

    return false;

}




int main()
{
    int n;
    cout<<"Enter size of the matrix"<<endl;
    cin>>n;
    vector<vector<int>> mat(n,vector<int>(n,0));
    int givenRow;
    cout<<"Enter which queen to be placed in first colums enter the row number"<<endl;
    cin>>givenRow;

    mat[givenRow][0]=1;

    if(solveNQ(n,mat,1))
        showNqueen(n, mat);
    else
    {
        cout<<"No solution found"<<endl;
    }
    return 0;

}