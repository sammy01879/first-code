
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int start;
    cin >> start;

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    vector<bool> visited(n + 1, false);

    pq.push({0, start});

    int mstWeight = 0;

    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();

        int weight = current.first;
        int node = current.second;

        if (visited[node])
            continue;

        visited[node] = true;
        mstWeight += weight;

        for (auto neighbor : adj[node]) {
            int nextNode = neighbor.first;
            int nextWeight = neighbor.second;

            if (!visited[nextNode]) {
                pq.push({nextWeight, nextNode});
            }
        }
    }

    cout << mstWeight << endl;

    return 0;
}
