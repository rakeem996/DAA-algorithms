#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void floyddWarshall(vector<vector<int>> &matrix , int n)
{
    for(int i=0 ; i<n; i++)
    {
        for( int j =0; j<n; j++)
        {
            if(matrix[i][j] == -1) matrix[i][j] = 1e9;
        }
    }


    for(int k=0 ; k<n ; k++)
    {
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<n; j++)
            {
                matrix[i][j] = min(matrix[i][j] , matrix[i][k]+matrix[k][j]);
            }
        }
    }

    for(int i=0 ; i<n; i++)
    {
        if(matrix[i][i] < 0 )
        {
            cout<<"the matrix has a negative cycle"<<endl;
        }
    }

    for(int i=0 ; i<n; i++)
    {
        for( int j =0; j<n; j++)
        {
            if(matrix[i][j] == 1e9) matrix[i][j] = -1;
        }
    }

    for(int i=0 ; i<n; i++)
    {
        for( int j =0; j<n; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

}

int main()
{
    vector<vector<int>> matrix{{0, 2, -1, -1}, {1, 0, 3, -1}, {-1, -1, 0, -1}, {3, 5, 4, 0}};
    floyddWarshall(matrix ,4);
    return 0;
}