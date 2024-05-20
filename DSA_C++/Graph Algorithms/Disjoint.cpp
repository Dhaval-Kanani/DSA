#include <bits/stdc++.h>
using namespace std;

class Disjoint {
    vector<int> rank, parent;

  public:
    Disjoint(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findPar(int n) {
        if (n == parent[n])
            return n;
        return parent[n] = findPar(parent[n]);
    }

    void unionByRank(int u, int v) {
        int ultp_u = findPar(u);
        int ultp_v = findPar(v);

        if (ultp_u == ultp_v)
            return;
        if (rank[ultp_u] < rank[ultp_v]) {
            parent[ultp_u] = ultp_v;
        } else if (rank[ultp_u] < rank[ultp_v]) {
            parent[ultp_v] = ultp_u;
        } else {
            parent[ultp_v] = ultp_u;
            rank[ultp_u]++;
        }
    }
};

int
main() {
    int n, m;
    cin >> n >> m;
    vector<int> group(n + 1);
    Disjoint ds(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        ds.unionByRank(u, v);
    }

    return 0;
}