#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define maxn 200000
#define mod 1000000007
#define ull unsigned long long
#pragma GCC optimize("O3")

vector<ll> f(100);

void fibo() {
    f[1] = 1;
    f[2] = 1;
    for(ll i=3;i<93;++i) {
        f[i] = f[i-1] + f[i-2];
    }
}

char s(ll n, ll k) {
    if(n==1) return 'A';
    if(n==2) return 'B';
    if(k <= f[n-2]) return s(n-2,k);
    return s(n-1,k - f[n-2]);
}

int main() {
    boost
    fibo();
    int t;
    cin >> t;
    while(t--) {
        ll n,k;
        cin >> n >> k;
        cout << s(n,k) << endl;
    }
    return 0;
}