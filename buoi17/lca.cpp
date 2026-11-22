#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"
#define FOR(i, l, r) for (ll i = l; i <= r; i++)
#define FORD(i, l, r) for (ll i = l; i >= r; i--)
#define fre(NAME) freopen(NAME".inp","r",stdin); freopen(NAME".out","w",stdout)
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ldb long double
#pragma GCC optimize("O3")
#define ull unsigned long long
#define time cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
#define fi first
#define se second
#define pb push_back
#define mpr make_pair
#define sz(a) a.size()
#define all(a) a.begin(),a.end()
#define ms(a,n) memset(a,n,sizeof(a))
#define FIX(a,n) fixed << setprecision(n) << a

// Bit
#define MASK(x) (1<<(x))
#define BIT(mask, i) (((mask) >> (i))&1)
#define SET_ON(x,i) ((x) | MASK(i))
#define SET_OFF(x,i) ((x) & ~MASK(i))
#define c_bit(i) __builtin_popcountll(i)

typedef long double ld;
typedef pair<ll,ll> pl;
typedef pair<int,int> pi;
typedef vector<ll> vll;
typedef vector<int> vi;

const int MOD = 1e9+7;
const ld PI = 3.141592653589793238462643383279502884L;

inline ll gcd(ll a, ll b){return b==0 ? a : gcd(b,a%b);}
inline ll lcm(ll a, ll b){return a/gcd(a,b)*b;}

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int N = 5e5 + 5;
const int LOG = __lg(N)+1;

const ll MAXN = 3005;

//ITIS

ll up[N][21];
ll depth[N];
vector<int> adj[N];

void dfs(int u,int par) {
    up[u][0] = par;
    depth[u] = depth[par] + 1;

    for(int v : adj[u]) {
        if(v == par) continue;
        
        dfs(v,u);
    }
}

void binlift(int n) {
    for(int j=1;j<21;++j) {
        for(int u=1;u<=n;++u) {
            up[u][j] = up[up[u][j-1]][j-1];
        }
    }
}

int jump(int u,int k) {
    for(int j=0;j<21;++j) {
        if(k & (1 << j)) {
            u = up[u][j];
        }
    }
    return u;
}

int lca(int u,int v) {
    if(depth[u] < depth[v]) swap(u,v);

    u = jump(u,depth[u] - depth[v]);

    if(u == v) return u;

    for(int j=20;j>=0;--j) {
        if(up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }
    return up[u][0];
}

int t = 1;

int main() {
    boost;
    //cin >> t;
    while (t--)
    {
        int n,q;
        cin >> n >> q;
        
        depth[1] = 0;
        up[1][0] = 0;

        for(int i=2;i<=n;++i) {
            cin >> up[i][0];
            depth[i] = depth[up[i][0]] + 1;
        }

        binlift(n);

        while(q--) {
            int u,v;
            cin >> u >> v;
            cout << lca(u,v) << endl;
        }
    }
    //time;
    return 0;
}

/*
    Hav a nice day xD
    Author Bạch Ngọc Đức - Cross
*/