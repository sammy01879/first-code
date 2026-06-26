
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {

    vector<pair<int, int>> adj[n + 1];

    // Build Graph
    for (int i = 0; i < times.size(); i++) {
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];

        adj[u].push_back({v, w});
    }

    // Distance Array
    vector<int> dist(n + 1, INT_MAX);

    // Min Heap
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    dist[k] = 0;
    pq.push({0, k});

    while (!pq.empty()) {

        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto it : adj[u]) {

            int v = it.first;
            int w = it.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {

        if (dist[i] == INT_MAX)
            return -1;

        ans = max(ans, dist[i]);
    }

    return ans;
}

int main() {

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> times;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        times.push_back({u, v, w});
    }

    cout << networkDelayTime(times, n, k) << endl;

    return 0;
}
