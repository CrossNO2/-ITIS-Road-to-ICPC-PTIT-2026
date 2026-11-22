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

struct seggmenttree{
    vector<ll> tree;
    int n;

    seggmenttree(int s) {
        n = s;
        tree.assign(4*n + 5,0);
    }

    void build(int idx,int l,int r,vector<ll> &a) {
        if(l == r) {
            tree[idx] = a[l];
            return;
        }

        int mid = (l+r) >> 1;

        build(idx << 1,l,mid,a);
        build((idx << 1) + 1,mid+1,r,a);

        tree[idx] = min(tree[idx << 1], tree[(idx << 1) + 1]); 
    }

    ll query(int idx,int l,int r,int u,int v) {
        if(u > r || l > v) return INF;
        if(u <= l && r <= v) {
            return tree[idx];
        }

        int mid = (l+r) >> 1;

        return min(query(idx << 1,l,mid,u,v),query((idx << 1) + 1,mid+1,r,u,v));
    }
};

int t = 1;

int main() {
    boost;
    //cin >> t;
    while (t--)
    {
        int n,q;
        cin >> n >> q;
        seggmenttree tree(n);
        vector<ll> a(n + 5);
        for(int i=1;i<=n;++i) cin >> a[i];
        tree.build(1,1,n,a);
        while(q--) {
            int l,r;
            cin >> l >> r;
            cout << tree.query(1,1,n,l,r) << endl;
        }
    }
    //time;
    return 0;
}

/*
    Hav a nice day xD
    Author Bạch Ngọc Đức - Cross
*/