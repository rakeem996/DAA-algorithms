#include <iostream>
#include <vector>
 #include <climits>
using namespace std;
#define vi vector<int>
#define rep(i, a, b) for (int i = a; i < b; i++)

class Solution
{
public:
    int max(int n, int m)
    {
        if(n>m){
            return n;
        }
        else{
            return m;
        }
    }

    int maxSubArray(vi &nums)
    {
        int sum = 0;
        int maxi = INT_MIN;
        rep(i,0,nums.size())
        {
            cout<<" the sum at "<< i <<" is "<<sum<<" + "<<nums[i]<<endl;
            sum += nums[i];
            cout<<"that is : "<<sum<<endl;
            maxi = max(sum , maxi);
            if(sum < 0) sum=0;
        }
        return maxi;
    }
};

int main()
{
    vi a{-2 ,-3, 4, -1, -2 ,5 ,-3};
    cout<<"the array is: ";
    rep(i,0,a.size()){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    Solution obj;
    int maxSubArr = obj.maxSubArray(a);
    cout<<maxSubArr;
    return 0;
}