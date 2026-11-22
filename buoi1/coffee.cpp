#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define MAXN 200000

vector<ll> d(MAXN+5);
vector<ll> s(MAXN+5);

int main() {
    boost;
    int n,k,q;
    cin >> n >> k >> q;
    for(int i=0;i<n;i++) {
        ll l,r;
        cin >> l >> r;
        d[l]++;
        d[r+1]--;
    }
    int c=0;
    for(int i=1;i<=MAXN;++i) {
        c+=d[i];
        if(c>=k) s[i] = 1;
        else s[i] = 0;
    }for(int i=1;i<=MAXN;++i) s[i] += s[i-1];
    while(q--) {
        int a,b;
        cin >> a >> b;
        cout << s[b] - s[a-1] << endl;
    }return 0;
}