#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"
#define FOR(i, l, r) for (ll i = l; i <= r; i++)
#define FORD(i, l, r) for (ll i = l; i >= r; i--)
#define fre(NAME) freopen(NAME".inp","r",stdin); freopen(NAME".out","w",stdout)
#define ALL(a) a.begin(), a.end()
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pii pair<ll,ll>
#define ldb long double
#pragma GCC optimize("O3")
#define ull unsigned long long
const ll MAXN = 3005;
const ll INF = 4e18;
const ll MOD = 1e9+7;

//ITIS

struct Edge{
    ll u,v,w;
};

int n,m;
vector<Edge> edge;

bool bellman_ford(int n, vector<Edge> &edges) {
    vector<ll> dist(n + 1, 0);
    for (int i = 1; i <= n - 1; i++) {
        bool ok = false;
        for (auto e : edges) {
            if (dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                ok = true;
            }
        }
        if (!ok) break;
    }
    for (auto e : edges) {
        if (dist[e.u] + e.w < dist[e.v])
            return true;
    }
    return false;
}

int main() {
    boost;
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        edge.resize(m+1);
        for(int i=1;i<=m;++i) cin >> edge[i].u >> edge[i].v >> edge[i].w;
        if(bellman_ford(n,edge)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}

/*
    Hav a nice day xD
    Author Bạch Ngọc Đức - Cross
*/