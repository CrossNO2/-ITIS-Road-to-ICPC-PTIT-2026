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

ll dp[20][4][7];
string s;

ll solve(int idx, int c4, int c7, bool tight) {
    if (idx == s.length()) {
        return (c4 == 0 && c7 == 0) ? 1 : 0;
    }
    if (tight && dp[idx][c4][c7] != -1) {
        return dp[idx][c4][c7];
    }
    long long res = 0;
    int limit = tight ? 9 : (s[idx] - '0');
    for (int d = 0; d <= limit; d++) {
        int nc4 = (c4 + (d == 4)) % 4;
        int nc7 = (c7 + (d == 7)) % 7;
        res += solve(idx + 1, nc4, nc7, tight || (d < limit));
    }

    if (tight) {
        dp[idx][c4][c7] = res;
    }
    return res;
}

int main() {
    boost;
    int t;
    cin >> t;
    while(t--) {
        memset(dp,-1,sizeof(dp));
        cin >> s;
        cout << solve(0,0,0,false)-1 << endl;
    }
    return 0;
}

/*
    Hav a nice day xD
    Author Bạch Ngọc Đức - Cross
*/