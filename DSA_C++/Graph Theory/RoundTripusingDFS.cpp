#include <bits/stdc++.h>
using namespace std;

bool
dfs(vector<int> adj[], vector<int> &vis, int u, vector<int> &cities, int parent,
    int &su, int &ev) {
    vis[u] = 1;

    for (auto x : adj[u]) {
        if (x == parent)
            continue;
        if (vis[x] != 1) {
            cities.push_back(x);
            if (dfs(adj, vis, x, cities, u, su, ev))
                return true;
            cities.pop_back();
        } else if (cities.size() >= 3) {
            su = x;
            ev = u;
            return true;
        }
    }

    return false;
}

int
main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];
    vector<int> vis(n + 1);
    vector<int> cities;
    int parent = -1;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int su = 0, ev = 0;
    for (int i = 1; i <= n; i++) {
        cities.push_back(i);
        if (vis[i] == 0)
            if (dfs(adj, vis, i, cities, parent, su, ev))
                break;
        cities.pop_back();
    }
    if (cities.size() < 3) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    vector<int> ans;
    int i = cities.size() - 1;
    while (ev != su) {
        ans.push_back(ev);
        i--;
        ev = cities[i];
    }
    ans.push_back(su);
    ans.push_back(ans[0]);
    cout << ans.size() << endl;
    for (auto x : ans)
        cout << x << " ";
    return 0;
}