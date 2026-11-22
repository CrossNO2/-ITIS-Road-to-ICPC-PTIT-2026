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

/*  
dp[mask][u] là chi phí min khi đã đi qua các đỉnh trong mask và đang đứng ở u
kq in ra là min dp[(1LL << n)-1][u]
cthuc truy hồi new_mask = bật bit j của mask lên
dp[new_mask][j] = min của nó hoặc dp[mask][j] + aij
*/

int main() {
    boost;
    int n;
    cin >> n;
    vector<vector<ll>> cost(n,vector<ll>(n));
    for(int i=0;i<n;++i) {
        for(int j=0;j<n;++j) {
            cin >> cost[i][j];
        }
    }
    vector<vector<ll>> dp(1LL << n, vector<ll>(1LL << n,INF));
    for(int i=0;i<n;++i) dp[1LL << i][i] = 0;
    for(int mask = 1;mask < (1LL << n);++mask) {
        for(int u=0;u<n;++u) {
            if(mask & (1LL << u)) {
                for(int v=0;v<n;++v) {
                    if(!(mask & (1LL << v))) {
                        int new_mask = mask | (1LL << v);
                        dp[new_mask][v] = min(dp[new_mask][v],dp[mask][u] + cost[u][v]);
                    }
                }
            }
        }
    }
    ll MIN = INF;
    for(int i=0;i<n;++i) {
        MIN = min(MIN,dp[(1LL << n) -1][i]);
    }
    cout << MIN << endl;
    return 0;
}

/*
    Hav a nice day xD
    Author Bạch Ngọc Đức - Cross
*/