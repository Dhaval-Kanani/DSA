#include <bits/stdc++.h>
using namespace std;

void
dfs(vector<int> adj[], vector<int> &vis, int u) {
    vis[u] = 1;

    for (auto x : adj[u]) {
        if (vis[x] != 1) {
            dfs(adj, vis, x);
        }
    }
}

int
main() {


    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n + 1);
    vector<int> roads;
    for (int i = 1; i <= n; i++) {
        if (vis[i] != 1) {
            dfs(adj, vis, i);
            ans++;
            roads.push_back(i);
        }
    }

    if (ans - 1) {
        cout << ans - 1 << endl;
        for (int i = 0; i < (int) roads.size() - 1; i++) {
            cout << roads[i] << " " << roads[i + 1] << endl;
        }
    } else
        cout << 0 << endl;

    return 0;
}