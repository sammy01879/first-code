#include <bits/stdc++.h>
using namespace std;

class DSU {
private:
    vector<int> parent, rankv;

public:
    DSU(int n) {
        parent.resize(n + 1);
        rankv.resize(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA == rootB)
            return false;

        if (rankv[rootA] < rankv[rootB])
            swap(rootA, rootB);

        parent[rootB] = rootA;

        if (rankv[rootA] == rankv[rootB])
            rankv[rootA]++;

        return true;
    }
};

int main() {
    int g_nodes, g_edges;
    cin >> g_nodes >> g_edges;

    vector<tuple<int, int, int>> edges;

    for (int i = 0; i < g_edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        edges.push_back({w, u, v});
    }

    sort(edges.begin(), edges.end());

    DSU dsu(g_nodes);

    int totalWeight = 0;

    for (auto edge : edges) {
        int w = get<0>(edge);
        int u = get<1>(edge);
        int v = get<2>(edge);

        if (dsu.unite(u, v)) {
            totalWeight += w;
        }
    }

    cout << totalWeight << endl;

    return 0;
}
