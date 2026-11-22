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
    ll n,k;
    cin >> n >> k;
    ll x = k-1;
    ll res = 1;
    while(x>0) {
        if(x%2==1) res++;
        x /= 2;
    }cout << res << endl;
    return 0;
}