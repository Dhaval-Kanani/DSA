#include <bits/stdc++.h>
using namespace std;

int
main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> g[n + 1];

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    priority_queue<pair<long, long>, vector<pair<long, long>>,
                   greater<pair<long, long>>>
        q;
    q.push({0, 1});
    vector<long> d(n + 1, LLONG_MAX);
    d[1] = 0;

    while (!q.empty()) {
        pair<long, long> p = q.top();
        q.pop();

        long dis = p.first;
        long node = p.second;
        if (dis > d[node])
            continue;
        for (auto x : g[node]) {
            long edgWeight = x.second;
            long adjNode = x.first;
            if (d[adjNode] > dis + edgWeight) {
                d[adjNode] = dis + edgWeight;
                q.push({d[adjNode], adjNode});
            }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << d[i] << " ";
}