#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define MAXN 200000

ll tong(ll a,ll b) {
    if(b==a) return b;
    else return tong(a,b-1)+b;
}

int main() {
    boost;
    int t;
    cin >> t;
    while(t--) {
        int a,b;
        cin >> a >> b;
        cout << tong(a,b) << endl;
    }return 0;
}