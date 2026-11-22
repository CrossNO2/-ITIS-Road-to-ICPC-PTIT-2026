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

int main() {
    boost;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<ll> dp(n+5,0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for(int i=4;i<=n;++i) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        cout << dp[n] << endl;
    }
    return 0;
}

/*
    Hav a nice day xD
    Author Bạch Ngọc Đức - Cross
*/