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

    void solve() {
        int n;
        cin >> n;
        vector<int> dp(n+2);
        vector<int> a(n+2);
        for(int i=1;i<=n;++i) cin >> a[i];
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = abs(a[2] - a[1]);
        for(int i=3;i<=n;++i) {
            dp[i] = min(dp[i-1] + abs(a[i-1] - a[i]), dp[i-2] + abs(a[i-2] - a[i]));
        }
        cout << dp[n] << endl;
    }

    int main() {
        boost;
        int t;
        cin >> t;
        while(t--) {
            solve();
        }
        return 0;
    }

    /*
        Hav a nice day xD
        Author Bạch Ngọc Đức - Cross
    */