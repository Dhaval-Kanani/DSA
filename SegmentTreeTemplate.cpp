#include <bits/stdc++.h>
using namespace std;
template <typename T>
class segment_tree
{
private:
    struct node
    {
        // leaf node
    } dummy_node; // init dummy_node acc to the problem
    int n;
    const long long nil = 0x3f3f3f3f3f3f3f3f;
    vector<node> st;
    vector<T> lz;
    segment_tree(vector<T> &a) : n(a.size())
    {
        st.resize(4 * n);
        lz.assign(4 * n, nil);
        build(0, 0, n - 1, a);
    }
    void apply(int v, int tl, int tr)
    {
        // recalculate values of node using lazy update

        if (v + 1 < 2 * n)
            propogate(v);
        else
            lz[v] = nil;
    }
    void apply(int v, int tl, int tr, T new_upd)
    {
        // recalculate values of node using lazy values and new_upd
        
        if (v + 1 < 2 * n)
            propogate(v);
        else
            lz[v] = nil;
    }
    node merge(node &n1, node &n2)
    {
        node n;
        // merge operation
        return n;
    }
    void propogate(int v)
    {
        if (lz[v] != nil)
        {
            // propogate lazy to children

            // set lazy of current node to null
            lz[v] = nil;
        }
    }

    void build(int v, int tl, int tr, vector<T> &a)
    {
        if (tl == tr)
        {
            // init leaf node
            return;
        }
        int mid = (tl + tr) >> 1;
        build(2 * v + 1, tl, mid, a);
        build(2 * v + 2, mid + 1, tr, a);
        st[v] = merge(st[2 * v + 1], st[2 * v + 2]);
    }

public:
    void update(int v, int tl, int tr, int l, int r, T upd)
    {
        if (l <= tl && tr <= r)
        {
            apply(v, upd);
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
            apply(v);
            return st[v];
        }
        if (tr < l || r < tl)
            return dummy_node;
        int mid = (tl + tr) >> 1;
        propogate(v);
        return merge(query(2 * v + 1, tl, mid, l, r), query(2 * v + 2, mid + 1, tr, l, r));
    }
};
int main()
{
}