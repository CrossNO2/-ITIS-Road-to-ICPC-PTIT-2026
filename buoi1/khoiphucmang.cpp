#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

int main() {
    boost;
    int n,m,q;
    cin >> n >> m >> q;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<ll> b(n+2,0);
    for(int i=0;i<m;i++) {
        int l,r;
        ll d;
        cin >> l >> r >> d;
        if(l>r) swap(l,r);
        b[l]+=d;
        b[r+1]-=d;
    }ll s = 0;
    for(int i=1;i<=n;i++) {
        s+=b[i];
        a[i]+=s;
    }
    while(q--) {
        int idx;
        cin >> idx;
        if(idx < 1 || idx > n) cout << "INVALID" << endl;
        else cout << a[idx] << endl;
    }return 0;
}