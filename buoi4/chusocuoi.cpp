#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define maxn 200000
#define mod 1000000007
#define ull unsigned long long
#pragma GCC optimize("O3")

int main() {
    boost
    int t;
    cin >> t;
    while(t--) {
        ll a,b;
        cin >> a >> b;
        ll m = a%10;
        ll n = b%4;
        if(b==0) {
            cout << 1 << endl;
            continue;
        }if(n==0) n=4;
        ll res = 1;
        for(int i=0;i<n;++i) res*=m;
        ll ans = pow(m,n);
        cout << res%10 << endl;
    }
    return 0;
}