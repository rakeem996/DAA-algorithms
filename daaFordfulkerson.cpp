#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

const int MAXN = 105;

int n, m, s1, s2, t, res, cap[MAXN][MAXN], flow[MAXN][MAXN], parent[MAXN];
bool visited[MAXN];

bool dfs(int u) {
    visited[u] = true;
    if (u == t) return true;
    for (int v = 1; v <= n; v++) {
        if (!visited[v] && cap[u][v] - flow[u][v] > 0) {
            parent[v] = u;
            if (dfs(v)) return true;
        }
    }
    return false;
}

int fordFulkerson() {
    while (true) {
        memset(visited, false, sizeof(visited));
        memset(parent, -1, sizeof(parent));
        if (!dfs(s1) && !dfs(s2)) break;
        int bottleneck = INT_MAX;
        for (int v = t; v != s1 && v != s2; v = parent[v]) {
            int u = parent[v];
            bottleneck = min(bottleneck, cap[u][v] - flow[u][v]);
        }
        cout << "Bottleneck capacity: " << bottleneck << endl;
        for (int v = t; v != s1 && v != s2; v = parent[v]) {
            int u = parent[v];
            flow[u][v] += bottleneck;
            flow[v][u] -= bottleneck;
        }
        cout << "Updated flow matrix:" << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << flow[i][j] << " ";
            }
            cout << endl;
        }
        res += bottleneck;
        cout << "Current max flow: " << res << endl;
    }
    return res;
}

int main() {
    cout<<"enter number of node , number of edges,  the two sources, the sink: "<<endl;
    cin >> n >> m >> s1 >> s2 >> t;
    cout<<"enter the value of capacity btw u , v as u-v-cap : "<<endl;
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        cap[u][v] += c;
        cap[v][u] += c;
    }
    cout << "Max flow: " << fordFulkerson() << endl;
    return 0;
}
