
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    pair<int, int> getPosition(int num, int n) {
        int row = (num - 1) / n;
        int col = (num - 1) % n;

        if (row % 2 == 1)
            col = n - 1 - col;

        return {n - 1 - row, col};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        queue<pair<int, int>> q;
        vector<bool> visited(n * n + 1, false);

        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            int curr = q.front().first;
            int moves = q.front().second;
            q.pop();

            if (curr == n * n)
                return moves;

            for (int dice = 1; dice <= 6; dice++) {
                int next = curr + dice;

                if (next > n * n)
                    break;

                auto pos = getPosition(next, n);
                int r = pos.first;
                int c = pos.second;

                if (board[r][c] != -1)
                    next = board[r][c];

                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, moves + 1});
                }
            }
        }

        return -1;
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    Solution obj;
    cout << obj.snakesAndLadders(board) << endl;

    return 0;
}
