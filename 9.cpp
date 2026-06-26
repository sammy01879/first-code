
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
using namespace std;

int minimumEffortPath(vector<vector<int>>& heights) {

    int n = heights.size();
    int m = heights[0].size();

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>
    > pq;

    dist[0][0] = 0;
    pq.push({0, {0, 0}});

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    while (!pq.empty()) {

        int effort = pq.top().first;
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        pq.pop();

        if (row == n - 1 && col == m - 1)
            return effort;

        for (int i = 0; i < 4; i++) {

            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {

                int newEffort = max(effort,
                    abs(heights[row][col] - heights[nr][nc]));

                if (newEffort < dist[nr][nc]) {

                    dist[nr][nc] = newEffort;
                    pq.push({newEffort, {nr, nc}});
                }
            }
        }
    }

    return 0;
}

int main() {

    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> heights(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> heights[i][j];
        }
    }

    cout << minimumEffortPath(heights) << endl;

    return 0;
}
