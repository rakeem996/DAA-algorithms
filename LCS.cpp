#include <iostream>
#include <vector>
#include<math.h>
#include<string>

using namespace std;


int f(string s1 , string s2, int n, int m , vector<vector<int>> &dp)
{
    if(n < 0 || m < 0 ) return 0;

    if(dp[n][m] != -1) return dp[n][m];

    if(s1[n] == s2[m]) return dp[n][m] = 1 + f(s1 , s2, n-1 , m-1 , dp);

    return dp[n][m] = max(f(s1, s2, n-1, m, dp) , f(s1, s2, n, m-1 ,dp));
}


int LCS(string s1 , string s2)
{
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n , vector<int> (m,-1));
    return f(s1, s2, n-1 , m-1 , dp);
    // for(int i=0;i<n ;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}

int main()
{
    string s1 = "abbcd";
    string s2 = "bacd";
    cout<<LCS(s1,s2);
    return 0;
}