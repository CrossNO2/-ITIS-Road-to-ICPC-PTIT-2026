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

int dp[1005][1005];
int weight[1005];
int value[1005];

int main() {
    boost;
    int t;
    cin >> t;
    while(t--) {
        ll n,b;
        cin >> n >> b;
        for(int i=1;i<=n;++i) {
            cin >> weight[i] >> value[i];
        }
        for(int i=1;i<=n;++i) {
            for(int j=0;j<=b;++j) {
                if(j >= weight[i]) {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        cout << dp[n][b] << endl;
    }
    return 0;
}

/*
    Hav a nice day xD
    Author Bạch Ngọc Đức - Cross
*/