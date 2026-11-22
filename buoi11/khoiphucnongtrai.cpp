#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
// mp.reserve(1<<len); mp.max_load_factor(0.7);

const int N = 1e6;
const int MOD = 1e9 + 7;

struct DSU
{
    vector<int> par, sz;
    vector <ll> d;

    DSU(int n)
    {
        par.resize(n + 1);
        d.assign(n + 1, 0);
        sz.assign(n + 1, 1);
        for (int i = 0; i <= n; ++i)
        {
            par[i] = i;
        }
    }
    int find(int v)
    {
        if (par[v] == v)
            return v;
        int p = par[v];
        par[v] = find(p);
        d[v] += d[p];
        return par[v];
    }

    bool unite(int u, int v, int w)
    {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv)
            return 0;
        if (sz[pu] < sz[pv])
        {
            swap(u, v);
            swap(pu, pv);
            w = -w;
        }
        sz[pu] += sz[pv];
        par[pv] = pu;
        d[pv] = d[u] - d[v] + w;
        return 1;
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    DSU dsu(n);
    while (q--)
    {
        char c;
        int u, v;
        cin >> c >> u >> v;
        if (c == '!')
        {
            int w;
            cin >> w;
            dsu.unite(u, v, w);
        }
        else
        {
            if (dsu.find(u) != dsu.find(v))
            {
                cout << "?!?\n";
            }
            else
            {
                cout << dsu.d[v] - dsu.d[u] << endl;
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef CPH
//    freopen("input", "r", stdin);
//    freopen("output", "w", stdout);
#endif
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
}