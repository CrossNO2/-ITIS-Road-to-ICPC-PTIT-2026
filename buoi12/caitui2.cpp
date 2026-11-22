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

//dp[i] là trọng lượng nhỏ nhất để đạt tổng giá trị i

void solve() {
    ll n,w;
    cin >> n >> w;
    vector<int> weight(n+1);
    vector<int> value(n+1);
    ll sum = 0;
    for(int i=1;i<=n;++i) {
        cin >> weight[i] >> value[i];
        sum += value[i];
    }
    vector<ll> dp(sum+1,INF);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = sum; j >= value[i]; j--) {
            dp[j] = min(dp[j], dp[j - value[i]] + weight[i]);
        }
    }
    ll ans = 0;
    for (int i = 0; i <= sum; i++) {
        if (dp[i] <= w) ans = i;
    }
    cout << ans << endl;
}

int main() {
    boost;
    solve();
    return 0;
}

/*
    Hav a nice day xD
    Author Bạch Ngọc Đức - Cross
*/