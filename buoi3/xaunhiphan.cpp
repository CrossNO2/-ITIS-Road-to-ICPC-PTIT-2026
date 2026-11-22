#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define maxn 200000
#define mod 100000007
#define ull unsigned long long
#pragma GCC optimize("O3")

int n;
vector<ll> a(15);

void p(int k) {
    if(k==n) {
        for(int i=0;i<n;++i) cout << a[i];
        cout << " ";
        return;
    }for(int i=0;i<=1;++i) {
        a[k]=i;
        p(k+1);
    }
}

int main() {
    boost
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        p(0);
        cout << endl;
    }
    return 0;
}