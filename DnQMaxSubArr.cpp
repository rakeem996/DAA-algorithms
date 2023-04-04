#include <iostream>
#include <climits>
using namespace std;

class solution
{
    public:

    //---------------------function for finding the maximum between 2 and 3 varibles
        int max(int a, int b)
        {
            return (a>b) ? a : b;
        }

        int max(int a , int b , int c)
        {
            return max(max(a,b),c);
        }
    //------------------------------function for finding the max subarray sum at crossing 

        int maxCrossingSum(int arr[], int l, int m , int h)
        {

            //calculating the left side sum and the mid value with be the upper val eg: if 1.5 then mid=1
            int sum = 0;
            int leftSum = INT_MIN;

            for(int i=m ; i>=l ; i--)
            {
                sum += arr[i];
                if(sum > leftSum)
                {
                    leftSum = sum;
                }
            }

            //calculating the right side sum
            sum=0;
            int rightSum = INT_MIN;

            for(int i=m ; i<=h ; i++)
            {
                sum += arr[i];
                if(sum > rightSum)
                {
                    rightSum = sum;
                }
            }

            return max(leftSum+rightSum-arr[m] , leftSum , rightSum);
        }

        int maxSubArraySum(int arr[], int l, int h)
        {
            if(l>h) return INT_MIN;
            
            if(l==h) return arr[l];

            int m = (h+l)/2;

            return max(
                maxSubArraySum(arr, l, m-1),
                maxSubArraySum(arr , m+1 , h),
                maxCrossingSum(arr, l , m , h)
            );
        }
};

int main()
{
    int arr[] = { 2, 3, 4, 5, 7 };
    int n = sizeof(arr)/sizeof(arr[0]);
    solution obj;
    int max_sum = obj.maxSubArraySum(arr,0,n-1);
    cout<<"the maximum subarray sum is : "<<max_sum;
    return 0;
}