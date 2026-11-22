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

//dp[i] là độ dài dãy con tăng tính tới i

void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i) cin >> a[i];
    vector<int> dp(n+1,1);
    for(int i=1;i<=n;++i) {
        for(int j=1;j<i;++j) {
            if(a[i] >= a[j]) dp[i] = max(dp[i],dp[j]+1);
        }
    }
    int k = 0;
    for(int x : dp) k = max(k,x);
    cout << n-k << endl;
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