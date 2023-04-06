#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> prefix(string pattern , int n)
{
    vector<int> pi(n, 0);
    for(int i=1 ; i<n ; i++)
    {
        int j = pi[i-1];

        while(j>0 && pattern[j] != pattern[i])
        {
            j = pi[j-1];
        }
        if(pattern[j] == pattern[i]) j++;

        pi[i] = j;

    }
    return pi;  
}

int main()
{
    string pattern = "abc";
    int n = pattern.length();
    vector<int> res = prefix(pattern , n);
    string text = "dbcabc";
    int pos;
    int i(0) , j(0);
    while(i<text.size())
    {
        if(text[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j!=0)
            {
                j = res[j];
            }
            else{
                i++;
            }
        }
        if(j == pattern.size())
        {
            pos = i-pattern.size();
            break;
        }
    }
    cout<<pos;
    return 0;
}