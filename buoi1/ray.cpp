#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

int main() {
    boost;
    int n,m,k;
    cin >> n >> m >> k;
    vector<ll> a(n+1,0);
    for(int i=1;i<=n;++i) cin >> a[i];
    vector<ll> l(m+1), r(m+1), d(m+1);
    for(int i=1;i<=m;++i) cin >> l[i] >> r[i] >> d[i];
    vector<ll> o(m+2,0);
    for(int i=0;i<k;++i) {
        int x,y;
        cin >> x >> y;
        o[x]++;
        o[y+1]--;
    }
    vector<ll> c(m+1,0);
    ll sum = 0;
    for(int i=1;i<=m;i++) {
        sum+=o[i];
        c[i] = sum;
    }vector<ll> f(n+2,0);
    for (int i = 1; i <= m; ++i) {
        ll v = c[i] * d[i];
        f[l[i]] += v;
        f[r[i] + 1] -= v;
    }ll g = 0;
    for (int i = 1; i <= n; ++i) {
        g += f[i];
        cout << a[i] + g << (i == n ? "" : " ");
    }
    return 0;
}