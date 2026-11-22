#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

int main() {
    int n;
    cin >> n;
    ll lower,upper;
    vector<ll> d(n);
    for(int i=0;i<n;i++) cin >> d[i];
    cin >> lower >> upper;
    ll s = 0;
    ll l = lower;
    ll r = upper;
    for(int i=0;i<n;i++) {
        s+=d[i];
        l = max(l,lower-s);
        r = min(r,upper-s);
    }ll res = r-l+1;
    if(res < 0) cout << 0 << endl;
    else cout << res << endl;
    return 0;
}