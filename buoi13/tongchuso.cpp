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

ll dp[20][200];
string s;

ll solve(int i, int sum, bool tight) {
    if (i == s.length()) {
        return sum;
    }
    if (!tight && dp[i][sum] != -1) {
        return dp[i][sum];
    }
    ll r = 0;
    int limit = tight ? (s[i] - '0') : 9;
    for (int d = 0; d <= limit; d++) {
        r += solve(i + 1, sum + d, tight && (d == limit));
    }
    if (!tight) {
        dp[i][sum] = r;
    }
    return r;
}

ll convert(ll n) {
    s = to_string(n);
    memset(dp,-1,sizeof(dp));
    return solve(0,0,true);
}

int main() {
    boost;
    int t;
    cin >> t;
    while(t--) {
        ll l,r;
        cin >> l >> r;
        cout << convert(r) - convert(l-1) << endl;
    }
    return 0;
}

/*
    Hav a nice day xD
    Author Bạch Ngọc Đức - Cross
*/