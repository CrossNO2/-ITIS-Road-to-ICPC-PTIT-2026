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

//dp[i] là số cách bước tới i

void solve() {
    int n,k;
    cin >> n >> k;
    vector<ll> dp(n+1);
    dp[0] = 1;
    ll sum = dp[0];
    for(int i = 1;i<=n;++i) {
        dp[i] = sum;
        sum = (sum + dp[i])%MOD;
        if(i - k>=0) {
            sum = (sum - dp[i-k]+MOD)%MOD;
        }
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