#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define maxn 200000
#define mod 100000007
#define ull unsigned long long
#pragma GCC optimize("O3")

ll res = 0;

ll backtrack(ll a, ll b, ll m) {
    if(b==0) return 0;
    res = backtrack(a,b/2,m);
    if(b%2==1) return ((res+res)%m + a)%m;
    else return ((res+res)%m); 
}

int main() {
    boost
    int t;
    cin >> t;
    while(t--) {
        ll a,b,m;
        cin >> a >> b >> m;
        cout << backtrack(a,b,m) << endl;
    }
    return 0;
}