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

const int MAXV = 1000000;
int minprimes[MAXV + 5];

void sieve() {
    for (int i = 2; i <= MAXV; ++i) minprimes[i] = i;
    for (int i = 2; i * i <= MAXV; ++i) {
        if (minprimes[i] == i) {
            for (int j = i * i; j <= MAXV; j += i) {
                if (minprimes[j] == j) minprimes[j] = i;
            }
        }
    }
}

int t = 1;

int main() {
    boost;
    //cin >> t;
    while (t--)
    {
        int n,m;
        cin >> n >> m;
        sieve();
        vector<bool> used(1000001,false);
        for(int i=1;i<=n;++i) {
            int x;
            cin >> x;
            while(x > 1) {
                int p = minprimes[x];
                used[p] = true;
                while(x%p == 0) x /= p;
            }
        }
        vector<bool> visited(m+1,false);
        for(int p=2;p <= 1000000;++p) {
            if(!used[p]) continue;
            for(int j=p;j<=m;j+=p) visited[j] = true;
        }
        vector<int> ans;
        for(int k=1;k<=m;++k) {
            if(!visited[k]) ans.push_back(k);
        }
        cout << ans.size() << endl;
        for(int x : ans) cout << x << " ";
    }
    //time;
    return 0;
}

/*
    Hav a nice day xD
    Author Bạch Ngọc Đức - Cross
*/