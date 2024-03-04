#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using omset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename U>
using omap = tree<T, U, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// SHORTFORMS
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define F first
#define S second
#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vb vector<bool>
#define vi vector<int>
#define vl vector<long long>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<long long, long long>>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define si set<int>
#define usi unordered_set<int>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define nn '\n'
#define yes return void(cout << "YES\n")
#define no return void(cout << "NO\n")
#define crt(x) return void(cout << x << '\n')
#define all(x) x.begin(), x.end()
#define sz(x) int(x.size())
#define acc(x) accumulate(x.begin(), x.end(), 0LL)
#define ff(i, l, r) for (int i = l; i <= r; i++)
#define rf(i, r, l) for (int i = r; i >= l; i--)
#define read(x)        \
    for (auto &xi : x) \
        cin >> xi;
#define readn(x, n)             \
    for (int i = 0; i < n; i++) \
        cin >> x[i];
#define print(x)           \
    for (auto xi : x)      \
        cout << xi << ' '; \
    cout << '\n';
//
template <typename T>
class segment_tree
{
private:
    struct node
    {
        ll sm;    // leaf node values
    } dummy_node; // init dummy_node acc to the problem
    int n;
    const long long nil = 0x3f3f3f3f3f3f3f3f;
    vector<node> st;
    vector<T> lz;
    void apply(int v, int l, int r)
    {
        // recalculate values of node using lazy update
        if (lz[v] != nil)
            st[v].sm = (r - l + 1) * (lz[v]);
        if (v + 1 < 2 * n)
            propogate(v);
        else
            lz[v] = nil;
    }
    void apply(int v, int l, int r, T new_upd)
    {
        // recalculate values of node using lazy values and new_upd
        st[v].sm = (r - l + 1) * (new_upd);
        if (v + 1 < 2 * n)
            propogate(v);
        else
            lz[v] = nil;
    }
    node merge(node n1, node n2) { return node{n1.sm + n2.sm}; }
    void propogate(int v)
    {
        if (lz[v] != nil)
        {
            lz[2 * v + 1] += lz[v];
            lz[2 * v + 2] += lz[v];
            lz[v] = nil;
        }
    }
    void build(int v, int tl, int tr, vector<T> &a)
    {
        if (tl == tr)
        {
            // init leaf node
            st[v] = node{a[tl]};
            return;
        }
        int mid = (tl + tr) >> 1;
        build(2 * v + 1, tl, mid, a);
        build(2 * v + 2, mid + 1, tr, a);
        st[v] = merge(st[2 * v + 1], st[2 * v + 2]);
    }

public:
    segment_tree(vector<T> &a) : n(a.size())
    {
        st.resize(4 * n);
        lz.assign(4 * n, nil);
        build(0, 0, n - 1, a);
        dummy_node.sm = 0;
    }
    void update(int v, int tl, int tr, int l, int r, T upd)
    {
        if (l <= tl && tr <= r)
        {
            apply(v, tl, tr, upd);
            return;
        }
        if (tr < l || r < tl)
            return;
        int mid = (tl + tr) >> 1;
        propogate(v);
        update(2 * v + 1, tl, mid, l, r, upd);
        update(2 * v + 2, mid + 1, tr, l, r, upd);
        st[v] = merge(st[2 * v + 1], st[2 * v + 2]);
    }
    node query(int v, int tl, int tr, int l, int r)
    {
        if (l <= tl && tr <= r)
        {
            apply(v, tl, tr);
            return st[v];
        }
        if (tr < l || r < tl)
            return dummy_node;
        int mid = (tl + tr) >> 1;
        propogate(v);
        return merge(query(2 * v + 1, tl, mid, l, r), query(2 * v + 2, mid + 1, tr, l, r));
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vl a(n);
    read(a);
    segment_tree<ll> sgt(a);
    int tt, l, r, x;
    while (m--)
    {
        cin >> tt;
        if (tt == 1)
        {
            cin >> l >> x;
            sgt.update(0, 0, n - 1, l - 1, l - 1, x);
        }
        else
        {
            cin >> l >> r;
            cout << sgt.query(0, 0, n - 1, l - 1, r - 1).sm << nn;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}