#include <bits/stdc++.h>
using namespace std;

int
main() {
    int n, m, query;
    cin >> n >> m >> query;
    vector<vector<long>> g(n + 1, vector<long>(n + 1, LLONG_MAX));
    vector<pair<int, int>> queries;

    for (int i = 1; i <= m; i++) {
        long u, v, w;
        cin >> u >> v >> w;
        g[u][v] = min(g[u][v], w);
        g[v][u] = min(g[v][u], w);
    }

    for (int i = 0; i < query; i++) {
        int a, b;
        cin >> a >> b;
        queries.push_back({a, b});
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                if (i == j) {
                    g[i][j] = 0;
                    continue;
                }
                if (g[i][k] != LLONG_MAX && g[k][j] != LLONG_MAX)
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }

    for (int i = 0; i < query; i++) {
        pair<int, int> p = queries[i];
        int s = p.first;
        int e = p.second;

        if (g[s][e] == LLONG_MAX)
            cout << -1 << endl;
        else
            cout << g[s][e] << endl;
    }
}