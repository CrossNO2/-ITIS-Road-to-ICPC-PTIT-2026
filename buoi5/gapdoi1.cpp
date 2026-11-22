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
        ll n,k;
        cin >> n >> k;
        ll res = 1;
        while(k%2==0) {
            k /= 2;
            res++;
        }cout << res << endl;
    }
    return 0;
}