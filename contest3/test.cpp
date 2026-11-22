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

int t = 1;

struct segmentree{
    int n;
    vector<int> tree;

    segmentree(int x = 0) {
        n = x;
        tree.assign(4*n+5,0);
    }

    void build(int idx,int l,int r) {
        if(l==r) {
            tree[idx] = 1;
            return;
        }
        int mid = (l+r)>>1;
        build(idx << 1,l,mid);
        build(idx << 1 | 1,mid+1,r);
        tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
    }

    void update(int idx,int l,int r,int pos) {
        if(l==r) {
            tree[idx] = 0;
            return;
        }

        int mid = (l+r)>>1;
        if(pos <= mid) {
            update(idx << 1, l,mid,pos);
        }
        else {
            update(idx << 1 | 1,mid+1,r,pos);
        }
        tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
    }

    int query(int idx,int l,int r, int ql, int qr) {
        if(qr < l || r < ql) return 0;
        if(ql <= l && qr >= r) return tree[idx];

        int mid = (l+r) >> 1;
        return query(idx << 1,l,mid,ql,qr) + query(idx << 1 | 1,mid+1,r,ql,qr);
    }

    void update(int pos) {
        update(1,1,n,pos);
    }

    int query(int l,int r) {
        if(l>r) return 0;
        return query(1,1,n,l,r);
    }
};

int main() {
    boost;
    //cin >> t;
    while (t--)
    {
        int n,m,k;
        cin >> n >> m >> k;
        vector<int> first_col(n+1,m+1);
        vector<int> first_row(m+1,n+1);

        for(int i=1;i<=k;++i) {
            int x,y;
            cin >> x >> y;
            first_col[x] = min(first_col[x],y);
            first_row[y] = min(first_row[y],x);
        }
        int d = first_row[1] - 1;
        int r = first_col[1] - 1;

        if(d == 0 && r == 0) {
            cout << 1 << endl;
            return 0;
        }

        vector<vector<int>> block(d+5);
        for(int col = 1;col<=r;++col) {
            if(first_row[col] <= d) block [first_row[col]].push_back(col);
        }

        segmentree seg(r);

        if(r > 0) seg.build(1,1,r);

        ll ans = 0;

        for(int col = 1; col <= r; ++col) {
            ans += first_row[col] - 1;
        }

        for(int i=1;i<=d;++i) {
            for(int col : block[i]) {
                seg.update(col);
            }
            int reach = first_col[i] - 1;

            ans += max(0,reach - r);

            int lim = min(reach,r);

            if(lim > 0) {
                ans += lim - seg.query(1,lim);
            }
        }
        cout << ans << endl;
    }
    //time;
    return 0;
}

/*
    Hav a nice day xD
    Author Bạch Ngọc Đức - Cross
*/