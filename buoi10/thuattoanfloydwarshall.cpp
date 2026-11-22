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

int n,m;
vector<vector<ll>> dp(n+1,vector<ll>(m+1));

void pre() {
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j) {
            if(i==j) dp[i][j] = 0;
            else dp[i][j] = INF;
        }
    }
}

void nhap() {
    cin >> n >> m;
    dp.assign(n+1,vector<ll>(n+1,INF));
    pre();

    for(int i=1;i<=m;++i) {
        int x,y,w;
        cin >> x >> y >> w;
        dp[x][y] = min(dp[x][y], 1LL*w);
        dp[y][x] = min(dp[y][x], 1LL*w);
    }
}

void floyd_warshall() {
    for(int k=1;k<=n;++k) {
        for(int j=1;j<=n;++j) {
            for(int i=1;i<=n;++i) {
                if(dp[i][k] != INF && dp[k][j] != INF) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
}

int main() {
    boost;
    nhap();
    floyd_warshall();
    int t;
    cin >> t;
    while(t--) {
        int x,y;
        cin >> x >> y;
        if(dp[x][y] == INF) cout << -1 << endl;
        else cout << dp[x][y] << endl;
    }
    return 0;
}

/*
    Hav a nice day xD
    Author Bạch Ngọc Đức - Cross
*/