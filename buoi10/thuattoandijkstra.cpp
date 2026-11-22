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

int n,m,u;
vector<pair<int,int>> adj[MAXN];

void nhap() {
    cin >> n >> m;
    for(int i = 1; i < MAXN; i++) adj[i].clear();
    for(int i=1;i<=m;++i) {
        int x,y,w;
        cin >> x >> y >> w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    cin >> u;
}

void dijkstra(int s) {
    vector<ll> d(n+1, INF);
    d[s] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0,s});
    while(!pq.empty()) {
        pair<int,int> top = pq.top();
        pq.pop();
        int u = top.second;
        int dis = top.first;
        if(dis > d[u]) {
            continue;
        }
        for(auto it : adj[u]) {
            int v = it.first;
            int w = it.second;
            if(d[u] + w < d[v]) {
                d[v] = d[u] + w;
                pq.push({d[v],v});
            }
        }
    }
    for(int i=1;i<=n;++i) {
        if(d[i] == INF) cout << -1 << " ";
        else cout << d[i] << " ";
    }
    cout << endl;
}


int main() {
    boost;
    int t;
    cin >> t;
    while(t--) {
        nhap();
        dijkstra(u);
    }
    return 0;
}

/*
    Hav a nice day xD
    Author Bạch Ngọc Đức - Cross
*/