#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

vector<int> bfsfunct(vector<vector<int>> adj[] , int v)
{
    vector<int> vis(v+1 ,0);
    vector<int> bfs;

    for(int i=0; i<v ;i++)
    {
        if(!vis[i])
        {
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                for(auto it: adj[node])
                {
                    if(!vis[it])
                    {
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
        }
    }
}