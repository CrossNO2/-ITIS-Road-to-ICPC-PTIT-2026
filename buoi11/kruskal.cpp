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

struct edge{
    int u,v;
    int w;
};

int n,m;
int parent[1000];
int sz[1000];
vector<edge> canh;

void make_set() {
    for(int i=1;i<=n;++i) {
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int v) {
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}

bool Union(int a,int b) {
    a = find(a);
    b = find(b);

    if(a == b) return false;
    if(sz[a] < sz[b]) swap(a,b);
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}

void input() {
    cin >> n >> m;
    for(int i=0;i<m;++i) {
        int x,y,w;
        cin >> x >> y >> w;
        edge e;
        e.u = x;
        e.v = y;
        e.w = w;
        canh.push_back(e);
    }
}

bool cmp(edge a, edge b) {
    return a.w < b.w;
}

void kruskal() {
    vector<edge> mst;
    int d = 0;
    
}

int main() {
    boost;
    
    return 0;
}

/*
    Hav a nice day xD
    Author Bạch Ngọc Đức - Cross
*/