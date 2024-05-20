#include <bits/stdc++.h>
using namespace std;

void
dfs(vector<int> adj[], vector<int> &vis, int u, vector<int> &color, int c) {
    vis[u] = 1;
    color[u] = c;
    if (c == 1)
        c = 2;
    else
        c = 1;

    for (auto x : adj[u]) {
        if (vis[x] != 1) {
            dfs(adj, vis, x, color, c);
        } else if (color[u] == color[x]) {
            color[0] = 3;
            return;
        }
    }
}

int
main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];
    vector<int> vis(n + 1);
    vector<int> color(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            dfs(adj, vis, i, color, 1);
        }
        if (color[0] == 3)
            break;
    }
    if (color[0] == 3) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    for (int i = 1; i <= n; i++) {

        cout << color[i] << " ";
    }

    return 0;
}