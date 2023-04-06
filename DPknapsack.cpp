#include <iostream>
using namespace std;

int knapSackRec(int W, int wt[], int val[], int i, int** dp)
{
    cout<<"entering the recursive loop with weight , values and index : "<<wt[i]<<" "<<val[i]<<" "<<i<<endl;
	if (i < 0)
        // cout<<"as out of bound returning 0"<<endl;
		return 0;
	if (dp[i][W] != -1)
        // cout<<"using memorization at "<<i<<","<<W<<endl;
		return dp[i][W];

	if (wt[i] > W) {

		// cout<<"as the value is not in dp then storing it at "<<i<<","<<W<<endl;
		dp[i][W] = knapSackRec(W, wt, val, i - 1, dp);
		return dp[i][W];
	}
	else {
		dp[i][W] = max(val[i]
						+ knapSackRec(W - wt[i], wt, val,
										i - 1, dp),
					knapSackRec(W, wt, val, i - 1, dp));

		return dp[i][W];
	}
}

int knapSack(int W, int wt[], int val[], int n)
{
	int** dp;
	dp = new int*[n];

	cout<<"creating a dynamic table for memorization and initializing to -1"<<endl;
	for (int i = 0; i < n; i++)
		dp[i] = new int[W + 1];


	for (int i = 0; i < n; i++)
		for (int j = 0; j < W + 1; j++)
			dp[i][j] = -1;
	return knapSackRec(W, wt, val, n - 1, dp);
}

int main()
{
	int profit[] = { 79, 72, 87, 40 , 75 };
	int weight[] = { 7, 7,8 , 4, 7 };
    for(int i=0; i<sizeof(profit) / sizeof(profit[0]); i++)
    {
        cout<<profit[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<sizeof(weight) / sizeof(weight[0]); i++)
    {
        cout<<weight[i]<<" ";
    }
    cout<<endl;
	int n = sizeof(profit) / sizeof(profit[0]);
	int W = 50;
	cout << knapSack(W, weight, profit, n);
	return 0;
}
