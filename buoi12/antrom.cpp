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

/* dp[i] là tổng đồ đã trộm tính đến nhà i 
   in ra số giá trị lớn nhất sau khi lấy hết n ngôi nhà
   đến nhà i thì có 2 lựa chọn là lấy và ko lấy 
*/

int main() {
    boost;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n+1);
        vector<int> dp(n+5);
        for(int i=1;i<=n;++i) cin >> a[i];
        dp[0] = 0;
        dp[1] = a[1];
        for(int i=2;i<=n;++i) dp[i] = max(dp[i-1], dp[i-2] + a[i]);
        cout << dp[n] << endl;
    }
    return 0;
}

/*
    Hav a nice day xD
    Author Bạch Ngọc Đức - Cross
*/