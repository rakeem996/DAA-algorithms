#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n ;i++)
    {
        cin>>arr[i];
    }

    int dp[n][n];
    for(int i =0 ;i<n ;i++)
    {
        dp[i][i] =0;
    }

    for(int l=2; l<n; l++)
    {
        for( int i=1; i<n-l+1 ;i++)
        {
            int j = i+l-1;
            
        }
    }
    return 0;
}