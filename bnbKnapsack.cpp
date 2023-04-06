#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Item
{
	float weight;
	int value;
};


struct Node
{
	int level, profit, bound;
	float weight;
};

bool cmp(Item a, Item b)
{
	double r1 = (double)a.value / a.weight;
	double r2 = (double)b.value / b.weight;
	return r1 > r2;
}

int bound(Node u, int n, int W, Item arr[])
{
	
	if (u.weight >= W)
		return 0;

	int profit_bound = u.profit;

	int j = u.level + 1;
	int totweight = u.weight;

	while ((j < n) && (totweight + arr[j].weight <= W))
	{
		totweight += arr[j].weight;
		profit_bound += arr[j].value;
		j++;
	}

	if (j < n)
		profit_bound += (W - totweight) * arr[j].value /
										arr[j].weight;

	return profit_bound;
}

int knapsack(int W, Item arr[], int n)
{
	cout<<"sorting Item on basis of value per unit weight"<<endl;
	sort(arr, arr + n, cmp);

	cout<<"make a queue for traversing the node"<<endl;
	queue<Node> Q;
	Node u, v;

	u.level = -1;
	u.profit = u.weight = 0;
	Q.push(u);

	cout<<"One by one extract an item from decision tree compute profit of all children of extracted item and keep saving maxProfit"<<endl;
	int maxProfit = 0;
	while (!Q.empty())
	{
		u = Q.front();
		cout<<"Dequeue a node at level : "<<u.level<<endl;
		Q.pop();

		if (u.level == -1){
            cout<<"as starting node assigning value 0"<<endl;
			v.level = 0;
            }
		if (u.level == n-1){
            cout<<"there is nothing on next level"<<endl;
			continue;
            }

		cout<<"Else if not last node, then increment level, and compute profit of children nodes."<<endl;
		v.level = u.level + 1;

		cout<<"Taking current level's item add current level's weight and value to node u's weight and value"<<endl;
		v.weight = u.weight + arr[v.level].weight;
		v.profit = u.profit + arr[v.level].value;

		cout<<"If cumulated weight is less than W and profit is greater than previous profit, update maxprofit"<<endl;
		if (v.weight <= W && v.profit > maxProfit)
			maxProfit = v.profit;

		cout<<"Get the upper bound on profit to decide whether to add v to Q or not."<<endl;
		v.bound = bound(v, n, W, arr);

		cout<<"If bound value is greater than profit, then only push into queue for further consideration"<<endl;
		if (v.bound > maxProfit)
			Q.push(v);

		cout<<"Do the same thing, but Without taking the item in knapsack"<<endl;
		v.weight = u.weight;
		v.profit = u.profit;
		v.bound = bound(v, n, W, arr);
		if (v.bound > maxProfit)
			Q.push(v);
	}

	return maxProfit;
}

int main()
{
	int W = 10;
	Item arr[] = {{7, 79}, {7, 72}, {8, 87},
				{4, 40}, {7, 75}};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Maximum possible profit = "
		<< knapsack(W, arr, n);

	return 0;
}
