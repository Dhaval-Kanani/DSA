#include <bits/stdc++.h>
using namespace std;

int
main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];
    vector<int> vis(n + 1);
    vector<int> cities;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans;
    int su = 0, eu = 0;
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++) {
        // if (su != 0 && eu != 0)
        //     break;
        if (vis[i])
            continue;
        queue<pair<int, int>> q;
        q.push({i, -1});
        vis[i] = 1;
        parent[i] = -1;
        while (q.size()) {

            int u = q.front().first;
            int p = q.front().second;
            q.pop();
            // cout << u << " " << p << endl;

            for (auto x : adj[u]) {
                cout << x << ": "<<u<<"-" << p << endl;
                
                if (vis[x] != 1) {
                    parent[x] = u;
                    vis[x] = 1;
                    cout << "push: " << x << " " << u << endl;
                    q.push({x, u});
                } else if (p != x) {
                    su = u;
                    eu = x;
                    cout << su << " " << eu << ": y" << endl;
                    while (su != eu) {
                        ans.push_back(eu);
                        eu = parent[eu];
                    }
                    cout << ans.size() + 2 << endl;
                    for (auto x : ans)
                        cout << x << " ";
                    cout << su << " " << ans[0];
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}