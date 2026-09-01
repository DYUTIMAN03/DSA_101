class Solution {
public:
    int minMoves(vector<string>& a, int energy) {
        int m = a.size(), n = a[0].size();
        int sr, sc, cnt = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 'S')
                    sr = i, sc = j;

                if (a[i][j] == 'L')
                    id[i][j] = cnt++;
            }
        }

        int full = (1 << cnt) - 1;

        // visited[r][c][energy][mask]
        vector<vector<vector<vector<bool>>>> vis(
            m, vector<vector<vector<bool>>>(
                n, vector<vector<bool>>(
                    energy + 1, vector<bool>(1 << cnt)
                )
            )
        );

        queue<array<int, 5>> q;

        q.push({sr, sc, energy, 0, 0});
        vis[sr][sc][energy][0] = true;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [r, c, e, mask, moves] = q.front();
            q.pop();

            if (mask == full)
                return moves;

            if (e == 0)
                continue;

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= m ||
                    nc < 0 || nc >= n ||
                    a[nr][nc] == 'X')
                    continue;

                int ne = e - 1;
                int nm = mask;

                if (a[nr][nc] == 'R')
                    ne = energy;

                if (a[nr][nc] == 'L')
                    nm |= (1 << id[nr][nc]);

                if (!vis[nr][nc][ne][nm]) {
                    vis[nr][nc][ne][nm] = true;
                    q.push({nr, nc, ne, nm, moves + 1});
                }
            }
        }

        return -1;
    }
};