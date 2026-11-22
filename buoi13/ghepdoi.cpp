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

/* dp[mask] là tổng độ hạnh phúc tối đa khi xét đến
nam thứ i với i = __builtin_popcount(mask) 
với các nữ là các bit 1 trong mask

in ra kq là dp[(1<<n)-1] 

new_mask = mask tắt bit thứ j
dp[mask] = max(aij + dp[new_mask])
dp[0] = 0;
*/

const ll NEG_INF = -4e18;

int main() {
    boost;
    int t;
    cin >> t;
    for(int k=1;k<=t;++k) {
        int n;
        cin >> n;
        vector<vector<ll>> a(n,vector<ll>(n));
        for(int i=0;i<n;++i) {
            for(int j=0;j<n;++j) {
                cin >> a[i][j];
            }
        }
        int m = (1LL << n);
        vector<ll> dp(m,NEG_INF);
        dp[0] = 0;
        for(int mask=0;mask<m;++mask) {
            int i = __builtin_popcount(mask);
            for(int j=0;j<n;++j) {
                if((mask & (1<<j)) == 0) {
                    int newMask = mask | (1 << j);
                    dp[newMask] = max(dp[newMask],dp[mask] + a[i][j]);
                }
            }
        }
        cout << "Case " << k << ": " << dp[m-1] << endl; 
    }
    return 0;
}

/*
    Hav a nice day xD
    Author Bạch Ngọc Đức - Cross
*/